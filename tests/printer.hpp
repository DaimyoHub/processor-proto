#pragma once

#include <cpu/core.hpp>
#include <cpu/mem.hpp>

void print_mem(cpu::mem::Mem const &mem, int pc_state);

void print_reg(cpu::core::RegTable const &regs);

void print_ctx(cpu::core::Ctx const &ctx);
