########################################################################################################################
### DOG APPLICATION
########################################################################################################################

cmake_minimum_required(VERSION 3.2)

########################################################################################################################
### PROJECT DESCRIPTION AND META INFO
########################################################################################################################

set(DOG_PROJECT_NAME        "dog")
set(DOG_PROJECT_DESCRIPTION "a cat-like cli tool to showcase argument parsing")
set(DOG_AUTHOR_DOMAIN       "https://github.com/mostsignificant/dog")
set(DOG_AUTHOR_MAINTAINER   "mostsig@gmail.com")
set(DOG_VERSION_MAJOR       "0")
set(DOG_VERSION_MINOR       "0")
set(DOG_VERSION_PATCH       "1")
set(DOG_VERSION             "${DOG_VERSION_MAJOR}.${DOG_VERSION_MINOR}.${DOG_VERSION_PATCH}")
set(DOG_NAME_VERSION        "${DOG_PROJECT_NAME} v${DOG_VERSION} (${DOG_VERSION_REVISION})")

########################################################################################################################
### DECLARE PROJECT
########################################################################################################################

project(${DOG_PROJECT_NAME})

set(DOG_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(DOG_INC_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

