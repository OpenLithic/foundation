cmake_minimum_required (VERSION 3.1.0)

set(PROJECT_NAME foundation-example)
set(FOUNDATION_VERSION v0.1.0)

project(${PROJECT_NAME})
set(FOUNDATION_DIR ${CMAKE_BINARY_DIR}/foundation-${FOUNDATION_VERSION})
if(NOT EXISTS ${FOUNDATION_DIR})
  file(MAKE_DIRECTORY ${FOUNDATION_DIR})
  set(FOUNDATION_DOWNLOAD_DIR ${CMAKE_BINARY_DIR}/downloads)
  set(FOUNDATION_DOWNLOAD ${FOUNDATION_DOWNLOAD_DIR}/foundation-${FOUNDATION_VERSION}.zip)
  if(NOT EXISTS ${FOUNDATION_DOWNLOAD})
    file(DOWNLOAD
      https://github.com/OpenLithic/foundation/releases/download/${FOUNDATION_VERSION}/foundation.zip
      ${FOUNDATION_DOWNLOAD})
  endif()
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar -xfz ${FOUNDATION_DOWNLOAD}
    WORKING_DIRECTORY ${FOUNDATION_DIR})
endif()
set(FOUNDATION_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/build.json)
add_subdirectory(${FOUNDATION_DIR})
