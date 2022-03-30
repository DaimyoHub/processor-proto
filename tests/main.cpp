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

  auto reg = mem::Reg::with_label("pc");
  mem::out(reg.get(), 3);

  auto br = isa::Br::prepare(mem::Addr::from(4));

  std::cout << isa::is_instr_consumed(br) << std::endl;

  br.impl(reg.get(), 10);

  std::cout << isa::is_instr_consumed(br) << std::endl;
}
