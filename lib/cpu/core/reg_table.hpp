/**
 * @file reg_table.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/mem/reg.hpp>

namespace cpu::core {

struct RegTable {
  mem::Reg program_counter;
};

} // namespace cpu::core