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
        std::cerr << "usage: dog <input_file> [-n]\n";
        return EXIT_FAILURE;
    }

    std::ifstream input_file(argv[1], std::ios::in);
    if (!input_file.is_open()) {
        std::cerr << "dog: could not open input file '" << argv[1] << "'!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    int         line_count = 1;
    while (std::getline(input_file, line)) {
        if (argc >= 3 && strcmp(argv[2], "-n") == 0)
            std::cout << std::setw(5) << std::setfill(' ') << line_count++ << "  ";

        std::cout << line << '\n';
    }

    return EXIT_SUCCESS;
}