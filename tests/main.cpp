#include <cpu/context/memory.hpp>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  auto vec = std::vector<std::byte>{std::byte(1), std::byte(2), std::byte(3)};
  auto mem = Mem::from_vec(std::move(vec));

  mem[3];
}
