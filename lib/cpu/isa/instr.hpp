/**
 * @file instr.hpp
 * @author Alexis Pocqte
 *
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

namespace cpu::isa {

/**
 * Checks if the given instruction have been consumed.
 *
 * @param instr The instruction to check
 * @return true if it have been consumed, else, false
 */
template <typename InstrT> bool is_instr_consumed(InstrT const &instr) {
  return instr.consume_hint == 0;
}

} // namespace cpu::isa
