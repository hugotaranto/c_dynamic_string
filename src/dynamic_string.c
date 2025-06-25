#include "dynamic_string.h"
#include <ctype.h>

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
  // allocate the data -- with 1 extra spot for the null character
  string->data = malloc(sizeof(char) * size + 1);

  if(!string->data) {
    return NULL;
  }

  // set all to null characters
  memset(string->data, '\0', sizeof(char) * (string->size + 1));

  return string;
}

void dstring_free(DynamicString *dstring) {
  // free the data
  free(dstring->data);
  free(dstring);
}

void dstring_clear(DynamicString *dstring) {
  dstring->length = 0;
  memset(dstring->data, '\0', sizeof(char) * (dstring->size + 1));
}

int dstring_resize(DynamicString *dstring, size_t new_size) {
  // this resizes the dynamic string making sure that there is an extra space for the '\0' character
  if(!dstring) {
    return -1;
  }
  if(new_size < 0) {
    return -1;
  }
  dstring->data = realloc(dstring->data, sizeof(char) * (new_size + 1));
  if(!dstring->data) {
    return -1;
  }
  dstring->size = new_size;
  if(dstring->length > dstring->size) {
    dstring->length = dstring->size;
  }

  // set all of the new data to null
  memset(&dstring->data[dstring->length], '\0', sizeof(char) * (dstring->size - dstring->length + 1));

  return 0;
}

int dstring_readline(DynamicString *dstring, FILE *stream) {

  if (!dstring) {
    return -1;
  }

  if (!stream) {
    return -2;
  }

  // reset the string to be empty
  dstring_clear(dstring);

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
    if(dstring_resize(dstring, dstring->size * 2)) {
      return -1;
    }
  }

  // then we can append the element
  dstring->data[dstring->length++] = ch;

  return 0;
}

int dstring_combine(DynamicString *dest, DynamicString *src) {
  
  if(!dest || !src) {
    return -1;
  }

  // make sure the destination has enough space
  size_t total_size = dest->length + src->length;
  if(dest->size < total_size) {
    // if it isn't the size must be increased
    if(dstring_resize(dest, total_size)) {
      return -1;
    }
  }

  // then the data can be copied in
  memcpy(&dest->data[dest->length], src->data, sizeof(char) * src->length);
  dest->length = total_size;

  return 0;
}

int dstring_combine_simple(DynamicString *dest, const char *src) {

  if(!dest || !src) {
    return - 1;
  }

  int i = 0;
  while(src[i] != '\0') {
    if (dstring_append(dest, src[i])) {
      return -1;
    }
    i++;
  }

  return 0;
}

int dstring_combine_nsimple(DynamicString *dest, const char *src, size_t size) {
  if(!dest || !src) {
    return -1;
  }

  if(size <= 0) {
    return -1;
  }

  // make sure the destination has enough space
  size_t total_size = dest->length + size;
  if(dest->size < total_size) {
    // if it isn't the size must be increased
    if(dstring_resize(dest, total_size)) {
      return -1;
    }
  }

  // then the data can be copied in
  memcpy(&dest->data[dest->length], src, sizeof(char) * total_size);
  dest->length = total_size;

  return 0;
}

DynamicString* dstring_to_lower(DynamicString *src) {

  if(!src) {
    return NULL;
  }
  // create the output string
  DynamicString *out = dstring_initialise_size(src->length);

  if(!out) {
    return NULL;
  }

  // loop through all of the data
  for(size_t i = 0; i < src->length; i++) {
    out->data[i] = tolower(src->data[i]);
  }

  out->length = src->length;
  out->size = src->size;

  return out;
}


DynamicString* dstring_to_upper(DynamicString *src) {
  if(!src) {
    return NULL;
  }
  // create the output string
  DynamicString *out = dstring_initialise_size(src->length);

  if(!out) {
    return NULL;
  }

  // just copy the data directly in, we don't have to use slow append
  for(size_t i = 0; i < src->length; i++) {
    out->data[i] = toupper(src->data[i]);
  }

  out->length = src->length;
  out->size = src->length;

  return out;
}


