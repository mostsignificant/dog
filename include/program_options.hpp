#ifndef THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED
#define THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED

#include <string_view>

class program_options {
public:
    void parse(int argc, char *argv[]);

    std::string_view input_file() const noexcept;
    bool             show_line_numbers() const noexcept;

private:
    std::string_view _input_file;
    bool             _show_line_numbers = false;
};

#endif  // THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED