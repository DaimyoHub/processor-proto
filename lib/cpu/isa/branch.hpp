/**
 * @file branch.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/ctx.hpp>
#include <cpu/mem/addr.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/reg.hpp>

namespace cpu::isa {

/**
 * Branch : Branch to another section of the code.
 *
 * Spec : branch to addr
 */
struct Br {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Br prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr);

  void _exc_impl(mem::Addr addr);
};

/**
 * Call : Call a function.
 *
 * Spec : save ctx & branch to addr
 */
struct Call {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Call prepare(core::Ctx &ctx);

  void reg();
  void val(mem::Addr addr);

  void _exc_impl(mem::Addr addr);
};

/**
 * Return : Return from the current called section to the caller section.
 *
 * Spec : restitute ctx & branch to caller section
 */
struct Ret {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Ret prepare(core::Ctx &ctx);

  void exc();
};

} // namespace cpu::isa
