#include <cpu/mem/byte.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/assert.hpp>
#include <cpu/util/obs_ptr.hpp>

namespace cpu::mem {

ROByte ROByte::from_ptr(util::ObsPtr<int const> ptr) {
  auto byte = ROByte();
  byte.raw_byte_ = ptr;

  return byte;
}

Byte Byte::from_ptr(util::ObsPtr<int> ptr) {
  auto byte = Byte();
  byte.raw_byte_ = ptr;

  return byte;
}

ROByte::ROByte(ROByte &&other) : raw_byte_(other.raw_byte_) {}

ROByte &ROByte::operator=(ROByte &&other) {
  raw_byte_ = other.raw_byte_;
  return *this;
}

ROByte ROByte::def() { return ROByte::from_ptr(nullptr); }

Byte::Byte(Byte &&other) : raw_byte_(other.raw_byte_) {}

Byte &Byte::operator=(Byte &&other) {
  raw_byte_ = other.raw_byte_;
  return *this;
}

Byte::Byte(Byte const &other) : raw_byte_(other.raw_byte_) {}

Byte &Byte::operator=(Byte const &other) {
  raw_byte_ = other.raw_byte_;
  return *this;
}

ROByte::ROByte(ROByte const &other) : raw_byte_(other.raw_byte_) {}

ROByte &ROByte::operator=(ROByte const &other) {
  raw_byte_ = other.raw_byte_;
  return *this;
}

Byte Byte::def() { return Byte::from_ptr(nullptr); }

} // namespace cpu::mem
