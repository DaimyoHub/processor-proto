#include "cpu/isa/io.hpp"
#include "printer.hpp"
#include <chrono>
#include <cpu/core/ctx.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/isa/br_comp.hpp>
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/addr.hpp>
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

/*
 * main:
 *   ld a0, 1
 *   ld a1, 23
 *   ld a2, 40
 *   br proc
 *
 * end:
 *   str 0x05, a0
 *   end
 *
 * proc:
 *   add a3, a0, a1
 *   be end, a3, a2
 *   inc a0
 *   br proc
 */

int main() {
  auto ctx = core::Ctx::create();

  isa::Ld::prepare(ctx)(ctx.get_reg().a0, 78);
  isa::Str::prepare(ctx)(ctx.get_mem()[23], 78);

  print_ctx(ctx);
}
