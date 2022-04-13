#include "cpu/mem/reg.hpp"
#include <cassert>
#include <cpu/core/ctx.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/assert.hpp>
#include <utility>

namespace cpu::core {

Ctx Ctx::create() {
  Ctx ctx;
  ctx.memory_ =
      mem::extract_mem_from_file("/home/daimyo/dev/cpu/res/null_mem.mf");
  ctx.code_ = mem::Mem();

  ctx._init_registers();

  return ctx;
}

void Ctx::_init_registers() {
  registers_ = core::RegTable{};

  registers_.pc = mem::Reg::with_label("pc");
  registers_.pc.describe("Program counter");

  registers_.cmp = mem::Reg::with_label("cmp");
  registers_.cmp.describe("Comparator");

  registers_.a0 = mem::Reg::with_label("a0");
  registers_.a0.describe("Accumulator");

  registers_.a1 = mem::Reg::with_label("a1");
  registers_.a1.describe("Accumulator");

  registers_.lhs = mem::Reg::with_label("lhs");
  registers_.lhs.describe("Left hand side");

  registers_.rhs = mem::Reg::with_label("rhs");
  registers_.rhs.describe("Right hand side");

  registers_.dst = mem::Reg::with_label("dst");
  registers_.dst.describe("Destination");

  registers_.addr = mem::Reg::with_label("addr");
  registers_.addr.describe("Address");

  registers_.src = mem::Reg::with_label("src");
  registers_.src.describe("Source");
}

Ctx::Ctx(Ctx &&other)
    : memory_(std::move(other.memory_)), code_(std::move(other.code_)),
      registers_(std::move(other.registers_)) {}

Ctx &Ctx::operator=(Ctx &&other) {
  memory_ = std::move(other.memory_);
  code_ = std::move(other.code_);
  registers_ = std::move(other.registers_);

  return *this;
}

mem::Mem &Ctx::get_mem() { return memory_; }
mem::Mem const &Ctx::get_mem() const { return memory_; }

mem::Mem const &Ctx::get_code() const { return code_; }

void Ctx::load_code(mem::Mem code) { code_ = std::move(code); }

RegTable &Ctx::get_reg() { return registers_; }
RegTable const &Ctx::get_reg() const { return registers_; }

} // namespace cpu::core
