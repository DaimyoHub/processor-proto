#include "cpu/core/reg_table.hpp"
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>
#include <iostream>

namespace cpu::isa {

// Branch
Br Br::prepare(mem::Addr addr) { return Br{.addr_ = addr}; }

void Br::impl(mem::Byte pc_handle, std::size_t bytes_count) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Br::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();

  impl(pc_handle, bytes_count);
}

// Branch if equal
Beq Beq::prepare(mem::Addr addr) { return Beq{.addr_ = addr}; }

void Beq::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
               std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) == mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Beq::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

// Branch if not equal
Bne Bne::prepare(mem::Addr addr) { return Bne{.addr_ = addr}; }

void Bne::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
               std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) != mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Bne::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

// Branch if greater
Bg Bg::prepare(mem::Addr addr) { return Bg{.addr_ = addr}; }

void Bg::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
              std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) > mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Bg::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

// Branch if smaller
Bs Bs::prepare(mem::Addr addr) { return Bs{.addr_ = addr}; }

void Bs::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
              std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) < mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Bs::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

// Branch if greater or equal
Bge Bge::prepare(mem::Addr addr) { return Bge{.addr_ = addr}; }

void Bge::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
               std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) >= mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Bge::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

// Branch if smaller or equal
Bse Bse::prepare(mem::Addr addr) { return Bse{.addr_ = addr}; }

void Bse::impl(mem::Byte pc_handle, mem::Byte cmp_handle,
               std::size_t bytes_count, mem::Byte lhs, mem::Byte rhs) {
  ASSERT_IS_IN_RANGE(0, bytes_count - 1, addr_.get());

  if (mem::in(lhs) <= mem::in(rhs))
    mem::out(cmp_handle, core::CmpState::EQUAL);
  else
    mem::out(cmp_handle, core::CmpState::UNKNOWN);

  if (mem::in(cmp_handle) == core::CmpState::EQUAL)
    mem::out(pc_handle, addr_.get());

  consume_hint--;
}

void Bse::operator()(core::Ctx &ctx) {
  auto pc_handle = ctx.get_reg().pc.get();
  auto cmp_handle = ctx.get_reg().cmp.get();
  auto bytes_count = ctx.get_mem().get_bytes_count();
  auto lhs = ctx.get_reg().lhs.get();
  auto rhs = ctx.get_reg().rhs.get();

  impl(pc_handle, cmp_handle, bytes_count, lhs, rhs);
}

} // namespace cpu::isa
