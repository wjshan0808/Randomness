
#
project(subA2xTest
#    LANGUAGES CXX
#    VERSION 1.0.1
)


# LIBRARY_OUTPUT_PATH
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../../lib)


# header directory
set(includeDirectory ${includeDirectory} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(BEFORE ${includeDirectory})

# header files GLOB_RECURSE CONFIGURE_DEPENDS
file(GLOB_RECURSE inc${PROJECT_NAME} LIST_DIRECTORIES false ${CMAKE_CURRENT_SOURCE_DIR} "*.h*")
# TREE
#source_group(TREE "Header Files" FILES ${CMAKE_CURRENT_SOURCE_DIR})

# source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} src${PROJECT_NAME})


# object
add_library(${PROJECT_NAME} OBJECT
    ${inc${PROJECT_NAME}}
    ${src${PROJECT_NAME}}
#    $<TARGET_OBJECTS:subA2xKits>
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
target_link_libraries(${PROJECT_NAME}
#    subA2xKits
    m
)

#
list(APPEND subTargetObjects $<TARGET_OBJECTS:${PROJECT_NAME}>)
set(subTargetObjects ${subTargetObjects} PARENT_SCOPE)
message("${PROJECT_NAME} subTargetObjects = " ${subTargetObjects})

