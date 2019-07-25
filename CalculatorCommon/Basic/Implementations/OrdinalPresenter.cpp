#include "Basic/Headers/OrdinalPresenter.h"

std::string OrdinalPresenter::OrdinalSuffix( unsigned int a_ordinal ) const noexcept
{
  std::string to_return;

  auto last_digit = a_ordinal % 10;

  switch( last_digit )
  {
    case 1:
      {
        to_return = "st";
      }
      break;
    case 2:
      {
        to_return = "nd";
      }
      break;
    case 3:
      {
        to_return = "rd";
      }
      break;
    default:
      {
        to_return = "th";
      }
      break;
  }

  return to_return;
}

std::string OrdinalPresenter::ToOrdinal( unsigned int a_num ) const noexcept
{
  std::string to_return;

  to_return += std::to_string( a_num );
  to_return += OrdinalSuffix( a_num );

  return to_return;
}