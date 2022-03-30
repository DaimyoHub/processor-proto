/**
 * @file byte.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/mem/access.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <cstdio>

namespace cpu::mem {

/**
 * A read-only byte is a byte contained in memory that can only be read. This
 * class represents this kind of byte, moreover, it is a box that allows to
 * use memory without responsibilities issues.
 */
class ROByte {
  friend std::byte read(ROByte const &byte);

private:
  util::ObsPtr<std::byte const> raw_byte_;

public:
  ROByte() = default;

  ROByte(ROByte &&other);
  ROByte &operator=(ROByte &&other);

  ROByte(ROByte const &other) = delete;
  ROByte &operator=(ROByte const &other) = delete;

  /**
   * Constructs a read-only byte box from a given raw byte in memory.
   *
   * @param ptr A pointer to the raw byte.
   * @return ROByte
   */
  static ROByte from_ptr(util::ObsPtr<std::byte const> ptr);
};

/**
 * A byte is contained in memory which can be mutated and read. This
 * class represents this kind of byte, moreover, it is a box that allows to
 * use memory without responsibilities issues.
 */
class Byte {
  friend std::byte read(Byte const &byte);
  friend void write(Byte &byte, std::byte data);

private:
  util::ObsPtr<std::byte> raw_byte_;

public:
  Byte() = default;

  Byte(Byte &&other);
  Byte &operator=(Byte &&other);

  Byte(Byte const &other) = delete;
  Byte &operator=(Byte const &other) = delete;

  /**
   * Constructs a byte box from a given raw byte in memory.
   *
   * @param ptr A pointer to the raw byte.
   * @return Byte
   */
  static Byte from_ptr(util::ObsPtr<std::byte> ptr);
};

} // namespace cpu::mem