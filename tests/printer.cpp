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
  std::cout << regs.pc.get_label() << ":\t "
            << "\e[102;30m" << cpu::mem::in(regs.pc.get()) << "\e[49;39m"
            << '\n';

  std::cout << regs.cmp.get_label() << ":\t " << cpu::mem::in(regs.cmp.get())
            << '\t' << regs.lhs.get_label() << ":\t "
            << cpu::mem::in(regs.lhs.get()) << '\n';

  std::cout << regs.a0.get_label() << ":\t " << cpu::mem::in(regs.a0.get())
            << '\t' << regs.rhs.get_label() << ":\t "
            << cpu::mem::in(regs.rhs.get()) << '\n';

  std::cout << regs.a1.get_label() << ":\t " << cpu::mem::in(regs.a1.get())
            << '\t' << regs.dst.get_label() << ":\t "
            << cpu::mem::in(regs.dst.get()) << '\n';
}

void print_ctx(cpu::core::Ctx const &ctx) {
  print_reg(ctx.get_reg());
  std::cout << std::endl;
  print_mem(ctx.get_mem(), cpu::mem::in(ctx.get_reg().pc.get()));
}
