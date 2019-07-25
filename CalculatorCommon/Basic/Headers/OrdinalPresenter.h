#pragma once

#include <string>

class OrdinalPresenter
{
public:

  OrdinalPresenter( ) noexcept = default;

  virtual ~OrdinalPresenter( ) noexcept = default;

  std::string OrdinalSuffix( unsigned int a_ordinal ) const noexcept;

  std::string ToOrdinal( unsigned int a_num ) const noexcept;

protected:

private:

  explicit OrdinalPresenter( const OrdinalPresenter& ar_presenter ) noexcept = default;

  OrdinalPresenter& operator = ( const OrdinalPresenter& ar_presenter ) noexcept = default;
};
