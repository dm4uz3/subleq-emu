#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <graphics.h>
#include <klib.h>
#include <system.h>

extern uint64_t _readram(uint64_t);
extern void _writeram(uint64_t, uint64_t);

void _strcpyram(uint64_t dest, const char *mem) {
    for (size_t i = 0; mem[i]; i++)
        _writeram(dest++, (uint64_t)mem[i] << 56);
    _writeram(dest, 0);
}

void init_subleq(void) {

    /* CPU id */
    _strcpyram(335413288, "subleq-emu x86");

    /* */
    _writeram(334364664, (uint64_t)1);

    /* display */
    _writeram(335540096, (uint64_t)edid_width);
    _writeram(335540096 + 8, (uint64_t)edid_height);
    _writeram(335540096 + 16, (uint64_t)32);
    _writeram(335540096 + 24, (uint64_t)2);

}
