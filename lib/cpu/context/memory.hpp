#include <cstddef>
#include <vector>

class Mem {
private:
  // The memory object is based on a simple native handle representing a
  // contiguous sequence of bytes.
  std::vector<std::byte> native_handle_;

public:
  /**
   * Constructs a memory object from a given vector.
   *
   * @param vec The source vector.
   * @return Mem
   */
  static Mem from_vec(std::vector<std::byte> vec);

  Mem() = default;

  Mem(Mem &&other);
  Mem &operator=(Mem &&other);

  Mem(Mem const &other) = delete;
  Mem operator=(Mem const &other) = delete;

public:
  /**
   * Fetches the owned data at the given index.
   *
   * @param idx The index of the location of the looked-for data.
   * @return std::byte The data looked for.
   */
  std::byte operator[](std::size_t idx) const;
  std::byte &operator[](std::size_t idx);
};
