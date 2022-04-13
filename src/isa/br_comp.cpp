#include <cpu/isa/br_comp.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::isa {

int compare_lhs_and_rhs(mem::Byte lhs, mem::Byte rhs) {
  auto value = mem::in(lhs)-mem::in(rhs);

  if (value < 0)
    return core::CmpState::SMALLER;
  else if (value > 0)
    return core::CmpState::GREATER;
  else if (value == 0)
    return core::CmpState::EQUAL;
  else
    return core::CmpState::UNKNOWN;
}

// Branch if equal
Beq Beq::prepare(core::Ctx &ctx) { return Beq{.ctx = ctx}; }

void Beq::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) == mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Beq::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

// Branch if not equal
Bne Bne::prepare(core::Ctx &ctx) { return Bne{.ctx = ctx}; }

void Bne::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) != mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Bne::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

// Branch if greater
Bg Bg::prepare(core::Ctx &ctx) { return Bg{.ctx = ctx}; }

void Bg::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) > mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Bg::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

// Branch if not equal
Bs Bs::prepare(core::Ctx &ctx) { return Bs{.ctx = ctx}; }

void Bs::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) < mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Bs::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

// Branch if not equal
Bge Bge::prepare(core::Ctx &ctx) { return Bge{.ctx = ctx}; }

void Bge::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) >= mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Bge::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

// Branch if not equal
Bse Bse::prepare(core::Ctx &ctx) { return Bse{.ctx = ctx}; }

void Bse::_exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  auto mem_bytes_count = ctx.get_mem().get_bytes_count();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto pc_handle = ctx.get_reg().pc.get();

  ASSERT_IS_IN_RANGE(0, ctx.get_mem().get_bytes_count() - 1, addr.get());

  if (mem::in(lhs) <= mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr.get());

  consume_hint--;
}

void Bse::operator()(mem::Addr addr, mem::Byte lhs, mem::Byte rhs) {
  _exc_impl(addr, lhs, rhs);
}

} // namespace cpu::isa
