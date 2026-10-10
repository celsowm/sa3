"""Host-compile the real MultiBoot completion task constructor C body.

Tests that the 0x400 flag alone is cleared and a zero-data-size task is
created at priority 0x2000 using the original callback. Does not establish
agbcc/whole-ROM matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
DECL = "void sub_802613C(void)"
HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
typedef uint16_t u16;
typedef uint32_t u32;
typedef void (*TaskMain)(void);
typedef struct Task { unsigned char pad; } Task;
u32 gFlags;
static unsigned taskCalls, gotSize, gotPriority, gotFlags;
static TaskMain gotMain;
static void (*gotDestructor)(Task *);
void Task_8026178(void) {}
Task *TaskCreate(TaskMain main, u16 size, u16 priority, u16 flags,
                 void (*destructor)(Task *)) {
    static Task task;
    taskCalls++;
    gotMain = main;
    gotSize = size;
    gotPriority = priority;
    gotFlags = flags;
    gotDestructor = destructor;
    return &task;
}
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; \
} } while (0)
"""
DRIVER = r"""
int main(void) {
    u32 values[] = {
      0, 0x400, 0xFFFFFFFF, 0xFFFFFBFF,
      0x7FFFFFFF, 0x80000000, 0xAAAAAAAA, 0x55555555,
    };
    unsigned index, mask;
    for (index = 0; index < sizeof values/sizeof values[0]; ++index) {
      for (mask = 0; mask < 2048; ++mask) {
        u32 before = values[index] ^ mask;
        gFlags = before;
        taskCalls = 0;
        gotSize = gotPriority = gotFlags = 0xFFFF;
        gotMain = 0;
        gotDestructor = (void (*)(Task *))Task_8026178;
        sub_802613C();
        CHECK(gFlags == (before & ~0x400u));
        CHECK(taskCalls == 1);
        CHECK(gotMain == Task_8026178);
        CHECK(gotSize == 0 && gotPriority == 0x2000 && gotFlags == 0);
        CHECK(gotDestructor == NULL);
      }
    }
    return 0;
}
"""


class MultiBootTaskStartTests(unittest.TestCase):
    def test_c_fallback_task_creation(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("Native C compiler not installed")
        source = SOURCE.read_text(encoding="utf-8")
        key = f'NONMATCH("asm/non_matching/sio/sio__sub_802613C.inc", {DECL})'
        match = re.search(re.escape(key) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                          source, re.S)
        self.assertIsNotNone(match)
        implementation = DECL + "\n" + match.group(1)
        with tempfile.TemporaryDirectory(prefix="sa3-multiboot-task-") as tmp:
            c = Path(tmp) / "boot_task.c"
            binary = Path(tmp) / "boot_task"
            c.write_text(HEADER + "\n" + implementation + "\n" + DRIVER,
                         encoding="utf-8")
            built = subprocess.run([
                compiler, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra",
                "-Werror", "-fsanitize=undefined", str(c), "-o", str(binary)
            ], text=True, capture_output=True)
            self.assertEqual(built.returncode, 0, built.stderr)
            executed = subprocess.run([str(binary)], text=True, capture_output=True)
            self.assertEqual(executed.returncode, 0, executed.stderr)


if __name__ == "__main__":
    unittest.main()
