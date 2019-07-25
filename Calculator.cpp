// Calculator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Basic/Headers/easylogging++.h"
#include "Data/Headers/IntervalData.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/EfficientPrimeNumberOperation.h"
#include "Operations/Headers/FibonacciNumberOperation.h"
#include "Operations/Headers/OperationException.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include <iostream>

INITIALIZE_EASYLOGGINGPP

int main( )
{
  el::Configurations defaultConf;
  defaultConf.setToDefault( );

  // Values are always std::string
  defaultConf.set( el::Level::Info,
                   el::ConfigurationType::Format, "%msg" );

  // Default logger uses default configurations
  el::Loggers::reconfigureLogger( "default", defaultConf );

  LOG( INFO ) << "Hello World!\n";

  unsigned int first = 1;
  unsigned long size = 3;

  LOG( INFO ) << "First prime number to show: ";
  scanf_s( "%d", &first );

  LOG( INFO ) << "Number of prime numbers to show: ";
  scanf_s( "%d", &size );

  auto sp_data = IDataSptr( IntervalData::NewSptr( first, size ) );

  IResultSptr sp_result;

  auto sp_operation = PrimeNumberOperation::NewSptr( );

  try
  {
    sp_result = sp_operation->Execute( sp_data );
  }
  catch( const OperationException& ar_exception )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << "Error processing " + sp_operation->Present( ) + ": " +
      ar_exception.what( ) + " in " + ar_exception.where( );
    LOG( INFO ) << std::endl;
  }

  if( sp_result )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << sp_operation->Present( ) + " " +
      sp_data->Present( ) + ": " + sp_result->Present( );
    LOG( INFO ) << std::endl;

    sp_result.reset( );
  }

  sp_operation = EfficientPrimeNumberOperation::NewSptr( );

  try
  {
    sp_result = sp_operation->Execute( sp_data );
  }
  catch( const OperationException& ar_exception )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << "Error processing " + sp_operation->Present( ) + ": " +
      ar_exception.what( ) + " in " + ar_exception.where( );
    LOG( INFO ) << std::endl;
  }

  if( sp_result )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << sp_operation->Present( ) + " " +
      sp_data->Present( ) + ": " + sp_result->Present( );
    LOG( INFO ) << std::endl;

    sp_result.reset( );
  }

  sp_operation = FibonacciNumberOperation::NewSptr( );

  try
  {
    sp_result = sp_operation->Execute( sp_data );
  }
  catch( const OperationException& ar_exception )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << "Error processing " + sp_operation->Present( ) + ": " +
      ar_exception.what( ) + " in " + ar_exception.where( );
    LOG( INFO ) << std::endl;
  }

  if( sp_result )
  {
    LOG( INFO ) << std::endl;
    LOG( INFO ) << sp_operation->Present( ) + " " +
      sp_data->Present( ) + ": " + sp_result->Present( );
    LOG( INFO ) << std::endl;

    sp_result.reset( );
  }
}