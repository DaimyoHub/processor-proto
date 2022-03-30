/**
 * @file branch.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/context.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/reg.hpp>

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

/**
 * Branch : Branch to another section of the code.
 *
 * Spec : branch to addr
 */
struct Br {
  mem::Addr addr_;
  int consume_hint = 1;

  static Br prepare(mem::Addr addr);

  void operator()(core::Ctx &ctx);

  void impl(mem::Byte pc_handle, std::size_t bytes_count);
};

/**
 * Call : Call a function.
 *
 * Spec : save context & branch to addr
 */
struct Call {
  int consume_hint = 1;

  static Call prepare(mem::Addr addr);

  void operator()(core::Ctx &ctx);
};

/**
 * Return : Return from the current called section to the caller section.
 *
 * Spec : restitute context & branch to caller section
 */
struct Ret {
  int consume_hint = 1;

  static Ret prepare();

  void operator()(core::Ctx &ctx);
};

/**
 * Branch (if) EQual : Branch to another section of the code if the content of a
 * register is equal to a given value.
 *
 * Spec : if lhs.content = rhs.content -> branch to addr
 */
struct Beq {
  int consume_hint = 1;

  static Beq prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx);
};

/**
 * Branch (if) Not Equal : Branch to another section of the code if the content
 * of a register is not equal to a given value.
 *
 * Spec : if lhs.content != rhs.content -> branch to addr
 */
struct Bne {
  int consume_hint = 1;

  static Bne prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx);
};

/**
 * Branch (if) Greater : Branch to another section of the code if the content of
 * a register is greater than a given value.
 *
 * Spec : if lhs.content > rhs.content -> branch to addr
 */
struct Bg {
  int consume_hint = 1;

  static Bg prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx);
};

/**
 * Branch (if) Smaller : Branch to another section of the code if the content of
 * a register is smaller than a given value.
 *
 * Spec : if lhs.content < lhs.content -> branch to addr
 */
struct Bs {
  int consume_hint = 1;

  static Bs prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx);
};

} // namespace cpu::isa
