#include "cpu/mem/addr.hpp"
#include "printer.hpp"
#include <chrono>
#include <cpu/core/ctx.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/isa/br_comp.hpp>
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/mem/reg.hpp>
#include <cpu/util/assert.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <type_traits>
#include <vector>

using namespace cpu;

// BR 22

int main() {
  auto ctx = core::Ctx::create();

  mem::out(ctx.get_reg().addr, 22);
  mem::out(ctx.get_reg().lhs, 77);
  mem::out(ctx.get_reg().rhs, 78);

  isa::Bne::prepare(ctx).reg();

  print_ctx(ctx);
}
