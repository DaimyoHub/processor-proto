#include <cpu/mem/byte.hpp>
#include <cpu/mem/reg.hpp>
#include <utility>

namespace cpu::mem {

Reg Reg::with_label(std::string_view label) {
  auto reg = Reg();

  reg.value_ = 0;
  reg.description_ = std::string();
  reg.label_ = label;

  return reg;
}

Reg::Reg(Reg &&other)
    : value_(other.value_), description_(std::move(other.description_)),
      label_(std::move(other.label_)) {}

Reg &Reg::operator=(Reg &&other) {
  value_ = other.value_;
  description_ = std::move(other.description_);
  label_ = std::move(other.label_);

  return *this;
}

ROByte Reg::get() const { return ROByte::from_ptr(&value_); }

Reg::operator ROByte() const { return get(); }

Byte Reg::get() { return Byte::from_ptr(&value_); }

Reg::operator Byte() { return get(); }

std::string const &Reg::get_description() const { return description_; }

std::string &Reg::get_description() { return description_; }

std::string const &Reg::get_label() const { return label_; }

std::string &Reg::get_label() { return label_; }

void Reg::describe(std::string desc) { description_ = std::move(desc); }

} // namespace cpu::mem
