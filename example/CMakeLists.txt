cmake_minimum_required (VERSION 3.1.0)

include(ExternalProject)
ExternalProject_Add(foundation
  # GIT_REPOSITORY https://github.com/OpenLithic/foundation.git
  # GIT_TAG master
  URL ${CMAKE_CURRENT_LIST_DIR}/../lib
  CMAKE_ARGS
    -DFOUNDATION_CONFIG=${CMAKE_CURRENT_SOURCE_DIR}/build.json
    -DFOUNDATION_OUTPUT_DIR=${CMAKE_BINARY_DIR}
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""
)
