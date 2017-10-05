cmake_minimum_required(VERSION 3.4)


project(Test_MainModule VERSION 0.0.0 LANGUAGES CXX)


#for adding an executable
add_executable(exe src/main.cpp)
#for addding an library
#add_library(lib SHARED|STATIC)


target_include_directories(exe PUBLIC include)
target_link_libraries(exe PRIVATE streams)
#target_sources(exe|lib PUBLIC|PRIVATE .\src)

#target_link_libraries(exe|lib PUBLIC|PRIVATE other_target)

#target_compile_definitions(exe|lib DEF)
#target_compile_options(exe|lib OPT)
#target_compile_features(exe|lig FEAT)

install(TARGETS exe DESTINATION bin)


target_compile_options(exe 
		#PRIVATE "-O3" 
		PRIVATE "-std=c++14"
		)

set_target_properties(exe
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
#target_compile_options(exe )
