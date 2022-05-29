#include <emscripten.h>
#include <stdio.h>

// Declare a reusable JavaScript function
EM_JS(void, javascript_function, (int number), {console.log("Call from EM_JS: " + number)});

int main()
{
  printf("WASM Ready\n");

  // Call JavaScript function (eval)
  emscripten_run_script("console.log('Hello from C!')");

  // Call JavaScript function ASYNC (eval)
  emscripten_async_run_script("console.log('Hello from C - ASYNC!')", 2000);

  // Get return value from JavaScript function - INT
  int javascript_value_int = emscripten_run_script_int("getNumber()");

  // Get return value from JavaScript function - STRING
  char *javascript_value_string = emscripten_run_script_string("getString()");

  printf("Value from getNumber() function: %d\n", javascript_value_int);
  printf("Value from getString() function: %s\n", javascript_value_string);

  // Execute EM_JS function
  javascript_function(144);

  return 42;
}