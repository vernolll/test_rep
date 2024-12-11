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

bool test_full_size_equal_low_high()
{
    // ����: ���� low � high ��������� (���� ����� �� ����������).
    Candle candle(10.0, 10.0, 10.0, 10.0);
    return candle.full_size() == 0.0;  // ������ ������� true, ���� ������ ����� ����� 0.
}

bool test_full_size_low_less_than_high()
{
    // ����: ���� low ������ ���� high.
    Candle candle(5.0, 15.0, 5.0, 10.0);
    return candle.full_size() == 10.0;  // ������ ������� true, ���� ������ ����� ����� 10.
}

bool test_full_size_high_less_than_low()
{
    // ����: ���� high ������ ���� low.
    Candle candle(15.0, 5.0, 15.0, 10.0);  // high � low ������ ���� 15.0 � 5.0 ��������������
    return candle.full_size() == 10.0;  // ������ ������� true, ��� ��� ������� = 15.0 - 5.0 = 10.0
}

bool test_body_size_equal_open_close()
{
    // ����: open � close �����, ���� ����� ����� 0.
    Candle candle(10.0, 15.0, 8.0, 10.0);  // ���� ����� ����� 0
    return candle.body_size() == 0.0;  // ������ ������� true, ��� ��� ���� ����� 0
}

bool test_body_size_green_candle()
{
    // ����: close ������ open, ����� ������� (������������� ���������).
    Candle candle(5.0, 15.0, 4.0, 10.0);  // ���� ����� ����� 10.0 (close - open = 10.0 - 5.0)
    return std::abs(candle.body_size() - 5.0) < 1e-9;  // ������ ������� true, ���� ����� 5.0
}

bool test_body_size_red_candle()
{
    // ����: open ������ close, ����� ������� (������������� ���������).
    Candle candle(15.0, 20.0, 12.0, 10.0);  // ���� ����� ����� 5.0 (open - close = 15.0 - 10.0)
    return std::abs(candle.body_size() - 5.0) < 1e-9;  // ������ ������� true, ���� ����� 5.0
}

bool test_is_red_candle()
{
    // ����: ����� �������, ����� open > close
    Candle candle(15.0, 20.0, 10.0, 5.0);  // open = 15.0, close = 5.0 (������� �����)
    return candle.is_red();  // ������ ������� true, ��� ��� ����� �������
}

bool test_is_red_no_change()
{
    // ����: ����� ��� ���������, ����� open == close
    Candle candle(10.0, 20.0, 5.0, 10.0);  // open = close = 10.0 (��� ���������, �� �������)
    return !candle.is_red();  // ������ ������� true, ��� ��� ����� �� ������� (���� �� �����)
}

bool test_is_red_green_candle()
{
    // ����: ����� �������, ����� close > open
    Candle candle(5.0, 15.0, 4.0, 10.0);  // open = 5.0, close = 10.0 (������� �����)
    return !candle.is_red();  // ������ ������� true, ��� ��� ����� �� �������
}

bool test_is_green_candle()
{
    // ����: ����� �������, ����� close > open
    Candle candle(5.0, 20.0, 3.0, 10.0);  // open = 5.0, close = 10.0 (������� �����)
    return candle.is_green();  // ������ ������� true, ��� ��� ����� �������
}

bool test_is_green_no_change()
{
    // ����: ����� ��� ���������, ����� open == close
    Candle candle(10.0, 20.0, 5.0, 10.0);  // open = close = 10.0 (��� ���������, �� �������)
    return !candle.is_green();  // ������ ������� true, ��� ��� ����� �� ������� (���� �� �������)
}

bool test_is_green_red_candle()
{
    // ����: ����� �������, ����� open > close
    Candle candle(15.0, 20.0, 12.0, 10.0);  // open = 15.0, close = 10.0 (������� �����)
    return !candle.is_green();  // ������ ������� true, ��� ��� ����� �� �������
}