/**
 * @file math.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/ctx.hpp>
#include <cpu/mem/byte.hpp>

namespace cpu::isa {

/**
 * Add : Adds lhs and rhs then put the result in the given register
 *
 * Spec : add dst, lhs, rhs
 */
struct Add {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Add prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg, int lhs, int rhs);

  void _exc_impl(mem::Byte reg, int lhs, int rhs);
};

/**
 * Sub : Subs lhs and rhs then put the result in the given register
 *
 * Spec : sub dst, lhs, rhs
 */
struct Sub {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Sub prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg, int lhs, int rhs);

  void _exc_impl(mem::Byte reg, int lhs, int rhs);
};

/**
 * Multiply : Multiplies lhs and rhs then put the result in the given register
 *
 * Spec : mul dst, lhs, rhs
 */
struct Mul {
  core::Ctx &ctx;
  int consume_hint = 3;

  static Mul prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg, int lhs, int rhs);

  void _exc_impl(mem::Byte reg, int lhs, int rhs);
};

/**
 * Divide : Divides lhs and rhs then put the result in the given register
 *
 * Spec : div dst, lhs, rhs
 */
struct Div {
  core::Ctx &ctx;
  int consume_hint = 3;

  static Div prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg, int lhs, int rhs);

  void _exc_impl(mem::Byte reg, int lhs, int rhs);
};

/**
 * Increment : Increments the value contained by the given register
 *
 * Spec : inc reg
 */
struct Inc {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Inc prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg);

  void _exc_impl(mem::Byte reg);
};

/**
 * Decrement : Decrements the value contained by the given register
 *
 * Spec : dec reg
 */
struct Dec {
  core::Ctx &ctx;
  int consume_hint = 1;

  static Dec prepare(core::Ctx &ctx);

  void operator()(mem::Byte reg);

  void _exc_impl(mem::Byte reg);
};

} // namespace cpu::isa