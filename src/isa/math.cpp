#include <cpu/isa/math.hpp>
#include <cpu/mem/byte.hpp>

namespace cpu::isa {

// Add
Add Add::prepare(core::Ctx &ctx) { return Add{.ctx = ctx}; }

void Add::operator()(mem::Byte reg, int lhs, int rhs) {
  _exc_impl(reg, lhs, rhs);
}

void Add::_exc_impl(mem::Byte reg, int lhs, int rhs) {
  int result = lhs + rhs;
  mem::out(reg, result);
}

// Sub
Sub Sub::prepare(core::Ctx &ctx) { return Sub{.ctx = ctx}; }

void Sub::operator()(mem::Byte reg, int lhs, int rhs) {
  _exc_impl(reg, lhs, rhs);
}

void Sub::_exc_impl(mem::Byte reg, int lhs, int rhs) {
  int result = lhs - rhs;
  mem::out(reg, result);
}

// Mul
Mul Mul::prepare(core::Ctx &ctx) { return Mul{.ctx = ctx}; }

void Mul::operator()(mem::Byte reg, int lhs, int rhs) {
  _exc_impl(reg, lhs, rhs);
}

void Mul::_exc_impl(mem::Byte reg, int lhs, int rhs) {
  int result = lhs * rhs;
  mem::out(reg, result);
}

// Div
Div Div::prepare(core::Ctx &ctx) { return Div{.ctx = ctx}; }

void Div::operator()(mem::Byte reg, int lhs, int rhs) {
  _exc_impl(reg, lhs, rhs);
}

void Div::_exc_impl(mem::Byte reg, int lhs, int rhs) {
  int result = lhs / rhs;
  mem::out(reg, result);
}

// Inc
Inc Inc::prepare(core::Ctx &ctx) { return Inc{.ctx = ctx}; }

void Inc::operator()(mem::Byte reg) { _exc_impl(reg); }

void Inc::_exc_impl(mem::Byte reg) {
  int result = mem::in(reg) + 1;
  mem::out(reg, result);
}

// Dec
Dec Dec::prepare(core::Ctx &ctx) { return Dec{.ctx = ctx}; }

void Dec::operator()(mem::Byte reg) { _exc_impl(reg); }

void Dec::_exc_impl(mem::Byte reg) {
  int result = mem::in(reg)-1;
  mem::out(reg, result);
}

} // namespace cpu::isa
