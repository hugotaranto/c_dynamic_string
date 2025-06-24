#include "dynamic_string.h"

int main() {
  // initialise a dynamic string
  DynamicString *string = dstring_initialise_size(5);
  // then read from user input
  int res = dstring_readline(string, stdin);

  printf("Result: %d\n", res); 
  printf("size: %lu, length: %lu\n", string->size, string->length);

  // print the output back
  printf("%s\n", string->data);

  dstring_free(string);
}


