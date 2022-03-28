/**
 * @file memory.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022 Alexis Pocquet
 */

#pragma once

#include <cpu/utils/obs_pointer.hpp>
#include <cstddef>
#include <vector>

namespace cpu::ctx {

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
   * Fetches the owned data at the given index.
   *
   * @param idx The index of the location of the looked-for data.
   * @return std::byte The data looked for.
   */
  std::byte operator[](std::size_t idx) const;
  std::byte &operator[](std::size_t idx);

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

  std::size_t size() const;
};

} // namespace cpu::ctx
