#include "test.h"

TEST_CASE("Compile a single file executable", "[simple]") 
{
  testenvironment env;
  create("hello/src/hello.cpp", R"(
#include <stdio.h>
int main() {
  printf("Hello World!\n");
}
)");
  run("evoke");
  REQUIRE(file_exists("build/gcc/bin/hello"));
  REQUIRE(file_exists("build/gcc/obj/hello/src/hello.cpp.o"));
  REQUIRE(run("build/gcc/bin/hello").first == "Hello World!\n");
}

