#include "dynamic_string.h"

DynamicString* dstring_initialise() {
  return dstring_initialise_size(DYNAMIC_STRING_INIT);
}

DynamicString* dstring_initialise_size(size_t size) {

  if (size < 0) {
    return NULL;
  }

  // create the dynamic string object here
  DynamicString *string = malloc(sizeof(DynamicString));

  // initialise the variables
  string->length = 0;
  string->size = size;
  // allocate the data
  string->data = malloc(sizeof(char) * size);

  if(!string->data) {
    return NULL;
  }

  // set all to null characters
  memset(string->data, '\0', sizeof(char) * string->size);

  return string;
}

void dstring_free(DynamicString *dstring) {
  // free the data
  free(dstring->data);
  free(dstring);
}

int dstring_readline(DynamicString *dstring, FILE *stream) {

  if (!dstring) {
    return -1;
  }

  if (!stream) {
    return -2;
  }

  // read in characters until end of file or \n
  int ch;
  while ((ch = fgetc(stream)) != EOF && ch != '\n') {
    char character = (char)ch;
    if(dstring_append(dstring, character)) {
      return -2;
    }
  }

  return 0;
}

int dstring_append(DynamicString *dstring, char ch) {
  // first check the size of the string
  
  // if they are the same we need to increase the size
  if(dstring->size <= dstring->length) {
    dstring->size = dstring->size * 2;
    dstring->data = realloc(dstring->data, sizeof(char) * dstring->size);
    // set all the new characters to null
    memset(&dstring->data[dstring->length], '\0', sizeof(char) * (dstring->size - dstring->length));
    if(!dstring->data) {
      return -1;
    }

  }

  // then we can append the element
  dstring->data[dstring->length++] = ch;

  return 0;
}


