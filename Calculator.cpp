// Calculator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Data/Headers/IntervalData.h"
#include "Data/Interfaces/IDataSptr.h"
#include "Operations/Headers/PrimeNumberOperation.h"
#include <iostream>

int main( )
{
  std::cout << "Hello World!\n";

  unsigned int first = 1;
  unsigned long size = 3;

  printf( "First prime number to show: " );
  scanf_s( "%d", &first );

  printf( "Number of prime numbers to show: " );
  scanf_s( "%d", &size );

  auto sp_data = IDataSptr( IntervalData::NewSptr( first, size ) );

  auto sp_operation = PrimeNumberOperation::NewSptr( );

  auto sp_result = sp_operation->Execute( sp_data );

  if( sp_result )
  {
    std::cout << std::endl;
    std::cout << sp_operation->Present( ) + " ";
    std::cout << sp_data->Present( ) + ": ";
    std::cout << sp_result->Present( );
    std::cout << std::endl;
  }
}