/**
 * @file instr.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/context.hpp>
#include <cpu/mem/reg.hpp>

namespace cpu::isa {

/**
 * This is an interface that allows to execute an instruction.
 */
struct Instr {
  virtual ~Instr() = default;

  virtual void operator()(core::Ctx &ctx) = 0;
};

} // namespace cpu::isa
