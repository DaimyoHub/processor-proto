/**
 * @file reg.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-29
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <cstddef>
#include <string>

namespace cpu::mem {

class ROByte;
class Byte;

class Reg {
private:
  int value_;
  std::string description_;
  std::string label_;

public:
  /**
   * Constructs a register with the given label and a default null contained
   * value.
   *
   * @param label The label of the register
   * @return Reg
   */
  static Reg with_label(std::string_view label);

  Reg() = default;

  Reg(Reg &&other);
  Reg &operator=(Reg &&other);

  Reg(Reg const &other) = delete;
  Reg &operator=(Reg const &other) = delete;

public:
  /**
   * Gets the content of the register as a byte box.
   *
   * @return ROByte
   */
  ROByte get() const;

  /**
   * @see ROByte cpu::mem::Reg::get() const
   *
   * @return Byte
   */
  Byte get();

  /**
   * Gets the description of the register.
   *
   * @return std::string const&
   */
  std::string const &get_description() const;

  /**
   * @see std::string const& cpu::mem::Reg::get_description() const
   *
   * @return std::string&
   */
  std::string &get_description();

  /**
   * Gets the label of the register.
   *
   * @return std::string const&
   */
  std::string const &get_label() const;

  /**
   * @see std::string const& cpu::mem::Reg::get_label() const
   *
   * @return std::string&
   */
  std::string &get_label();

  /**
   * Sets the description of the register.
   *
   * @param desc The description.
   */
  void describe(std::string desc);
};

} // namespace cpu::mem
