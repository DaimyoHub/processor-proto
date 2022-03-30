#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>

#if defined(CPU_MULTITHREADED)
#include <mutex>
#endif

namespace cpu::mem {

std::byte read(Byte byte) { return *byte.raw_byte_; }

std::byte read(ROByte byte) { return *byte.raw_byte_; }

void write(Byte byte, std::byte data) {
#if defined(CPU_MULTITHREADED)
  std::lock_guard(byte.mutex_);
#endif
  *byte.raw_byte_ = data;
}

int in(ROByte byte) { return static_cast<int>(read(byte)); }

int in(Byte byte) { return static_cast<int>(read(byte)); }

void out(Byte byte, int data) {
  ASSERT_IS_IN_RANGE(0x00, 0xff, data);

  write(byte, std::byte(data));
}

} // namespace cpu::mem
