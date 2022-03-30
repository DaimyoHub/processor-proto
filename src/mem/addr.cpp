#include <cpu/mem/addr.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::mem {

Addr Addr::from(int raw_addr) {
  ASSERT_IS_POSITIVE(raw_addr);

  Addr addr;
  addr.raw_addr_ = raw_addr;

  return addr;
}

int Addr::get() const { return raw_addr_; }

Addr::Addr(Addr &&other) : raw_addr_(other.raw_addr_) {}

Addr &Addr::operator=(Addr &&other) {
  raw_addr_ = other.raw_addr_;
  return *this;
}

Addr::Addr(Addr const &other) : raw_addr_(other.raw_addr_) {}

Addr &Addr::operator=(Addr const &other) {
  raw_addr_ = other.raw_addr_;
  return *this;
}

} // namespace cpu::mem
