cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

# ”казываем каталог с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR})

# ”казываем исходные файлы
add_executable(${PROJECT_NAME} main.cpp candle.cpp "tests.h" "tests.cpp")
