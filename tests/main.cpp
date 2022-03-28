#include "cpu/utils/obs_pointer.hpp"
#include <cpu/context/extractor.hpp>
#include <cpu/context/memory.hpp>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

int main() {
  using namespace cpu::ctx;

  auto mem = extract_mem_from_file("/home/daimyo/dev/cpu/resources/test.mf");

  for (auto e : mem)
    std::cout << static_cast<int>(e) << ' ';
}
