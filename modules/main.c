// WasmFiddle converter from C to Wasm: https://wasdk.github.io/WasmFiddle/
#include <string.h>

void num_log(int number);
void str_log(char *offset, int length);

int main()
{
  return 42;
}

void greet()
{
  char *message = "Hello from C programming language!";
  str_log(message, strlen(message));
}

void get_double_number(int number)
{
  num_log(number * 2);
}
