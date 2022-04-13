/**
 * @file context.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cpu/core/reg_table.hpp>
#include <cpu/mem/mem.hpp>

int main();

namespace cpu::core {

class Ctx {
private:
  mem::Mem memory_;
  mem::Mem code_;
  RegTable registers_;

public:
  /**
   * Constructs a context for a virtual machine.
   *
   * @return Ctx
   */
  static Ctx create();

  Ctx() = default;

  Ctx(Ctx &&other);
  Ctx &operator=(Ctx &&other);

  Ctx(Ctx const &other) = delete;
  Ctx &operator=(Ctx const &other) = delete;

public:
  /**
   * Gets the working memory.
   *
   * @return mem::Mem&
   */
  mem::Mem &get_mem();
  mem::Mem const &get_mem() const;

  /**
   * Gets the current executed code.
   *
   * @return mem::Mem const&
   */
  mem::Mem const &get_code() const;

  /**
   * Loads the given code into the code section of memory.
   *
   * @param code The code to load.
   */
  void load_code(mem::Mem code);

  /**
   * Gets the working registers.
   *
   * @return RegTable&
   */
  RegTable &get_reg();
  RegTable const &get_reg() const;

private:
  /**
   * Initializes registers.
   */
  void _init_registers();
};

} // namespace cpu::core