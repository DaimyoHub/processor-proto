/**
 * @file extract.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 *
 * Extractors serve as tools to easily convert formatted memory data into
 * memory objects.
 */

#pragma once

#include <cpu/mem/mem.hpp>
#include <cstddef>
#include <exception>
#include <fstream>
#include <istream>
#include <string_view>
#include <vector>

namespace cpu::mem {

namespace detail {

/**
 * Parses the given string to construct a vector representing a memory chunck.
 *
 * @param mem The memory formatted as a string
 * @return std::vector<std::byte>  The constructed vector
 */
std::vector<std::byte> parse_mem_string(std::string mem);

struct UnableToOpenMemFile : public std::exception {

  std::string filename;

  UnableToOpenMemFile(std::string_view filename) : filename(filename) {}

  /**
   * The returned message is "Unable to "
   *
   * @return char const*
   */
  char const *what() const noexcept;
};

/**
 * Get count of bytes in the given memory string.
 *
 * @param mem_string Memory string to analyze
 * @return std::size_t  The number of formatted bytes conatined in the given
 * string.
 */
std::size_t get_bytes_count_from_mem_string(std::string_view mem_string);

} // namespace detail

/**
 * Extracts formatted memory from a given file to construct a Mem object.
 *
 * @param filename The filename of the given file.
 * @return Mem  The new Mem object constructed from the given file.
 */
Mem extract_mem_from_file(std::string filename);

/**
 * Extracts formatted memory from a given input stream to construct a Mem
 * object.
 *
 * @param input_stream The handle of the input stream.
 * @return Mem  The new Mem object constructec from the given input stream.
 */
Mem extract_mem_from_input(std::istream input_stream);

} // namespace cpu::mem
