/**
 * @file  upy_gc.h
 * @brief Minimum definitions for Micropython's gabage collector
 */

#ifndef UPY_GC_H_INCLUDED
#define UPY_GC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "py/mpstate.h"
#include "py/mpconfig.h"  // For MP_STATE_PORT(x)

extern void *gc_alloc(size_t n_bytes, unsigned int alloc_flags);
extern void gc_free(void *ptr);  // does not call finaliser
extern size_t gc_nbytes(const void *ptr);
extern void *gc_realloc(void *ptr, size_t n_bytes, bool allow_move);

#define upy_gc_alloc(b) gc_alloc((b), false)
#define upy_gc_free(ptr) gc_free(ptr)
#define upy_gc_realloc(ptr, n) gc_realloc(ptr, n, true)
#define upy_gc_nbytes(ptr) gc_nbytes(ptr)

#endif  // UPY_GC_H_INCLUDED
