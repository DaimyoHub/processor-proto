/**
 * @file br_comp.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/ctx.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/reg.hpp>

namespace cpu::isa {

/**
 * Compares lhs and lhs to return a cmp register state.
 *
 * @param lhs
 * @param rhs
 * @return int  The cmp register state.
 */
int compare_lhs_and_rhs(mem::Byte lhs, mem::Byte rhs);

/**
 * Branch (if) EQual : Branch to another section of the code if lhs is equal
 * to rhs.
 *
 * Spec : if lhs = rhs -> branch to addr
 */
struct Beq {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Beq prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

/**
 * Branch (if) Not Equal : Branch to another section of the code if lhs is not
 * equal to rhs.
 *
 * Spec : if lhs != rhs -> branch to addr
 */
struct Bne {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Bne prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

/**
 * Branch (if) Greater : Branch to another section of the code if lhs is greater
 * than rhs.
 *
 * Spec : if lhs > rhs -> branch to addr
 */
struct Bg {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Bg prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

/**
 * Branch (if) Smaller : Branch to another section of the code if lhs is smaller
 * than rhs.
 *
 * Spec : if lhs < lhs -> branch to addr
 */
struct Bs {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Bs prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

/**
 * Branch (if) Greater or Equal : Branch to another section of the code if the
 * content of lhs is greater or equal rhs.
 *
 * Spec : if lhs >= rhs -> branch to addr
 */
struct Bge {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Bge prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

/**
 * Branch (if) Smaller or Equal : Branch to another section of the code if the
 * content of lhs is smaller or equal rhs.
 *
 * Spec : if lhs <= rhs -> branch to addr
 */
struct Bse {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Bse prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);

  void _exc_impl(mem::Addr addr, mem::Byte lhs, mem::Byte rhs);
};

} // namespace cpu::isa
