cmake_minimum_required (VERSION 3.6)

project (library)
add_subdirectory(src)

add_executable(library main.cpp)


target_link_libraries(${PROJECT_NAME} 
  PRIVATE  library_lib)