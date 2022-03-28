#include "cpu/utils/obs_pointer.hpp"
#include <cassert>
#include <cpu/context/memory.hpp>
#include <cpu/utils/assertions.hpp>
#include <cstddef>

namespace cpu::ctx {

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

std::byte Mem::operator[](std::size_t idx) const {
  ASSERT_IS_INDEX_OF(idx, native_handle_);

  return native_handle_[idx];
}

std::byte &Mem::operator[](std::size_t idx) {
  ASSERT_IS_INDEX_OF(idx, native_handle_);

  return native_handle_[idx];
}

util::ObsPtr<std::byte> Mem::begin() { return &native_handle_[0]; }
util::ObsPtr<std::byte const> Mem::begin() const { return &native_handle_[0]; }

util::ObsPtr<std::byte> Mem::end() {
  return &native_handle_[native_handle_.size()];
}

util::ObsPtr<std::byte const> Mem::end() const {
  return &native_handle_[native_handle_.size()];
}

std::size_t Mem::size() const { return native_handle_.size(); }

} // namespace cpu::ctx
