/*
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_PRINTER_H
#define NDDS_DCPS_PRINTER_H

#ifndef NDDS_SAFETY_PROFILE

#include "dcps_export.h"

#include <iostream>

#ifndef ACE_LACKS_PRAGMA_ONCE
#  pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

/**
 * Class used to help print an IDL Type to a std::ostream. It just configures
 * the printing options and is what is used directly. The actual work is done
 * by Printable and operator<< implementations.
 *
 * Given an IDL Type T, the following will need to be generated in its
 * *TypeSupportImpl.cpp by the marshal generator:
 *   std::ostream& operator<<(const Printable& printable, const Type& value);
 *
 * Then given an object of type T called value, it can be printed to stdout
 * using:
 *   std::cout << Printer() << value;
 *
 * TODO:
 *  - Implement for more than just simple structs
 *  - Enum member names
 *  - Maybe have an inline printing option?
 *  - Maybe optionally print the IDL name of the Type?
 */
class NDDS_Dcps_Export Printer {
public:
  Printer();

  char indent_char() const;
  void indent_char(char new_value);

  unsigned indent_char_count() const;
  void indent_char_count(unsigned new_value);

  unsigned initial_indent_level() const;
  void initial_indent_level(unsigned new_value);

  bool print_field_names() const;
  void print_field_names(bool new_value);

private:
  char indent_char_;
  unsigned indent_char_count_;
  unsigned initial_indent_level_;
  bool print_field_names_;
};

/**
 * Object created from the << operator between a Printer and an IDL type.
 * Contains the all particulars of how something is going to be printed.
 */
class NDDS_Dcps_Export Printable {
public:
  Printable(
    std::ostream& os, const Printer& printer);

  std::ostream& os();
  const Printer& printer();

  void push_indent();
  void pop_indent();
  void print_indent();

private:
  std::ostream& os_;
  const Printer& printer_;
  unsigned indent_level_;
};

NDDS_Dcps_Export
Printable operator<<(std::ostream& os, const Printer& printer);

/// Default Implementation
template<typename T>
std::ostream& operator<<(Printable printable, const T& value) {
  return printable.os() << value;
}

} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif // ifndef NDDS_SAFETY_PROFILE

#endif // ifndef NDDS_DCPS_PRINTER_H
