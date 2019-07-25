#include "Data/Headers/IntervalData.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/SeriesNumberOperation.h"
#include "Results/Headers/ListResult.h"
#include "Results/Implementations/ListResult.cpp"

SeriesNumberOperation::SeriesNumberOperation( ) :
  ISeriesOperation( )
{
}

std::string SeriesNumberOperation::Present( ) const
{
  return std::string( "Prime Numbers" );
}

IResultSptr SeriesNumberOperation::Execute( IDataSptr asp_data ) const
{
  auto sp_to_return = ListResult< long long unsigned int >::NewSptr( );

  auto sp_interval = std::dynamic_pointer_cast<IntervalData>( asp_data );

  if( sp_interval && sp_interval->IsValid( ) )
  {
    auto preliminary_list_result = SeriesOrigin( );

    while( sp_interval->LastValue( ) > preliminary_list_result.size( ) )
    {
      AddNextSeriesNumber( preliminary_list_result );
    }

    std::vector< long long unsigned int > list_to_return(
      preliminary_list_result.begin( ) +
      ( sp_interval->FirstValue( ) - 1 ),
      preliminary_list_result.begin( ) +
      ( sp_interval->LastValue( ) - 1 ) );

    auto sp_series = std::dynamic_pointer_cast
      <ListResult< long long unsigned int >>( sp_to_return );

    if( sp_series )
    {
      sp_series->SetList( list_to_return );
    }
  }

  return sp_to_return;
}

void SeriesNumberOperation::AddNextSeriesNumber(
  std::vector<long long unsigned int>& ar_series ) const
  noexcept( false )
{
  auto old_size = ar_series.size( );

  AddNextSeriesNumberSpecific( ar_series );

  if( old_size >= ar_series.size( ) )
  {
    throw OperationException( "Wrong series operation AddNextSeriesNumber"
                              " implementation, no element could be added"
                              " to the series.", __func__ );
  }
}