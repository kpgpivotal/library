cmake_minimum_required (VERSION 3.6)

project (library)
add_subdirectory(src)


set(Boost_USE_STATIC_RUNTIME FALSE)
set(Boost_USE_STATIC_LIBS TRUE)
set(Boost_USE_MULTITHREADED TRUE)
set(THREAD_LIBRARY_DEBUG TRUE)
set(Boost_USE_DEBUG_RUNTIME FALSE)
set(Boost_COMPILER "-clang11")

find_package(Boost  REQUIRED COMPONENTS filesystem date_time filesystem log system 
                thread log_setup chrono atomic)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()
message(STATUS "Boost version: ${Boost_VERSION}")

include_directories (${Boost_INCLUDE_DIR})

add_definitions(-DBOOST_LOG_DYN_LINK)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS}) 

message(" Boost_LIBRARIES " ${Boost_LIBRARIES})


target_link_libraries(${PROJECT_NAME} PUBLIC   ${Boost_LIBRARIES}
  PRIVATE  library_lib
  
  )

  