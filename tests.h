#include "candle.h"
#include <cassert>

bool test_body_contains_green_candle_within_body();
bool test_body_contains_green_candle_outside_body();
bool test_body_contains_red_candle_within_body();

bool test_contains_price_within_range();
bool test_contains_price_below_low();
bool test_contains_price_above_high();

bool test_full_size_equal_low_high();
bool test_full_size_low_less_than_high();
bool test_full_size_high_less_than_low();

bool test_body_size_equal_open_close();
bool test_body_size_green_candle();
bool test_body_size_red_candle();

bool test_is_red_candle();
bool test_is_red_no_change();
bool test_is_red_green_candle();

