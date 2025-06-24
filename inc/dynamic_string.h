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

int dstring_readline(DynamicString *dstring, FILE *stream);

int dstring_append(DynamicString *dstring, char ch);

#endif
