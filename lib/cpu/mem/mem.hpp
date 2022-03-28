/**
 * @file mem.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 */

#pragma once

#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <vector>

namespace cpu::mem {

class Byte;
class ROByte;

class Mem {
private:
  // The memory object is based on a simple native handle representing a
  // contiguous sequence of bytes.
  std::vector<std::byte> native_handle_;

  std::size_t bytes_count_;

public:
  /**
   * Constructs a memory object from a given vector.
   *
   * @param vec The source vector.
   * @return Mem
   */
  static Mem from_vec(std::vector<std::byte> vec);

  Mem() = default;

  Mem(Mem &&other);
  Mem &operator=(Mem &&other);

  Mem(Mem const &other) = delete;
  Mem operator=(Mem const &other) = delete;

public:
  /**
   * Gets the first byte contained in memory. This is a utility function mainly
   * used for for-loops.
   *
   * @return std::byte&  The first byte in memory.
   */
  util::ObsPtr<std::byte> begin();
  util::ObsPtr<std::byte const> begin() const;

  /**
   * Gets the last byte contained in memory. This is a utility function mainly
   * used for for-loops.
   *
   * @return std::byte&  The last byte in memory.
   */
  util::ObsPtr<std::byte> end();
  util::ObsPtr<std::byte const> end() const;

  /**
   * Gets the wanted byte at te given index.
   *
   * @param idx The index of the byte in memory.
   */
  Byte operator[](std::size_t idx);
  ROByte operator[](std::size_t idx) const;

  /**
   * Gets the count of bytes contained by the memory chunck.
   *
   * @return std::size_t
   */
  std::size_t bytes_count() const;
};

} // namespace cpu::mem
