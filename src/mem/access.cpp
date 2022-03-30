#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>

#if defined(CPU_MULTITHREADED)
#include <mutex>
#endif

namespace cpu::mem {

int read(Byte byte) { return *byte.raw_byte_; }

int read(ROByte byte) { return *byte.raw_byte_; }

void write(Byte byte, int data) {
#if defined(CPU_MULTITHREADED)
  std::lock_guard(byte.mutex_);
#endif
  *byte.raw_byte_ = data;
}

int in(ROByte byte) { return static_cast<int>(read(byte)); }

int in(Byte byte) { return static_cast<int>(read(byte)); }

void out(Byte byte, int data) { write(byte, data); }

} // namespace cpu::mem
