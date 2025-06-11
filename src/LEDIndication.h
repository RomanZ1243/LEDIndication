/*
    LEDIndication - легкая бибилотека для светодиодных индикаторов без микросхем, работающих по типу динамической индикации
    Документация:
    GitHub: https://github.com/RomanZ1243/LEDIndication
    Возможности:
    - Выбор индикатора
      - Работа со светодиодными матрицами и семисегментными индикаторами
      - Ввод типа и размера индикатора вручную
      - Ввод сигнала для работы светодиодов
    - Настройки и данные
      - Включение/выключение индикатора
      - Программный поворот матрицы
      - Возможность получить массив данных, который выводится на индикатор
    - Графика
      - Точка
      - Горизонтальная линия
      - Вертикальная линия
      - Прямоугольник
    - Вывод чисел
      - Несколько шрифтов
      - Изменение положения цифр на матрице
      - Возможность выводить черные и белые цифры
      - Возможность выводить цифры отдельно на разных индексах на четырехразрядных семисегментных индикаторах

    RomanZ1243
    https://t.me/programmmmmmer
    MIT License

    Версии:
    v1.0 - релиз
*/

#pragma once
#include <Arduino.h>

#define CLEAR 0
#define STROKE 1
#define CLEAR_FILL 2
#define STROKE_FILL 3

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define DP 7

enum typeMatrix {   // тип индикатора
  SEVSEGMENT,
  MATRIX,
};

class Indication {   // класс Indication
  public:
    //---ИНИЦИАЛИЗАЦИЯ---
    Indication(typeMatrix type, byte *_x_pin, boolean _signal = 1);
    Indication(typeMatrix type, byte x_num, byte y_num, byte *_x_pin, byte *_y_pin, boolean _signal = 1);

    //---ОБЩИЕ---
    void clear(byte index = 4);   // очистить дисплей (выбор индекса работает только на четырехразрядном семисегментном индикаторе)
    void clear_matrix();          // очистить дисплей (не очищая массив)
    void fill();                  // полностью зажечь дисплей
    void fill_matrix();           // полностью зажечь дисплей (не заполняя массив)
    void update();                // обновление дисплея
    void layer(byte x1);          // включаем один слой
    void getMatrix();             // получить массив матрицы
    void setSpeed(byte mill);     // скорость обновления дисплея (по умолчанию 2 мс)
    void setEnable(boolean _enable);    // включить/выключить светодиодный индикатор
    void delayUpdate(uint16_t mill);   // задержка с update
    void number(byte num, byte typeText = 0, boolean en = 1);   // нарисовать цифру (цифра, тип шрифта (работает только на матрицах, на семисегментных индикаторах это enable), enable)

    //---МАТРИЦА---
    void dot(byte x, byte y, boolean en = 1);                 // нарисовать точку
    void lineH(byte y, byte x0, byte x1, boolean en = 1);     // нарисовать горизонтальную линию
    void lineV(byte x, byte y0, byte y1, boolean en = 1);     // нарисовать вертикальную линию
    void rect(byte x0, byte y0, byte x1, byte y1, byte fill = 1); // нарисовать прямоугольник
    void invert();                                            // инвертировать матрицу
    void setCursor(byte ang_x, byte ang_y);                   // установить курсор для текста (левый верхний угол)
    void setRotation(byte side = 0);                          // повернуть матрицу (0 - 3)

    //---СЕМИСЕГМЕНТНЫЙ ИНДИКАТОР---
    void segment(byte seg, boolean en = 1);                   // зажечь один сегмент (сегмент)
    void segment4(byte seg, byte digit = 0, boolean en = 1);  // зажечь один сегмент на четырехразрядном индикаторе (сегмент, индекс цифры)
    void digit(long num, boolean zero = 0);                   // вывести число (для четырехразрядного)
  private:
    void swap(byte & a, byte & b);                  // сортировка чисел от меньшего к большему
    int pow_fast(int base, unsigned exp);           // возведение числа base в степень exp
    boolean rotation(byte x, byte y);  // загрузка данных в массив матрицы с учетом поворота

    typeMatrix _type;   // тип светодиодного индикатора
    byte type1;         // номер типа светодиодного индикатора
    byte x_pin[16];     // массив с пинами (слои)
    byte y_pin[16];     // массив с пинами (сегменты)
    byte x_max = 0;     // количество пинов (слои)
    byte y_max = 0;     // количество пинов (сегменты)
    boolean signal; // сигнал для включения сегмента
    boolean enable = 1; // вкл/выкл светодиодный индикатор
    byte _mill = 2;
    byte _degr = 0;     // сторона поворота
    byte _ang_x;        // левый верхний угол текста
    byte _ang_y;        // левый верхний угол текста
    byte _ang_x1;       // левый верхний угол текста
    byte _ang_y1;       // левый верхний угол текста
    boolean matrix[16][16] = {    // матрица
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
    };
};
