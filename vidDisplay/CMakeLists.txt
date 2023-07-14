cmake_minimum_required(VERSION 2.8)
#set project name
project( vidDisplay )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#add all the executable files
add_executable( src/main src/main.cpp src/filter.cpp)

#linking libraries
target_link_libraries( src/main ${OpenCV_LIBS} )