#define ASSERT_IS_INDEX_OF(idx, ds_length)                                     \
  assert("An index can not be negative." && idx >= 0);                         \
  assert("The given index is out of range." && idx < ds_length.size())
