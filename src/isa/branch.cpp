#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::isa {

Br Br::prepare(mem::Addr addr) {
  Br br;
  br.addr_ = addr;

  return br;
}

void Br::operator()(core::Ctx &ctx) {
  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count(), addr_.get());

  auto prog_addr = ctx.get_reg().program_addr;
  mem::out(prog_addr, addr_);
}

} // namespace cpu::isa
