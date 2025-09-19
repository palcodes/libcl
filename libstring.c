/**
 * Author: Aayush
 * Description: Collection of string related function reimplemenatations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

// Declarations -- will eventually move to a separate .h file.
unsigned long lenstr(const char *__s);
char *cpystr(char *dest, const char *src);
char *tokenstr(char *str, const char *delim);

// Runner code
int main() {
  char str[] = "hello,, world!";
  char alp[] = "A,B,C";
  char *tok = tokenstr(str, ",!");

  // char *str2 = (char *)malloc(lenstr(str) + 1);
  // char *s = cpystr(str2, str);
  // byte __x = ((byte *)str2)[2];

  // printf("Test o/p for curr function:\t%s\n", s);
  // printf("Printing out byte info:\t\t%p\n", &__x);

  while (tok != NULL) {
    printf("%s\n", tok);
    tok = tokenstr(NULL, ",!");
  }

  // free(str2);
  return 0;
}

// Definitions
unsigned long lenstr(const char *__s) {
  int i = 0;
  while (__s[i] != '\0') {
    i++;
  }
  return i;
};

// @TODO: only works for char * right now.
char *cpystr(char *dest, const char *src) {
  int i = 0;

  // use an integer allocated value of len, instead of recomputing.
  // better yet, loop until the null-terminator character.
  //
  // Another note: I guess this way we are not checking if dest has enough
  // space for the src to be copied.
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';

  return dest;
}

// Tokenizes the provided string by using the delimiters.
// Parse "str" into tokens separated by characters in "delim". ( definition from
// libc )
// If "str" is NULL, then the last string tokenstr() was called with is used.
char *tokenstr(char *str, const char *delim) {
  static char *cursor; // keep track of progress
  char *start;

  if (str != NULL) {
    cursor = str;
  }
  // Nothing left to parse
  if (cursor == NULL)
    return NULL;

  start = cursor;

  int len = lenstr(start);
  int lendelim = lenstr(delim);
  // printf("%s\n", olds);

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < lendelim; j++) {
      if (cursor[i] == delim[j]) {
        cursor[i] = '\0';
        cursor = &cursor[i + 1]; // advance for next call
        return start;
      }
    }
  }
  cursor = NULL;
  return start;
}
