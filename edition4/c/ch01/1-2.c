#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str) {
  char *end = str;
  char temp;
  
  if (str) {
    // find end of string
    while(*end) {
      ++end;
    }
    --end;

    while(str < end) {
      // swap chars
      temp = *str;
      *str = *end;
      *end = temp;

      // move to next spot
      ++str;
      --end;
    }
  }
}

int main() {
  // test
  char str1[] = "This is a test string";
  reverseString(str1);
  assert(strcmp(str1, "gnirts tset a si sihT") == 0);
  
  return 0;
}
