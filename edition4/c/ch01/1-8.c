#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isRotation(char *str1, char *str2) {
  int size = (strlen(str1) * 2)  + 1;
  char str[size];
  strcpy(str, str1);
  strcat(str, str1);
  str[size-1] = 0;

  return strstr(str, str2) == 0 ? 0 : 1;
}

int main() {
  // tests
  char str1[] = "This is a test string ";
  char str2[] = "a test string This is ";
  int actual = isRotation(str1, str2);
  assert(actual == 1);

  char str3[] = "Test";
  char str4[] = "estT";
  actual = isRotation(str3, str4);
  assert(actual == 1);

  char str5[] = "Test";
  char str6[] = "esz";
  actual = isRotation(str5, str6);
  assert(actual == 0);

  return 0;
}
