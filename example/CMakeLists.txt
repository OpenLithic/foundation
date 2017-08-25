cmake_minimum_required (VERSION 3.1.0)

set(PROJECT_NAME foundation-example)
project(${PROJECT_NAME})
set(FOUNDATION_DIR ${CMAKE_BINARY_DIR}/foundation-0.1.0)
if(NOT EXISTS ${FOUNDATION_DIR})

endif()
execute_process(COMMAND git clone --recursive https://github.com/OpenLithic/foundation.git ${CMAKE_BINARY_DIR}/foundation)
set(FOUNDATION_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/build.json)
add_subdirectory(${CMAKE_BINARY_DIR}/foundation/lib)

# include(ExternalProject)
# ExternalProject_Add(foundation
#   # GIT_REPOSITORY https://github.com/OpenLithic/foundation.git
#   # GIT_TAG master
#   URL ${CMAKE_CURRENT_LIST_DIR}/../lib
#   CMAKE_ARGS
#     -DFOUNDATION_CONFIG=${CMAKE_CURRENT_SOURCE_DIR}/build.json
#     -DFOUNDATION_OUTPUT_DIR=${CMAKE_BINARY_DIR}
#   UPDATE_COMMAND ""
#   INSTALL_COMMAND ""
# )
