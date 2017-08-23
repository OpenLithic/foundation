cmake_minimum_required (VERSION 3.1.0)

project(foundation-test)

include(ExternalProject)
ExternalProject_Add(foundation
  GIT_REPOSITORY https://github.com/OpenLithic/foundation.git
  GIT_TAG master
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""
)
