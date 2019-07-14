#pragma once

#include <string>

class OrdinalPresenter
{
public:

  OrdinalPresenter( ) = default;

  virtual ~OrdinalPresenter( ) = default;

  std::string OrdinalSuffix( unsigned int a_ordinal );

  std::string ToOrdinal( unsigned int a_num );
};
