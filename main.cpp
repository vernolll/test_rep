#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"
#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

void initTests()
{
  tests.push_back(test_body_contains_green_candle_within_body);
  tests.push_back(test_body_contains_green_candle_outside_body);
  tests.push_back(test_body_contains_red_candle_within_body);
  tests.push_back(test_contains_price_within_range);
  tests.push_back(test_contains_price_below_low);
  tests.push_back(test_contains_price_above_high);
  tests.push_back(test_full_size_equal_low_high);
  tests.push_back(test_full_size_low_less_than_high);
  tests.push_back(test_full_size_high_less_than_low);
  tests.push_back(test_body_size_equal_open_close);
  tests.push_back(test_body_size_green_candle);
  tests.push_back(test_body_size_red_candle);
  tests.push_back(test_is_red_candle);
  tests.push_back(test_is_red_no_change);
  tests.push_back(test_is_red_green_candle);
  tests.push_back(test_is_green_candle);
  tests.push_back(test_is_green_no_change);
  tests.push_back(test_is_green_red_candle);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
