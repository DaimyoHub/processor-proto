#include <cassert>

#define ASSERT_IS_INDEX_OF(idx, ds_length)                                     \
  assert("An index can not be negative." && idx >= 0);                         \
  assert("The given index is out of range." && idx < ds_length)

#define IS_IN_RANGE(a, b, val)                                                 \
  assert("The given value is out of range (under)." && a <= val);              \
  assert("The given value is out of range (over)." && val <= b)
