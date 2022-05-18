// WasmFiddle converter from C to Wasm: https://wasdk.github.io/WasmFiddle/

void num_log(int number);
void str_log(char *message);

int main()
{
  return 42;
}

void greet()
{
  str_log("Hello from C programming language!");
}

void get_double_number(int number)
{
  num_log(number * 2);
}
