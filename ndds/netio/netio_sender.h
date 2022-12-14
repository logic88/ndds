// -*- C++ -*-
/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef value_writer_generator_H
#define value_writer_generator_H

#include "dds_generator.h"

class value_writer_generator : public dds_generator {
public:
  bool gen_enum(AST_Enum*, UTL_ScopedName* name,
                const std::vector<AST_EnumVal*>& contents, const char* repoid);

  bool gen_typedef(AST_Typedef*, UTL_ScopedName*, AST_Type*, const char*);

  bool gen_struct(AST_Structure* node, UTL_ScopedName* name,
                  const std::vector<AST_Field*>& fields,
                  AST_Type::SIZE_TYPE size, const char* repoid);

  bool gen_union(AST_Union*, UTL_ScopedName*, const std::vector<AST_UnionBranch*>&,
                 AST_Type*, const char*);
};

#endif
