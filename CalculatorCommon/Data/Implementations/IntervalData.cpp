#include "Basic/Headers/OrdinalPresenter.h"
#include "Data/Headers/IntervalData.h"

IntervalData::IntervalData( unsigned int a_first_value, unsigned int a_number_of_values ) :
  IData( ),
  _first_value( a_first_value ),
  _number_of_values( a_number_of_values )
{
}

IDataSptr IntervalData::NewSptr( unsigned int a_first_value, unsigned int a_number_of_values )
{
  return IDataSptr( new IntervalData( a_first_value, a_number_of_values ) );
}

std::string IntervalData::Present( )
{
  std::string to_return( "From the " );

  OrdinalPresenter presenter;

  to_return += presenter.ToOrdinal( _first_value );
  to_return += " to the ";
  to_return += presenter.ToOrdinal( _first_value - 1 + _number_of_values );

  return to_return;
}

unsigned int IntervalData::FirstValue( ) const
{
  return _first_value;
}

unsigned int IntervalData::NumberOfValues( ) const
{
  return _number_of_values;
}