cmake_minimum_required(VERSION 3.16)

add_library (library_lib library.cpp utils.cpp  person.cpp author.cpp book.cpp member.cpp)
target_include_directories(library_lib PUBLIC "../include" "/home/kishore/lib/cereal-1.3.2/include"   "/home/kishore/lib/fmt-9.0.0/include")
message("Library created")