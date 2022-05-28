#include <stdio.h>
#include <string.h>

int main()
{
  printf("WASM Ready - Testing with Emscripten HTML!\n");
  return 42;
}

int get_number()
{
  return 22;
}

int get_double_number(int number)
{
  return number * 2;
}

char *greet(char *name)
{
  char greeting[50];
  if (strlen(name) > 40)
  {
    return "Name too long";
  }
  strcpy(greeting, "Hello ");
  return strcat(greeting, name);
}