# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enable C++ support
project(runTask LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

ADD_EXECUTABLE (runTask main.cpp PeriodicTaskScheduler.cpp)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)
target_link_libraries(runTask Boost::thread)

if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(runTask PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(runTask "${CMAKE_THREAD_LIBS_INIT}")
endif()




# and its sources
target_sources(
  runTask
  PRIVATE
    main.cpp
    PeriodicTaskScheduler.cpp
  )
