#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceDups(char *str) {
  if (str == 0) {
    return;
  }

  int len = strlen(str);
  if (len < 2) {
    return;
  }

  int currPosition = 1;
  for (int head=1; head<len; head++) {

    int tail;
    for (tail=0; tail<currPosition; tail++) {
      if (str[head] == str[tail]) break;
    }

    if (currPosition == tail) {
      str[currPosition] = str[head];
      currPosition++;
    }
  }

  // append null at the end of new string
  str[currPosition] = 0;
}

int main() {
  // tests
  char str1[] = "This is a test string";
  char str1_expected[] = "This aterng";
  replaceDups(str1);
  assert(strcmp(str1, str1_expected) == 0);

  char str2[] = "  ";
  char str2_expected[] = " ";
  replaceDups(str2);
  assert(strcmp(str2, str2_expected) == 0);

  char str3[] = "aaaaabbbcccccccc";
  char str3_expected[] = "abc";
  replaceDups(str3);
  assert(strcmp(str3, str3_expected) == 0);

  return 0;
}
