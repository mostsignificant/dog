#include "program_options.hpp"

#include <stdexcept>
#include <string>
#include <vector>

void
program_options::parse(int argc, char* argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    bool first = false;
    for (const auto& arg : args) {
        if (!first) {
            _input_file = arg;
            first       = true;
        } else if (arg == "-n") {
            if (_show_line_numbers) throw std::runtime_error("dog: cannot use -n parameter twice!");
            _show_line_numbers = true;
        } else {
            throw std::runtime_error("dog: unknown parameter!");
        }
    }
}

std::string_view
program_options::input_file() const noexcept {
    return _input_file;
}

bool
program_options::show_line_numbers() const noexcept {
    return _show_line_numbers;
}
