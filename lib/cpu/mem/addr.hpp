/**
 * @file addr.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

namespace cpu::mem {

/**
 * This class serves as a box for raw adresses. The only thing it adds to a
 * simple integer formatted adress is the "safety" : when constructing the
 * object, we assert the validity of the adress.
 */
class Addr {
private:
  int raw_addr_;

public:
  Addr() = default;

  Addr(Addr &&other);
  Addr &operator=(Addr &&other);

  Addr(Addr const &other);
  Addr &operator=(Addr const &other);

  /**
   * Constructs an address box from a raw address.
   *
   * @param raw_addr
   * @return Addr
   */
  static Addr from(int raw_addr);

  /**
   * Constructs a default address.
   *
   * @return Addr
   */
  static Addr def();

public:
  /**
   * Gets the raw address contained in the box.
   *
   * @return int
   */
  int get() const;
};

} // namespace cpu::mem
