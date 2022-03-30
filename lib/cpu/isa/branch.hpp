/**
 * @file branch.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/isa/instr.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/reg.hpp>

namespace cpu::isa {

/**
 * Branch : Branch to another section of the code.
 *
 * Spec : branch to addr
 */
struct Br : public Instr {
  mem::Addr addr_;

  static Br prepare(mem::Addr addr);

  void operator()(core::Ctx &ctx) override;
};

/**
 * Call : Call a function.
 *
 * Spec : save context & branch to addr
 */
struct Call : public Instr {
  static Call prepare(mem::Addr addr);

  void operator()(core::Ctx &ctx) override;
};

/**
 * Return : Return from the current called section to the caller section.
 *
 * Spec : restitute context & branch to caller section
 */
struct Ret : public Instr {
  static Ret prepare();

  void operator()(core::Ctx &ctx) override;
};

/**
 * Branch (if) EQual : Branch to another section of the code if the content of a
 * register is equal to a given value.
 *
 * Spec : if lhs.content = rhs.content -> branch to addr
 */
struct Beq : public Instr {
  static Beq prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx) override;
};

/**
 * Branch (if) Not Equal : Branch to another section of the code if the content
 * of a register is not equal to a given value.
 *
 * Spec : if lhs.content != rhs.content -> branch to addr
 */
struct Bne : public Instr {
  static Bne prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx) override;
};

/**
 * Branch (if) Greater : Branch to another section of the code if the content of
 * a register is greater than a given value.
 *
 * Spec : if lhs.content > rhs.content -> branch to addr
 */
struct Bg : public Instr {
  static Bg prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx) override;
};

/**
 * Branch (if) Smaller : Branch to another section of the code if the content of
 * a register is smaller than a given value.
 *
 * Spec : if lhs.content < lhs.content -> branch to addr
 */
struct Bs : public Instr {
  static Bs prepare(mem::Addr addr, mem::Reg const &lhs, mem::Reg const &rhs);

  void operator()(core::Ctx &ctx) override;
};

} // namespace cpu::isa
