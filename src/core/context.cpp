#include <cpu/core/context.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
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

  registers_.program_counter = mem::Reg::with_label("pc");
  registers_.program_counter.describe("Program counter");
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

mem::Mem const &Ctx::get_code() { return code_; }

void Ctx::load_code(mem::Mem code) { code_ = std::move(code); }

RegTable &Ctx::get_reg() { return registers_; }

} // namespace cpu::core
