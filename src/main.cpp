#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "dog: missing input file!\n";
        return -1;
    }

    std::ifstream file(argv[1], std::ios::in);
    std::string   line;
    int           line_count = 1;
    while (std::getline(file, line)) {
        if (argc >= 3 && argv[2] == std::string("-n"))
            std::cout << std::setw(5) << std::setfill(' ') << line_count++ << "  ";

        std::cout << line << '\n';
    }
}