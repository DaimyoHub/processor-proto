/**
 * @file extractor.cpp
 * @author  Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 */

#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace cpu::mem {

namespace detail {

std::vector<int> parse_mem_string(std::string mem) {
  auto bytes_count = get_bytes_count_from_mem_string(mem);

  auto make_mem_vec_string = [&]() {
    std::vector<std::string> vec_mem_string;

    for (auto i = 0; i < bytes_count; ++i) {
      auto byte = mem.substr(i * 5, mem.find(" "));
      if (!byte.starts_with(' '))
        vec_mem_string.emplace_back(byte);
    }

    return vec_mem_string;
  };

  auto mem_vec_string = make_mem_vec_string();

  std::vector<int> mem_vec;
  mem_vec.reserve(bytes_count);

  for (auto &&e : mem_vec_string)
    mem_vec.emplace_back(std::stoi(e.c_str(), 0, 16));

  return mem_vec;
}

char const *UnableToOpenMemFile::what() const noexcept {
  return "Unable to open memory file. (see member variable 'filename' to get "
         "the filename)";
}

size_t get_bytes_count_from_mem_string(std::string_view mem_string) {
  return mem_string.size() / 5;
}

} // namespace detail

Mem extract_mem_from_file(std::string filename) {
  auto try_open_file = [filename = std::move(filename)]() {
    std::ifstream file;

    file = std::ifstream(filename);

    if (!file.is_open())
      throw detail::UnableToOpenMemFile(filename);

    return file;
  };

  auto file = try_open_file();

  auto get_string_from_file = [&file]() {
    std::string line;
    std::string mem_string;

    while (std::getline(file, line))
      mem_string += line + ' ';

    return mem_string;
  };

  auto mem_string = get_string_from_file();

  return Mem::from_vec(detail::parse_mem_string(mem_string));
}

} // namespace cpu::mem
