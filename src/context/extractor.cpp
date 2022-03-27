/**
 * @file extractor.cpp
 * @author  Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 */

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace cpu::ctx {

namespace detail {

std::vector<std::byte> parse_mem_string(std::string mem) {
  auto make_mem_vec_string = [&mem]() {
    std::vector<std::string> vec_mem_string;

    for (auto i = 0; i < mem.size() / 4; ++i) {
      auto byte = mem.substr(i * 5, mem.find(" "));
      if (!byte.starts_with(' '))
        vec_mem_string.emplace_back(byte);
    }

    return vec_mem_string;
  };

  auto mem_vec_string = make_mem_vec_string();
  std::vector<std::byte> mem_vec;

  for (auto &&e : mem_vec_string)
    mem_vec.emplace_back(std::byte(std::stoi(e.c_str(), 0, 16)));

  return mem_vec;
}

} // namespace detail

} // namespace cpu::ctx
