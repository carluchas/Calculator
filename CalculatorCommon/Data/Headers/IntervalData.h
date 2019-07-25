#pragma once

#include "Data/Interfaces/IData.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Results/Interfaces/IResult.h"

class IntervalData : public virtual IData
{
public:

  static IDataSptr NewSptr( unsigned int a_first_value,
                            unsigned int a_number_of_values ) noexcept;

  virtual ~IntervalData( ) noexcept = default;

  virtual std::string Present( ) const noexcept override;

  virtual bool IsValid( ) const noexcept override;

  unsigned int FirstValue( ) const noexcept;

  unsigned int NumberOfValues( ) const noexcept;

  unsigned int LastValue( ) const noexcept;

protected:

  IntervalData( unsigned int a_first_value = 0,
                unsigned int a_number_of_values = 0 ) noexcept;

private:

  unsigned int _first_value = 0;

  unsigned int _number_of_values = 0;

  explicit IntervalData( const IntervalData& ar_operation ) noexcept = default;

  IntervalData& operator = ( const IntervalData& ar_operation ) noexcept = default;
};
