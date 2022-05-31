#include <emscripten.h>
#include <stdio.h>

char *string_value = "my string variable";

char *get_string_value()
{
  return string_value;
}

int main()
{
  printf("WASM Ready\n");

  return 42;
}