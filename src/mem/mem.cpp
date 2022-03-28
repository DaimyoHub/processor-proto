#include <cassert>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/assert.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>

namespace cpu::mem {

Mem Mem::from_vec(std::vector<std::byte> vec) {
  Mem obj;
  obj.bytes_count_ = vec.size();
  obj.native_handle_ = std::move(vec);

  return obj;
}

Mem::Mem(Mem &&other)
    : native_handle_(std::move(other.native_handle_)),
      bytes_count_(other.bytes_count_) {}

Mem &Mem::operator=(Mem &&other) {
  bytes_count_ = other.bytes_count_;
  native_handle_ = std::move(other.native_handle_);

  return *this;
}

util::ObsPtr<std::byte> Mem::begin() { return &native_handle_[0]; }

util::ObsPtr<std::byte const> Mem::begin() const { return &native_handle_[0]; }

util::ObsPtr<std::byte> Mem::end() {
  return &native_handle_[native_handle_.size()];
}

util::ObsPtr<std::byte const> Mem::end() const {
  return &native_handle_[native_handle_.size()];
}

Byte Mem::operator[](std::size_t idx) {
  ASSERT_IS_INDEX_OF(idx, bytes_count());

  return Byte::from_ptr(&native_handle_[idx]);
}

ROByte Mem::operator[](std::size_t idx) const {
  ASSERT_IS_INDEX_OF(idx, bytes_count());

  return ROByte::from_ptr(&native_handle_[idx]);
}

std::size_t Mem::bytes_count() const { return native_handle_.size(); }

} // namespace cpu::mem
