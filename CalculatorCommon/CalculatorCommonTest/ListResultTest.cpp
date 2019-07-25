#include "Basic/Headers/easylogging++.h"
#include "gtest/gtest.h"
#include "Results/Headers/ListResult.h"
#include "Results/Implementations/ListResult.cpp"
#include <string>

TEST( ListResultTestCase, ListResultTest )
{
  std::string str_list( "34, 23, 90, 89, 106" );

  std::vector<int> int_list;

  std::stringstream ss( str_list );

  while( ss.good( ) )
  {
    std::string substr;
    getline( ss, substr, ',' );
    int_list.emplace_back( std::stoi( substr ) );
  }

  auto sp_result = ListResult< int >::NewSptr( );

  auto sp_list = std::dynamic_pointer_cast<ListResult<int>>( sp_result );

  ASSERT_TRUE( sp_list );

  sp_list->SetList( int_list );

  EXPECT_EQ( sp_list->Present( ), str_list );

  EXPECT_EQ( sp_list->List( ), int_list );
}