#include "dynamic_string.h"

// int main() {
//   // initialise a dynamic string
//   DynamicString *string = dstring_initialise_size(5);
//   // then read from user input
//   int res = dstring_readline(string, stdin);
//
//   printf("Result: %d\n", res); 
//   printf("size: %lu, length: %lu\n", string->size, string->length);
//
//   // print the output back
//   printf("%s\n", string->data);
//
//
//   DynamicString *combine_test = dstring_initialise();
//   dstring_readline(combine_test, stdin);
//
//   dstring_combine(string, combine_test);
//
//   printf("Combined String: %s\n", string->data);
//
//   dstring_combine_simple(combine_test, " Test123 ");
//
//   printf("simple Comine: %s\n", combine_test->data);
//
//   dstring_free(combine_test);
//   dstring_free(string);
// }

int main() {
  DynamicString *string = dstring_initialise_size(5);
  dstring_readline(string, stdin);
  printf("Size: %lu, Length: %lu, String: %s\n",string->size, string->length, string->data);

  DynamicString *string2 = dstring_initialise_size(6);
  dstring_readline(string2, stdin);
  printf("Size: %lu, Length: %lu, String: %s\n",string2->size, string2->length, string2->data);

  dstring_combine(string2, string);
  printf("Size: %lu, Length: %lu, String: %s\n",string2->size, string2->length, string2->data);

  dstring_free(string2);
  dstring_free(string);
}

