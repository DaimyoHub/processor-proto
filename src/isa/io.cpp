#include "cpu/mem/access.hpp"
#include <cpu/isa/io.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/util/assert.hpp>

namespace cpu::isa {

// Load
Ld Ld::prepare(core::Ctx &ctx) { return Ld{.ctx = ctx}; }

void Ld::operator()(mem::Byte reg, int val) { _exc_impl(reg, val); }

void Ld::_exc_impl(mem::Byte reg, int val) {
  ASSERT_IS_POSITIVE(val);
  mem::write(reg, val);
}

// Store
Str Str::prepare(core::Ctx &ctx) { return Str{.ctx = ctx}; }

void Str::operator()(mem::Byte mem, int val) { _exc_impl(mem, val); }

void Str::_exc_impl(mem::Byte mem, int val) {
  ASSERT_IS_POSITIVE(val);
  mem::write(mem, val);
}

} // namespace cpu::isa
