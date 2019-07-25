#pragma once

#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Interfaces/IOperationSptr.h"
#include "Operations/Interfaces/ISeriesOperation.h"
#include "Results/Interfaces/IResultSptr.h"

class SeriesNumberOperation : public virtual ISeriesOperation
{
public:

  virtual ~SeriesNumberOperation( ) = default;

  virtual std::string Present( ) const override;

  virtual IResultSptr Execute( IDataSptr asp_data ) const override final;

  virtual void AddNextSeriesNumberSpecific(
    std::vector< long long unsigned int >& ar_series ) const = 0;

  void AddNextSeriesNumber(
    std::vector< long long unsigned int >& ar_series ) const
    noexcept( false ) override final;

protected:

  SeriesNumberOperation( );

private:
};
