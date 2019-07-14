#include "Basic/Headers/OrdinalPresenter.h"
#include "gtest/gtest.h"
#include <string>

TEST( OrdinalPresenterTestCase, OrdinalSuffixTest )
{
  OrdinalPresenter presenter;

  unsigned int num0 = 0;
  unsigned int num1 = 1;
  unsigned int num2 = 2;
  unsigned int num3 = 3;
  unsigned int num4 = 4;
  unsigned int num5 = 5;
  unsigned int num6 = 6;
  unsigned int num7 = 7;
  unsigned int num8 = 8;
  unsigned int num9 = 9;

  for( unsigned int multiplier = 0; multiplier < 1500; multiplier += 10 )
  {
    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num0 ) );

    EXPECT_EQ( std::string( "st" ),
               presenter.OrdinalSuffix( multiplier + num1 ) );

    EXPECT_EQ( std::string( "nd" ),
               presenter.OrdinalSuffix( multiplier + num2 ) );

    EXPECT_EQ( std::string( "rd" ),
               presenter.OrdinalSuffix( multiplier + num3 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num4 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num5 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num6 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num7 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num8 ) );

    EXPECT_EQ( std::string( "th" ),
               presenter.OrdinalSuffix( multiplier + num9 ) );
  }
}

TEST( OrdinalPresenterTestCase, ToOrdinalTest )
{
  OrdinalPresenter presenter;

  unsigned int num0 = 0;
  unsigned int num1 = 1;
  unsigned int num2 = 2;
  unsigned int num3 = 3;
  unsigned int num4 = 4;
  unsigned int num5 = 5;
  unsigned int num6 = 6;
  unsigned int num7 = 7;
  unsigned int num8 = 8;
  unsigned int num9 = 9;

  for( unsigned int multiplier = 0; multiplier < 1500; multiplier += 10 )
  {
    EXPECT_EQ( std::string( std::to_string( multiplier + num0 ) + "th" ),
               presenter.ToOrdinal( multiplier + num0 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num1 ) + "st" ),
               presenter.ToOrdinal( multiplier + num1 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num2 ) + "nd" ),
               presenter.ToOrdinal( multiplier + num2 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num3 ) + "rd" ),
               presenter.ToOrdinal( multiplier + num3 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num4 ) + "th" ),
               presenter.ToOrdinal( multiplier + num4 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num5 ) + "th" ),
               presenter.ToOrdinal( multiplier + num5 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num6 ) + "th" ),
               presenter.ToOrdinal( multiplier + num6 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num7 ) + "th" ),
               presenter.ToOrdinal( multiplier + num7 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num8 ) + "th" ),
               presenter.ToOrdinal( multiplier + num8 ) );

    EXPECT_EQ( std::string( std::to_string( multiplier + num9 ) + "th" ),
               presenter.ToOrdinal( multiplier + num9 ) );
  }
}