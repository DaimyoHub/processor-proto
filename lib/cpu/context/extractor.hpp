/**
 * @file extractor.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 */

#pragma once

#include <cpu/context/memory.hpp>
#include <cstddef>
#include <fstream>
#include <istream>
#include <string_view>
#include <vector>

namespace cpu::ctx {

namespace detail {

/**
 * Parses the given string to construct a vector representing a memory chunck.
 *
 * @param mem The memory formatted as a string
 * @return std::vector<std::byte>  The constructed vector
 */
std::vector<std::byte> parse_mem_string(std::string mem);

} // namespace detail

/**
 * Extracts formatted memory from a given file to construct a Mem object.
 *
 * @param filename The filename of the given file.
 * @return Mem  The new Mem object constructed from the given file.
 */
Mem extract_mem_from_file(std::string_view filename);

/**
 * Extracts formatted memory from a given input stream to construct a Mem
 * object.
 *
 * @param input_stream The handle of the input stream.
 * @return Mem  The new Mem object constructec from the given input stream.
 */
Mem extract_mem_from_input(std::istream input_stream);

} // namespace cpu::ctx
