#include <cpu/core/context.hpp>
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/mem/reg.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

int main() {
  using namespace cpu;

  auto ctx = core::Ctx::create();

  std::cout << mem::in(ctx.get_reg().program_counter.get()) << std::endl;

  auto br = isa::Br::prepare(mem::Addr::from(5));
  br(ctx);

  std::cout << mem::in(ctx.get_reg().program_counter.get()) << std::endl;
}
