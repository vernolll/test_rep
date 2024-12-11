#include "tests.h"

bool test_body_contains_green_candle_within_body()
{
    // Бычья свеча: open = 10.0, close = 15.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // Тест: цена внутри тела свечи (цена = 12.0)
    return candle.body_contains(12.0) == true;
}

bool test_body_contains_green_candle_outside_body()
{
    // Бычья свеча: open = 10.0, close = 15.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // Тест: цена вне тела свечи (цена = 9.0)
    return candle.body_contains(9.0) == false;
}

bool test_body_contains_red_candle_within_body()
{
    // Медвежья свеча: open = 15.0, close = 10.0
    Candle candle(15.0, 20.0, 5.0, 10.0);

    // Тест: цена внутри тела свечи (цена = 12.0)
    return candle.body_contains(12.0) == true;
}
