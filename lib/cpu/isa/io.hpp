/**
 * @file io.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-04-13
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/ctx.hpp>
#include <cpu/mem/byte.hpp>

namespace cpu::isa {

/**
 * Load : Loads the given value in the given register
 *
 * Spec : ld reg, val
 */
struct Ld {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Ld prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg, int val);

  void _exc_impl(mem::Byte reg, int val);
};

/**
 * Store : Stores the given value to the given memory cell.
 *
 * Spec : str mem, val
 */
struct Str {
  core::Ctx &ctx;
  int consume_hint = 2;

  static Str prepare(core::Ctx &ctx);

  void operator()(mem::Byte mem, int val);

  void _exc_impl(mem::Byte mem, int val);
};

} // namespace cpu::isa
