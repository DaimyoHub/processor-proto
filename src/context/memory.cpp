#include <cassert>
#include <cpu/context/memory.hpp>
#include <cpu/utils/assertions.hpp>
#include <cstddef>

Mem Mem::from_vec(std::vector<std::byte> vec) {
  Mem obj;
  obj.native_handle_ = std::move(vec);

  return obj;
}

Mem::Mem(Mem &&other) : native_handle_(std::move(other.native_handle_)) {}

Mem &Mem::operator=(Mem &&other) {
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
