cmake_minimum_required (VERSION 3.6)

project (library)
add_subdirectory(src)

set(Boost_USE_STATIC_RUNTIME FALSE)
set(Boost_USE_STATIC_LIBS TRUE)
set(Boost_USE_MULTITHREADED TRUE)
set(THREAD_LIBRARY_DEBUG TRUE)
set(Boost_USE_DEBUG_RUNTIME FALSE)
set(Boost_COMPILER "-clang17")

set_target_properties( ${Boost_ALL_TARGETS}
                       PROPERTIES IMPORTED_GLOBAL TRUE )
find_package(Boost   COMPONENTS  filesystem date_time  log system 
thread log_setup chrono atomic serialization exception regex context REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()
message(STATUS "Boost version: ${Boost_VERSION}")

include_directories (${Boost_INCLUDE_DIR})

add_definitions(-DBOOST_LOG_DYN_LINK)
add_executable(library main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS}) 

message(" Boost_LIBRARIES " ${Boost_LIBRARIES})

set(CMAKE_CXX_STANDARD_LIBRARIES -lboost_serialization)
target_link_libraries(${PROJECT_NAME} PUBLIC   ${Boost_LIBRARIES} 
  PRIVATE  library_lib   )