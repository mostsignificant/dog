########################################################################################################################
### DOG APPLICATION
########################################################################################################################

add_executable(${DOG_PROJECT_NAME}
        ${DOG_SRC_DIR}/main.cpp
        ${DOG_SRC_DIR}/program_options.cpp)

target_compile_features(${DOG_PROJECT_NAME} PUBLIC
        cxx_std_20)

target_include_directories(${DOG_PROJECT_NAME} PUBLIC
        ${DOG_INC_DIR})