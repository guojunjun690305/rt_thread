cmake_minimum_required(VERSION 3.16)
project(rt_thread)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -o3")
find_package(Threads)
include_directories(
  ${PROJECT_SOURCE_DIR}/include

)

link_directories(${PROJECT_SOURCE_DIR})

add_executable(
	rt_thread 
	src/rt_thread.cpp
	src/thread_1.cpp
	src/thread_2.cpp
)

target_link_libraries(
	rt_thread 
	pthread
	${CMAKE_THREAD_LIBS_INIT}
)

