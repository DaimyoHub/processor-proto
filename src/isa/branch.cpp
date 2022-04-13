#include <cpu/core/reg_table.hpp>
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>
#include <iostream>

namespace cpu::isa {

// Branch
Br Br::prepare(core::Ctx &ctx) { return Br{.ctx = ctx}; }

void Br::_exc_impl(mem::Addr addr) {
  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  mem::out(ctx.get_reg().pc, addr.get());

  consume_hint--;
}

void Br::reg() {
  auto addr = mem::Addr::from(mem::in(ctx.get_reg().src.get()));
  _exc_impl(addr);
}

void Br::val(mem::Addr addr) { _exc_impl(addr); }

} // namespace cpu::isa
