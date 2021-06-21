#include <cstdlib>
#include <iostream>
#include <fmt/core.h>
#include <glog/logging.h>
#include <gflags/gflags.h>
#include "Message.hpp"

int main(int argc, char** argv) {
//   Message say_hello("Hello, CMake World!");

//   std::cout << say_hello << std::endl;

//   Message say_goodbye("Goodbye, CMake World");

//   std::cout << say_goodbye << std::endl;
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  fmt::print("hello, {}\n", "world");
  LOG(ERROR) << "file";
  return EXIT_SUCCESS;
}