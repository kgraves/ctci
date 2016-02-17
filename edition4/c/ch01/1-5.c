#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void urlize(char *str) {
  int len = strlen(str);
  int numSpaces = 0;
  for (int i=0; i<len; i++) {
    if (str[i] == ' ') {
      numSpaces++;
    }
  }

  if (numSpaces == 0) {
    return;
  }

  // calculate total characters after replacment
  int totalLen = len + (2 * numSpaces);
  int currPosition = totalLen - 1;
  for (int i=len-1; i>=0; i--) {
    if (str[i] == ' ') {
      str[currPosition--] = '0';
      str[currPosition--] = '2';
      str[currPosition--] = '%';
    } else {
      str[currPosition--] = str[i];
    }
  }

  // append null char at end of string
  str[totalLen] = '\0';
}

int main() {
  // tests
  char str1[] = "a a a\0   ";
  char str1_expected[] = "a%20a%20a";
  urlize(str1);
  assert(strcmp(str1, str1_expected) == 0);

  char str2[] = "  \0    ";
  char str2_expected[] = "%20%20";
  urlize(str2);
  assert(strcmp(str2, str2_expected) == 0);

  char str3[] = "asdf";
  char str3_expected[] = "asdf";
  urlize(str3);
  assert(strcmp(str3, str3_expected) == 0);

  return 0;
}
