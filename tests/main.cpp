#include "printer.hpp"
#include <chrono>
#include <cpu/core/context.hpp>
#include <cpu/core/reg_table.hpp>
#include <cpu/isa/branch.hpp>
#include <cpu/mem/access.hpp>
#include <cpu/mem/byte.hpp>
#include <cpu/mem/extract.hpp>
#include <cpu/mem/mem.hpp>
#include <cpu/mem/reg.hpp>
#include <cpu/util/assert.hpp>
#include <cpu/util/obs_ptr.hpp>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <type_traits>
#include <vector>

using namespace cpu;

int main() { auto ctx = core::Ctx::create(); }
