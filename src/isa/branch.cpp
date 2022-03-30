#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::isa {

Br Br::prepare(mem::Addr addr) {
  Br br;
  br.addr_ = addr;

  return br;
}

void Br::impl(mem::Byte pc_handle, std::size_t bytes_count) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  mem::out(pc_handle, addr_.get());

  consume_hint--;
}

/*
void Br::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().program_counter.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();

  impl(pc_handle, bytes_count);
}
*/

} // namespace cpu::isa
