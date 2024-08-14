#!/usr/bin/env -S cmake -P

# "Unix Makefiles" "MSYS Makefiles"
# cmake -B ./../../build -S . -G "Unix Makefiles"

#
message(NOTICE "CMAKE_ARGC = " ${CMAKE_ARGC})
set(indexCmakeArgc 1)
while(${indexCmakeArgc} LESS ${CMAKE_ARGC})
    if("${CMAKE_ARGV${indexCmakeArgc}}" STREQUAL "-P")
        math(EXPR indexCmakeArgc "${indexCmakeArgc} + 1")
        break()
    endif()
    math(EXPR indexCmakeArgc "${indexCmakeArgc} + 1")
endwhile()

#
set(valueCmakeArgv "")
while(${indexCmakeArgc} LESS ${CMAKE_ARGC})
    list(APPEND valueCmakeArgv "${CMAKE_ARGV${indexCmakeArgc}}")
    math(EXPR indexCmakeArgc "${indexCmakeArgc} + 1")
endwhile()
message(NOTICE "valueCmakeArgv = " ${valueCmakeArgv})


#
set(buildGenerator "Unix Makefiles")
set(cmakeDirectory ${CMAKE_CURRENT_LIST_DIR})
set(buildDirectory ${CMAKE_CURRENT_LIST_DIR}/../../build)
message(NOTICE "buildDirectory = " ${buildDirectory})

#
if(EXISTS ${buildDirectory})
    #
    set(buildDirectoryFiles)
    set(buildDirectoryFilesCount)
    file(GLOB buildDirectoryFiles ${buildDirectory} "*")
    list(LENGTH buildDirectoryFiles buildDirectoryFilesCount)
    message(NOTICE "buildDirectoryFilesCount = " ${buildDirectoryFilesCount})

    if(${buildDirectoryFilesCount} GREATER 0)

        #
        message(NOTICE "clean = " ${buildDirectory})
        file(REMOVE_RECURSE ${buildDirectory})

    endif()

endif()

#
file(MAKE_DIRECTORY ${buildDirectory})

#
set(cmakeConfigResult)
execute_process(
    # ${valueCmakeArgv}
    COMMAND "${CMAKE_COMMAND}" -B "${buildDirectory}" -S "${cmakeDirectory}" -G "${buildGenerator}"
    WORKING_DIRECTORY "${buildDirectory}"
    RESULT_VARIABLE cmakeConfigResult
    COMMAND_ERROR_IS_FATAL ANY
)
#
message(STATUS "cmakeConfigResult = " ${cmakeConfigResult})
if(NOT ${cmakeConfigResult} EQUAL 0)
    #
    message(FATAL_ERROR "cmakeConfigResult = " ${cmakeConfigResult})
endif()


#
message(NOTICE "CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
set(cmakeBuildResult)
execute_process(
    # --config ${CMAKE_BUILD_TYPE}
    COMMAND "${CMAKE_COMMAND}" --build "${buildDirectory}"
    WORKING_DIRECTORY "${buildDirectory}"
    RESULT_VARIABLE cmakeBuildResult
    COMMAND_ERROR_IS_FATAL ANY
)
#
message(STATUS "cmakeBuildResult = " ${cmakeBuildResult})
if(NOT ${cmakeBuildResult} EQUAL 0)
    #
    message(FATAL_ERROR "cmakeBuildResult = " ${cmakeBuildResult})
endif()


