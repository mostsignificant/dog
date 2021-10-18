#ifndef THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED
#define THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED

#include <string_view>
#include <vector>

namespace program_options {

void parse(int argc, char* argv[]);

const std::vector<std::string_view>& input_files();
bool                                 show_ends();
bool                                 show_line_numbers();

};  // namespace program_options

#endif  // THAT_THIS_PROGRAM_OPTIONS_HEADER_FILE_IS_ALREADY_INCLUDED