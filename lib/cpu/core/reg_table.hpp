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
#include <cpu/util/obs_ptr.hpp>

int main();

namespace cpu::core {

struct CmpState {
  static constexpr int UNKNOWN = 0;
  static constexpr int EQUAL = 1;
  static constexpr int NOT_EQUAL = 2;
  static constexpr int GREATER = 3;
  static constexpr int SMALLER = 4;
};

struct RegTable {
  mem::Reg pc;
  mem::Reg cmp; // see CmpState
  mem::Reg a0;
  mem::Reg a1;

  mem::Reg lhs;
  mem::Reg rhs;
  mem::Reg dst;
};

} // namespace cpu::core
