#include <cstdlib>
#include <iostream>
#include <fmt/core.h>
#include <glog/logging.h>
#include <gflags/gflags.h>
#include "Message.hpp"
#include <chrono>
#include <pthread.h>

pthread_mutex_t count_mutex;
pthread_cond_t  count_threshold_cv;

int main(int argc, char** argv) {
  using std::chrono::high_resolution_clock;
//   Message say_hello("Hello, CMake World!");

//   std::cout << say_hello << std::endl;

//   Message say_goodbye("Goodbye, CMake World");

//   std::cout << say_goodbye << std::endl;
  std::chrono::_V2::system_clock::time_point now = high_resolution_clock::now();
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  fmt::print("hello, {}\n", "world");
  LOG(ERROR) << "file";
  auto diff = high_resolution_clock::now() - now;
  fmt::print("lasts: {}\n", diff.count());
  return EXIT_SUCCESS;
}