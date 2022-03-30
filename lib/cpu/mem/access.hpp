/**
 * @file access.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cstddef>

namespace cpu::mem {

class Byte;
class ROByte;

/**
 * Reads memory at the given index.
 *
 * @param idx The index of the byte to read.
 * @return std::byte The read byte.
 */
int read(Byte byte);

/**
 * Reads memory at the given index.
 *
 * @param idx The index of the byte to read.
 * @return std::byte The read byte.
 */
int read(ROByte byte);

/**
 * If memory is not read-only, writes the given data in it, at the given
 * index.
 *
 * @param idx The index of the byte to write.
 * @param data The data to write in.
 */
void write(Byte byte, int data);

/**
 * This function is a shortcut for cpu::mem::read. Return type is an integer,
 * it is easier to fastly use than an std::byte.
 *
 * @see std::byte cpu::mem::read(cpu::mem::ROByte byte)
 *
 * @param byte The byte to read.
 * @return int  The value of the read byte.
 */
int in(ROByte byte);

/**
 * This function is a shortcut for cpu::mem::read. Return type is an integer,
 * it is easier to fastly use than an std::byte.
 *
 * @see std::byte cpu::mem::read(cpu::mem::Byte byte)
 *
 * @param byte The byte to read.
 * @return int  The value of the read byte.
 */
int in(Byte byte);

/**
 * This function is a shortcut from cpu::mem::write. Input data is in integer
 * format. It is easier to fastly use than an std::byte.
 *
 * @see cpu::mem::write(Byte byte, std::byte data)
 *
 * @param byte The byte to write.
 * @param data The data to write.
 */
void out(Byte byte, int data);

} // namespace cpu::mem
