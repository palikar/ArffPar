cmake_minimum_required(VERSION 3.4)


project(Test_libs VERSION 0.0.0 LANGUAGES CXX)


#Modern CMake library
#set(lib_ROOT_DIR lib/)
#find_package(lib REQUIRED )


#Library from binary 
#add_library(lib STATIC IMPORTED)
#set_property(TARGET lib PROPERTY INTERFACE_INCLUDE_DIRECTORIES lib/inlcude)
#set_property(TARGET boost-iostreams PROPERTY IMPORTED_LOCATION lib/bin/)

#Header only library
#add_library(lib INTERFACE)
#target_include_directories(lib INTERFACE lib/include GLOBAL)

#Library from source 
#add_library(lib STATIC)
#target_sources(lib lib/src)
#target_include_directories(lib lib/inc)



######STREAMS LIBRARY######
add_library(streams INTERFACE)
target_include_directories(streams INTERFACE streams/source GLOBAL)
install(DIRECTORY streams/source/ DESTINATION ${CMAKE_BINARY_DIR}/inc)

################################



