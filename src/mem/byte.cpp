#include "cpu/util/obs_ptr.hpp"
#include <cpu/mem/byte.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::mem {

ROByte ROByte::from_ptr(util::ObsPtr<std::byte const> ptr) {
  auto byte = ROByte();
  byte.raw_byte_ = ptr;

  return byte;
}

Byte Byte::from_ptr(util::ObsPtr<std::byte> ptr) {
  auto byte = Byte();
  byte.raw_byte_ = ptr;

  return byte;
}

} // namespace cpu::mem
