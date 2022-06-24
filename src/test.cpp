#include <iostream>
#include <stdlib.h>
int main(void) {
  std::cout << "test" << std::endl;

  std::string cmd = "ls";
  auto ret = system(cmd.c_str());
  return 0;
}