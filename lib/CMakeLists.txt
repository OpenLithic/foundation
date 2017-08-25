cmake_minimum_required (VERSION 3.1.0)

function(foundation_load root target type)
  set(FOUNDATION_PROJECT_NAME ${${target}.name})
  project(${FOUNDATION_PROJECT_NAME})

  unset(FOUNDATION_PROJECT_DEPENDENCIES)
  foreach(dependenciesIndex ${${target}.dependencies})
    set(dependency ${${target}.dependencies_${dependenciesIndex}})
    if(dependency)
      # Local library dependency
      set(FOUNDATION_PROJECT_DEPENDENCIES
        ${FOUNDATION_PROJECT_DEPENDENCIES}
        ${dependency})
      foreach(librariesIndex ${${root}.libraries})
        set(library "${root}.libraries_${librariesIndex}")
        set(libraryName ${${library}.name})
        # Include directories listed as published
        foreach(publishIndex ${${library}.publish})
          set(publish "${${library}.publish_${publishIndex}}")
          if(NOT IS_ABSOLUTE ${publish})
            set(publish ${FOUNDATION_DIR}/${publish})
          endif()
          include_directories(${publish})
        endforeach()
      endforeach()
    endif()
  endforeach()

  unset(FOUNDATION_PROJECT_SOURCES)
  foreach(sourcesIndex ${${target}.sources})
    set(source ${${target}.sources_${sourcesIndex}})
    if(NOT IS_ABSOLUTE ${source})
      set(source ${FOUNDATION_DIR}/${source})
    endif()
    if(IS_DIRECTORY ${source})
      file(GLOB FOUNDATION_C_SOURCES ${source}/*.c)
      file(GLOB FOUNDATION_CPP_SOURCES ${source}/*.cpp)
      set(FOUNDATION_PROJECT_SOURCES
        ${FOUNDATION_PROJECT_SOURCES}
        ${FOUNDATION_C_SOURCES}
        ${FOUNDATION_CPP_SOURCES})
    endif()
  endforeach()
  if(type STREQUAL "executable")
    add_executable(${FOUNDATION_PROJECT_NAME} ${FOUNDATION_PROJECT_SOURCES})
  elseif(type STREQUAL "library")
    add_library(${FOUNDATION_PROJECT_NAME} ${FOUNDATION_PROJECT_SOURCES})
  endif()
  target_link_libraries(${FOUNDATION_PROJECT_NAME} ${FOUNDATION_PROJECT_DEPENDENCIES})
endfunction()

function(foundation_load_executable root executable)
  foundation_load(${root} ${executable} "executable")
endfunction()

function(foundation_load_library root library)
  foundation_load(${root} ${library} "library")
endfunction()

project(foundation)
include(${CMAKE_CURRENT_SOURCE_DIR}/json-cmake/JSONParser.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

get_filename_component(FOUNDATION_DIR ${FOUNDATION_CONFIG} DIRECTORY)
file(READ ${FOUNDATION_CONFIG} configString)
sbeParseJson(configJSON configString)s

foreach(librariesIndex ${configJSON.libraries})
  set(library "configJSON.libraries_${librariesIndex}")
  foundation_load_library("configJSON" ${library})
endforeach()

foreach(executablesIndex ${configJSON.executables})
  set(executable "configJSON.executables_${executablesIndex}")
  foundation_load_executable("configJSON" ${executable})
endforeach()
