#pragma once

#include "Data/Interfaces/IData.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Results/Interfaces/IResult.h"

class IntervalData : public virtual IData
{
public:

  static IDataSptr NewSptr( unsigned int a_first_value,
                            unsigned int a_number_of_values );

  virtual ~IntervalData( ) = default;

  virtual std::string Present( ) const override;

  virtual bool IsValid( ) const override;

  unsigned int FirstValue( ) const;

  unsigned int NumberOfValues( ) const;

  unsigned int LastValue( ) const;

protected:

  IntervalData( unsigned int a_first_value = 0,
                unsigned int a_number_of_values = 0 );

private:

  unsigned int _first_value = 0;

  unsigned int _number_of_values = 0;
};
