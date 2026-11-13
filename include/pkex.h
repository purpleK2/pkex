#ifndef PKEX_H
#define PKEX_H

#include <stdint.h>

/* Current version identifier */
#define PKEX_VER    0x100   // 00000001 00000000

#define PKEX_MAGIC  "PEXT"

#define PKEX_VMIN(v)    ((v) & 0xff)
#define PKEX_VMAJ(v)    (((v) >> 8) & 0xff)

/* zero value and NUL character */
#define PKEX_NULL   0

struct pkex_header {
    char magic[4];
    uint16_t version;
    uint8_t type;
    uint8_t name_offs;
    uint16_t mversion;  /* Module version */

    uint16_t stroffs;   /* String table offset */
    uint16_t foffs;     /* Features table offset */
    uint16_t doffs;     /* Dependencies table offset */
    uint16_t e_offs;    /* ELF file offset */
};

#endif
