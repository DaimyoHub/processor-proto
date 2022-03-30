/**
 * @file context.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/reg_table.hpp>
#include <cpu/mem/mem.hpp>

namespace cpu::core {

class Ctx {
private:
  mem::Mem memory_;
  RegTable registers_;

public:
public:
  mem::Mem &get_mem();

  RegTable &get_reg();
};

} // namespace cpu::core