cmake_minimum_required(VERSION 2.8)
#set project name
project( imgDisplay )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#add all the executable files
add_executable(main src/main.cpp)

#linking libraries
target_link_libraries( main ${OpenCV_LIBS} )