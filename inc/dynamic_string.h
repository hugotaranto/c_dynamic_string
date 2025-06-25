#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this library implements a dynamic string.
#define DYNAMIC_STRING_INIT 128

typedef struct {
  char *data;
  size_t length;
  size_t size;
} DynamicString;

DynamicString* dstring_initialise();
DynamicString* dstring_initialise_size(size_t size);
void dstring_free(DynamicString *dstring);

void dstring_clear(DynamicString *dstring);

int dstring_resize(DynamicString *dstring, size_t new_size);

int dstring_readline(DynamicString *dstring, FILE *stream);

int dstring_append(DynamicString *dstring, char ch);

int dstring_combine(DynamicString *dest, DynamicString *src);

// src must be a char array ending in a '\0' -- null terminated
int dstring_combine_simple(DynamicString *dest, const char *src);

int dstring_combine_nsimple(DynamicString *dest, const char *src, size_t size);


#endif
