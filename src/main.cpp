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

    if (argc < 2) {
        std::cerr << "dog: missing input file!\n";
        std::cerr << "usage: dog <input_file> ...\n";
        return EXIT_FAILURE;
    }

    for (auto i = 1; i < argc; ++i) {
        std::ifstream input_file(argv[i], std::ios::in);
        if (!input_file.is_open()) {
            std::cerr << "dog: could not open input file '" << argv[i] << "'!\n";
            return EXIT_FAILURE;
        }

        std::string line;
        while (std::getline(input_file, line)) {
            std::cout << line << '\n';
        }
    }

    return EXIT_SUCCESS;
}