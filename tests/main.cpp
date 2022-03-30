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
  using namespace cpu::mem;

  auto reg = Reg::with_label("dick");
  reg.describe("Hello world");

  auto content = reg.get();
  out(content, 78);

  std::cout << reg.get_label() << ": " << in(reg.get()) << std::endl;
  std::cout << reg.get_description() << std::endl;
}
