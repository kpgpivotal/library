cmake_minimum_required(VERSION 3.16)

add_library (library_lib library.cpp utils.cpp librarian.cpp person.cpp author.cpp book.cpp)
target_include_directories(library_lib PUBLIC ../include)
message("Library created")