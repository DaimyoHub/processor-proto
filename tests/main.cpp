#include <cpu/context/extractor.hpp>
#include <cpu/context/memory.hpp>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  std::string text = "0xff 0x06 0x03 0x06";

  auto res = cpu::ctx::detail::parse_mem_string(text);
}
