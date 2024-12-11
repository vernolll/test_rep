#include "tests.h"

bool test_body_contains_green_candle_within_body()
{
    // ����� �����: open = 10.0, close = 15.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // ����: ���� ������ ���� ����� (���� = 12.0)
    return candle.body_contains(12.0) == true;
}

bool test_body_contains_green_candle_outside_body()
{
    // ����� �����: open = 10.0, close = 15.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // ����: ���� ��� ���� ����� (���� = 9.0)
    return candle.body_contains(9.0) == false;
}

bool test_body_contains_red_candle_within_body()
{
    // �������� �����: open = 15.0, close = 10.0
    Candle candle(15.0, 20.0, 5.0, 10.0);

    // ����: ���� ������ ���� ����� (���� = 12.0)
    return candle.body_contains(12.0) == true;
}


bool test_contains_price_within_range()
{
    // �����: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // ����: ���� ������ ��������� (���� = 12.0)
    return candle.contains(12.0) == true;
}

bool test_contains_price_below_low()
{
    // �����: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // ����: ���� ������ �������� ��������� (���� = 4.0)
    return candle.contains(4.0) == false;
}

bool test_contains_price_above_high()
{
    // �����: low = 5.0, high = 20.0
    Candle candle(10.0, 20.0, 5.0, 15.0);

    // ����: ���� ������ ��������� ��������� (���� = 21.0)
    return candle.contains(21.0) == false;
}
