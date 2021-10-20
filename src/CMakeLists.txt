########################################################################################################################
### DOG APPLICATION
########################################################################################################################

add_executable(${DOG_PROJECT_NAME}
        ${DOG_SRC_DIR}/main.cpp)

target_compile_features(${DOG_PROJECT_NAME} PUBLIC
        cxx_std_20)

target_include_directories(${DOG_PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${DOG_INC_DIR}
        cxxopts)

target_link_libraries(${DOG_PROJECT_NAME} PUBLIC 
        cxxopts)