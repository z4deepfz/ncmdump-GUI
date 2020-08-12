project(ncmdump-GUI)
cmake_minimum_required(VERSION 2.4)
# find library
find_package(wxWidgets REQUIRED)
find_package(taglib)

# Compile source files
set(CMAKE_CXX_FLAGS "-std=c++11 -static -s -O3 -flto -Wno-deprecated-declarations -DTAGLIB_STATIC") # specified flags

# Set Variables
# On Windows

message(STATUS "Compiling under win32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
list(APPEND PLATEFORM_LIBS
	ws2_32
	comctl32
)

# Begin Compile
aux_source_directory(. SRC_LIST) # add source files
aux_source_directory(ncmdump SRC_LIST)
list(APPEND SRC_LIST resource.rc)

include_directories(${wxWidgets_INCLUDE_DIRS} ${taglib_INCLUDE_DIRS})
link_directories(${wxWidgets_LIB_DIR} ${taglib_LIB_DIR})

add_executable(ncmdump-GUI ${SRC_LIST})

target_link_libraries(ncmdump-GUI 
	${wxWidgets_LIBRARIES}
	${taglib_LIBRARIES}
)

