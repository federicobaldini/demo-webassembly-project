#include <emscripten.h>
#include <string.h>

int get_number()
{
  int number = 22;

  // emscripten_debugger();

  if (number < 30)
  {
    emscripten_log(EM_LOG_WARN, "'number' less than 30");
  }

  return number;
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