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


bool test_contains_price_within_range()
{
    // Свеча: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // Тест: цена внутри диапазона (цена = 12.0)
    return candle.contains(12.0) == true;
}

bool test_contains_price_below_low()
{
    // Свеча: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // Тест: цена меньше минимума диапазона (цена = 4.0)
    return candle.contains(4.0) == false;
}

bool test_contains_price_above_high()
{
    // Свеча: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // Тест: цена больше максимума диапазона (цена = 21.0)
    return candle.contains(21.0) == false;
}

bool test_full_size_equal_low_high()
{
    // Тест: Цена low и high одинаковы (цена свечи не изменяется).
    Candle candle(10.0, 10.0, 10.0, 10.0);
    return candle.full_size() == 0.0;  // Должен вернуть true, если размер свечи равен 0.
}

bool test_full_size_low_less_than_high()
{
    // Тест: Цена low меньше цены high.
    Candle candle(5.0, 15.0, 5.0, 10.0);
    return candle.full_size() == 10.0;  // Должен вернуть true, если размер свечи равен 10.
}

bool test_full_size_high_less_than_low()
{
    // Тест: Цена high меньше цены low.
    Candle candle(15.0, 5.0, 15.0, 10.0);  // high и low должны быть 15.0 и 5.0 соответственно
    return candle.full_size() == 10.0;  // Должен вернуть true, так как разница = 15.0 - 5.0 = 10.0
}

bool test_body_size_equal_open_close()
{
    // Тест: open и close равны, тело свечи равно 0.
    Candle candle(10.0, 15.0, 8.0, 10.0);  // Тело свечи равно 0
    return candle.body_size() == 0.0;  // Должно вернуть true, так как тело равно 0
}

bool test_body_size_green_candle()
{
    // Тест: close больше open, свеча зеленая (положительное изменение).
    Candle candle(5.0, 15.0, 4.0, 10.0);  // Тело свечи равно 10.0 (close - open = 10.0 - 5.0)
    return std::abs(candle.body_size() - 5.0) < 1e-9;  // Должно вернуть true, тело равно 5.0
}

bool test_body_size_red_candle()
{
    // Тест: open больше close, свеча красная (отрицательное изменение).
    Candle candle(15.0, 20.0, 12.0, 10.0);  // Тело свечи равно 5.0 (open - close = 15.0 - 10.0)
    return std::abs(candle.body_size() - 5.0) < 1e-9;  // Должно вернуть true, тело равно 5.0
}

bool test_is_red_candle()
{
    // Тест: Свеча красная, когда open > close
    Candle candle(15.0, 20.0, 10.0, 5.0);  // open = 15.0, close = 5.0 (красная свеча)
    return candle.is_red();  // Должен вернуть true, так как свеча красная
}

bool test_is_red_no_change()
{
    // Тест: Свеча без изменения, когда open == close
    Candle candle(10.0, 20.0, 5.0, 10.0);  // open = close = 10.0 (нет изменения, не красная)
    return !candle.is_red();  // Должен вернуть true, так как свеча не красная (цена не упала)
}

bool test_is_red_green_candle()
{
    // Тест: Свеча зеленая, когда close > open
    Candle candle(5.0, 15.0, 4.0, 10.0);  // open = 5.0, close = 10.0 (зеленая свеча)
    return !candle.is_red();  // Должен вернуть true, так как свеча не красная
}

bool test_is_green_candle()
{
    // Тест: Свеча зеленая, когда close > open
    Candle candle(5.0, 20.0, 3.0, 10.0);  // open = 5.0, close = 10.0 (зеленая свеча)
    return candle.is_green();  // Должен вернуть true, так как свеча зеленая
}

bool test_is_green_no_change()
{
    // Тест: Свеча без изменения, когда open == close
    Candle candle(10.0, 20.0, 5.0, 10.0);  // open = close = 10.0 (нет изменения, не зеленая)
    return !candle.is_green();  // Должен вернуть true, так как свеча не зеленая (цена не выросла)
}

bool test_is_green_red_candle()
{
    // Тест: Свеча красная, когда open > close
    Candle candle(15.0, 20.0, 12.0, 10.0);  // open = 15.0, close = 10.0 (красная свеча)
    return !candle.is_green();  // Должен вернуть true, так как свеча не зеленая
}