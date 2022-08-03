cmake_minimum_required (VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
project (library)
add_subdirectory(src)

add_executable(library main.cpp)


target_link_libraries(${PROJECT_NAME} 
  PRIVATE  library_lib /home/kishore/lib/fmt-9.0.0/lib/libfmt.a )