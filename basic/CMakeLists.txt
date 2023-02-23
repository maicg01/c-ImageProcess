# cmake_minimum_required(VERSION 3.9.1)
# project(CMakeHello)
# set(CMAKE_CXX_STANDARD 14)
# add_executable(cmake_hello hello.cpp)


#nang cao voi nhieu system
cmake_minimum_required(VERSION 3.9.1)
project(CMakeHello)
set(CMAKE_CXX_STANDARD 14)
# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system hhh")
elseif(WIN32)
    message("This is a Windows System")
endif()
# or use MATCHES to see if actual system name 
# Darwin is Apple's system name
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system kkk")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a Windows System")
endif()
add_executable(cmake_hello hello.cpp)