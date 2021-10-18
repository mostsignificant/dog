#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int
main(int argc, char *argv[]) {
#ifdef _DEBUG
    std::copy(argv, argv + argc, std::ostream_iterator<char *>(std::cout, "\n"));
#endif

    const bool show_line_numbers = argc >= 2 && (strcmp(argv[1], "-n") == 0);
    const int  input_files_i     = show_line_numbers ? 2 : 1;

    if (argc < input_files_i) {
        std::cerr << "dog: missing input file!\n";
        std::cerr << "usage: dog [-n] <input_file> ...\n";
        return EXIT_FAILURE;
    }

    for (auto i = input_files_i; i < argc; ++i) {
        std::ifstream input_file(argv[i], std::ios::in);
        if (!input_file.is_open()) {
            std::cerr << "dog: could not open input file '" << argv[i] << "'!\n";
            return EXIT_FAILURE;
        }

        std::string line;
        int         line_count = 1;
        while (std::getline(input_file, line)) {
            if (show_line_numbers) {
                std::cout << std::setw(6) << std::setfill(' ') << line_count++ << "  ";
            }

            std::cout << line << '\n';
        }
    }

    return EXIT_SUCCESS;
}