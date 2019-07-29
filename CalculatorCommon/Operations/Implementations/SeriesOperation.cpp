#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/SeriesOperation.h"
#include "Results/Headers/ListResult.h"
#include "Results/Implementations/ListResult.cpp"
#include <limits>

SeriesOperation::SeriesOperation( ) noexcept :
  ISeriesOperation( )
{
}

std::string SeriesOperation::Present( ) const noexcept
{
  return std::string( "Prime Numbers" );
}

IResultSptr SeriesOperation::Execute( IDataSptr asp_data )
const noexcept( false )
{
  auto sp_to_return = ListResult< unsigned long long >::NewSptr( );

  auto sp_interval = std::dynamic_pointer_cast<IntervalData>( asp_data );

  if( sp_interval && sp_interval->IsValid( ) )
  {
    auto preliminary_list_result = SeriesOrigin( );

    while( sp_interval->LastValue( ) > preliminary_list_result.size( ) )
    {
      AddNextSeriesNumber( preliminary_list_result );
    }

    std::vector< unsigned long long > list_to_return(
      preliminary_list_result.begin( ) +
      ( sp_interval->FirstValue( ) - 1 ),
      preliminary_list_result.begin( ) +
      ( sp_interval->LastValue( ) ) );

    auto sp_series = std::dynamic_pointer_cast
      <ListResult< unsigned long long >>( sp_to_return );

    if( sp_series )
    {
      sp_series->SetList( list_to_return );
    }
  }
  else
  {
    throw OperationException( "No valid data provided for this operation",
                              __func__ );
  }

  if( !sp_to_return || !sp_to_return->IsValid( ) )
  {
    throw OperationException( "No valid result obtained for this operation",
                              __func__ );
  }

  return sp_to_return;
}

void SeriesOperation::AddNextSeriesNumber(
  std::vector<unsigned long long>& ar_series ) const
  noexcept( false )
{
  auto old_size = ar_series.size( );

  if( old_size > std::numeric_limits< size_t >::max( ) - 1 )
  {
    throw OperationException( "Next series number cannot be contained in "
                              "the result output in this platform using "
                              "the stl basic vector", __func__ );
  }

  AddNextSeriesNumberSpecific( ar_series );

  if( old_size >= ar_series.size( ) )
  {
    throw OperationException( "Wrong series operation AddNextSeriesNumber"
                              " implementation, no element could be added"
                              " to the series.", __func__ );
  }
}