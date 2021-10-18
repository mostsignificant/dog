#include "program_options.hpp"

#include <filesystem>
#include <stdexcept>
#include <vector>

namespace {

static std::vector<std::string_view> _input_files;
static bool                          _show_line_numbers = false;
static bool                          _show_ends         = false;

}  // namespace

void
program_options::parse(int argc, char* argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    for (const auto& arg : args) {
        if (_input_files.empty()) {
            if (arg == "-n" || arg == "--number") {
                if (_show_line_numbers) {
                    throw std::runtime_error("dog: cannot use -n/--number parameter twice!");
                }
                _show_line_numbers = true;
                continue;
            }

            if (arg == "-E" || arg == "--show-ends") {
                if (_show_ends) {
                    throw std::runtime_error("dog: cannot use -E/--show-ends parameter twice!");
                }
                _show_ends = true;
                continue;
            }
        }

        if (!std::filesystem::exists(arg)) {
            throw std::runtime_error(std::string("dog: ") + std::string(arg) + ": No such file or directory");
        }
        _input_files.push_back(arg);
    }
}

const std::vector<std::string_view>&
program_options::input_files() {
    return _input_files;
}

bool
program_options::show_ends() {
    return _show_ends;
}

bool
program_options::show_line_numbers() {
    return _show_line_numbers;
}
