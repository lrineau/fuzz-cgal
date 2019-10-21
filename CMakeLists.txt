project(fuzz-cgal CXX)

cmake_minimum_required(VERSION 3.11...3.15)

find_package(CGAL REQUIRED)

add_executable(test_fuzzer test_fuzzer.cc)
target_link_libraries(test_fuzzer CGAL::CGAL)
target_compile_options(test_fuzzer PRIVATE -fsanitize=fuzzer)
target_link_options(test_fuzzer PRIVATE -fsanitize=fuzzer)
