/**
 * @file obs_pointer.hpp
 * @author  Alexis Pocquet
 *
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <type_traits>

namespace cpu::util {

template <typename T> using ObsPtr = T *;

}
