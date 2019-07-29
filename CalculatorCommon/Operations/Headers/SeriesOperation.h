#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include "Operations/Interfaces/ISeriesOperation.h"
#include "Results/Interfaces/IResultSptr.h"

class SeriesOperation : public virtual ISeriesOperation
{
public:

  virtual ~SeriesOperation( ) noexcept = default;

  virtual std::string Present( ) const noexcept override;

  virtual IResultSptr Execute( IDataSptr asp_data ) const noexcept( false )
    override final;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< unsigned long long >& ar_series ) const noexcept( false ) = 0;

  void AddNextSeriesNumber(
    std::vector< unsigned long long >& ar_series ) const
    noexcept( false ) override final;

protected:

  SeriesOperation( ) noexcept;

private:

  explicit SeriesOperation( const SeriesOperation& ar_operation )
    noexcept = default;

  SeriesOperation& operator = ( const SeriesOperation& ar_operation )
    noexcept = default;
};
