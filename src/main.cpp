#include <cxxopts.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "version.hpp"

int
main(int argc, char *argv[]) {
    cxxopts::Options options("dog");

    // clang-format off
    options.add_options()
        ("n,number", "Show line numbers") 
        ("E,show-ends", "Show line endings")
        ("version", "Show the version")
        ("input_files", "Input file(s) to concatenate", cxxopts::value<std::vector<std::string>>());
    // clang-format on

    options.parse_positional({"input_files"});
    cxxopts::ParseResult result;

    try {
        result = options.parse(argc, argv);
    } catch (const cxxopts::OptionParseException &x) {
        std::cerr << "dog: " << x.what() << '\n';
        std::cerr << "usage: dog [options] <input_file> ...\n";
        return EXIT_FAILURE;
    }

    if (result.count("version")) {
        std::cout << "dog version " << DogWholeVersion << '\n';
        return EXIT_SUCCESS;
    }

    if (!result.count("input_files")) {
        std::cerr << "dog: missing input file(s)!\n";
        std::cerr << "usage: dog [options] <input_file> ...\n";
        return EXIT_FAILURE;
    }

    for (const auto &file_name : result["input_files"].as<std::vector<std::string>>()) {
        std::ifstream input_file(file_name, std::ios::in);
        if (!input_file.is_open()) {
            std::cerr << "dog: could not open input file '" << file_name << "'!\n";
            return EXIT_FAILURE;
        }

        std::string line;
        int         line_count = 1;
        while (std::getline(input_file, line)) {
            if (result.count("number")) {
                std::cout << std::setw(6) << std::setfill(' ') << line_count++ << "  ";
            }

            std::cout << line;

            if (result.count("show-ends")) {
                std::cout << '$';
            }

            std::cout << '\n';
        }
    }

    return EXIT_SUCCESS;
}