#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

int main() {
  using namespace cpu::mem;

  auto mem = extract_mem_from_file("/home/daimyo/dev/cpu/res/null_mem.mf");

  out(mem[6], 78);
  std::cout << in(mem[6]) << std::endl;
}
