cmake_minimum_required(VERSION 3.16)

# name
project(Randomness
    LANGUAGES CXX
    VERSION 1.0.1
)


#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# LIBRARY_OUTPUT_PATH
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib)


# header directory
set(includeDirectory ${includeDirectory} ${CMAKE_CURRENT_SOURCE_DIR}/../../../include)
include_directories(BEFORE ${includeDirectory})

# header files GLOB_RECURSE CONFIGURE_DEPENDS
file(GLOB inc${PROJECT_NAME} LIST_DIRECTORIES false ${CMAKE_CURRENT_SOURCE_DIR} "*.h*")
# TREE
#source_group(TREE "Header Files" FILES ${CMAKE_CURRENT_SOURCE_DIR})

# source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} src${PROJECT_NAME})


#
set(subTargetObjects)

# sub dir
add_subdirectory(A2xKits)
add_subdirectory(A2xTest)

message("${PROJECT_NAME} subTargetObjects = " ${subTargetObjects})


# shared library
add_library(${PROJECT_NAME} SHARED
    ${inc${PROJECT_NAME}}
    ${src${PROJECT_NAME}}
#    $<TARGET_OBJECTS:subA2xKits>
#    $<TARGET_OBJECTS:subA2xTest>
)
# target properties
target_compile_definitions(${PROJECT_NAME}
    PUBLIC RANDOMNESS_LIBRARY
)
target_link_directories(${PROJECT_NAME} BEFORE
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE ${subTargetObjects}
#   PUBLIC subA2xTest
    m
)

#
set_target_properties(${PROJECT_NAME} PROPERTIES
#    OUTPUT_NAME "x"
    VERSION 1.0
    SOVERSION 1
)


# post_build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND sh post_build.sh ARGS ${CMAKE_CURRENT_SOURCE_DIR} ${includeDirectory}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


