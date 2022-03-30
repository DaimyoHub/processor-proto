#include <cpu/core.hpp>
#include <cpu/mem.hpp>
#include <iostream>

void print_mem(cpu::mem::Mem const &mem, int pc_state) {
  int counter = mem.get_bytes_count();
  int line_counter = 1;

  std::cout << "0:\t";

  for (int i = 0; i < mem.get_bytes_count(); ++i) {
    if (counter % 32 == 0 && counter != mem.get_bytes_count()) {
      std::cout << '\n' << line_counter << ":\t";
      line_counter++;
    }

    if (counter % 8 == 0)
      std::cout << " ";

    counter--;

    if (pc_state == i)
      std::cout << "\e[102;30m" << cpu::mem::in(mem[i]) << "\e[49;39m" << ' ';
    else
      std::cout << cpu::mem::in(mem[i]) << ' ';
  }
}

void print_reg(cpu::core::RegTable const &regs) {
  std::cout << regs.program_counter.get_label() << ":\t "
            << "\e[102;30m" << cpu::mem::in(regs.program_counter.get())
            << "\e[49;39m" << '\n';
}

void print_ctx(cpu::core::Ctx const &ctx) {
  print_reg(ctx.get_reg());
  print_mem(ctx.get_mem(), cpu::mem::in(ctx.get_reg().program_counter.get()));
}
