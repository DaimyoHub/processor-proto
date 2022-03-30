#include <cassert>

#define ASSERT_IS_INDEX_OF(idx, ds_length)                                     \
  assert("An index can not be negative." && idx >= 0);                         \
  assert("The given index is out of range." && idx < ds_length)

#define ASSERT_IS_IN_RANGE(a, b, val)                                          \
  assert("The given value is out of range (under)." && a <= val);              \
  assert("The given value is out of range (over)." && val <= b)

#define ASSERT_IS_POSITIVE(val)                                                \
  assert("The given value is not positive." && val >= 0)

#define ASSERT_IS_STRICTLY_POSITIVE(val)                                       \
  assert("The given value is not strictly positive." && val > 0)

#define ASSERT_IS_NEGATIVE(val)                                                \
  assert("The given value is not positive." && val <= 0)

#define ASSERT_IS_STRICTLY_NEGATIVE(val)                                       \
  assert("The given value is not strictly positive." && val < 0)