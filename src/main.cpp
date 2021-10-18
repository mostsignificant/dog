#include <fstream>
#include <iostream>
#include <string>

#include "program_options.hpp"

int
main(int argc, char *argv[]) {
    try {
        program_options::parse(argc, argv);
    } catch (const std::exception &x) {
        std::cerr << x.what() << '\n';
        std::cerr << "usage: dog [-n|--number] [-E|--show-ends] <input_file> ...\n";
        return EXIT_FAILURE;
    }

    for (const auto &file_name : program_options::input_files()) {
        std::ifstream input_file(file_name, std::ios::in);
        if (!input_file.is_open()) {
            std::cerr << "dog: could not open input file '" << file_name << "'!\n";
            return EXIT_FAILURE;
        }

        std::string line;
        int         line_count = 1;
        while (std::getline(input_file, line)) {
            if (program_options::show_line_numbers()) {
                std::cout << std::setw(6) << std::setfill(' ') << line_count++ << "  ";
            }

            std::cout << line;

            if (program_options::show_ends()) {
                std::cout << '$';
            }

            std::cout << '\n';
        }
    }

    return EXIT_SUCCESS;
}