cmake_minimum_required(VERSION 3.18)
include(FetchContent)

FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG master
)

FetchContent_MakeAvailable(httplib)