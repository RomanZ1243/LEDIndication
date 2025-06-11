# LEDIndication
LEDIndication - легкая бибилотека для светодиодных индикаторов без микросхем, работающих по типу динамической индикации

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

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Распиновка](#data)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
  
<a id="install"></a>
## Установка
- [Скачать библиотеку](https://github.com/RomanZ1243/LEDIndication/archive/refs/heads/main.zip) .zip архивом
- Запустить приложение Arduino IDE
- Нажать: Скетч -> Подключить библиотеку -> Добавить .ZIP библиотеку
- Выбрать скаченный .zip архив

### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи

<a id="data"></a>
## Распиновка
![Распиновка Segment](https://github.com/RomanZ1243/image/blob/main/Segment.png)
![Распиновка Segment4](https://github.com/RomanZ1243/image/blob/main/Segment%20%D1%80%D0%B0%D1%81%D0%BF%D0%B8%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0.jpg)

![Распиновка Matrix](https://github.com/RomanZ1243/image/blob/main/Matrix%20%D1%80%D0%B0%D1%81%D0%BF%D0%B8%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0.png)

> Распиновка на картинках выше может отличаться от вашего светодиодного индикатора

<a id="init"></a>
## Инициализация
```cpp
// типы индикатора:
SEVSEGMENT - семисегментный индикатор
MATRIX - светодиодная матрица

// _signal - сигнал (0 или 1), который нужно подать на пины y, чтобы сегмент загорелся

Indication(typeMatrix type, byte x_num, byte y_num, byte *_x_pin, byte *_y_pin, byte _signal = 1);  // создание объекта (тип индикатора, количество слоев, количество светодиодов в слое, массив с пинами слоев, массив с пинами светодиодов, сигнал для работы светодиодов)
Indication(typeMatrix type, byte *_x_pin, byte _signal = 1);    // для одиночного семисегментного индиктора (SEVSEGMENT, пины индикатора (8 пинов),  сигнал для работы светодиодов)
```

<a id="usage"></a>
## Использование
```cpp
// общие функции
void clear(byte index = 4);   // очистить дисплей (выбор индекса работает только на четырехразрядном семисегментном индикаторе)
void clear_matrix();          // очистить дисплей (не очищая массив)
void fill();                  // полностью зажечь дисплей
void fill_matrix();           // полностью зажечь дисплей (не заполняя массив)
void update();                // обновление дисплея
void layer(byte x1);          // включаем один слой
void getMatrix();             // получить массив матрицы
void setSpeed(byte mill);     // скорость обновления дисплея (по умолчанию 2 мс)
void setEnable(boolean _enable);    // включить/выключить светодиодный индикатор
void delayUpdate(uint16_t millisecond);   // задержка с update
void number(byte num, byte typeText = 0, boolean en = 1);   // нарисовать цифру (цифра, тип шрифта (работает только на матрицах, на семисегментных индикаторах это enable), enable)

// матрица
// далее fill:
CLEAR - очистить рамку фигуры
STROKE - нарисовать рамку фигуры
CLEAR_FILL - очистить всю область фигуры
STROKE_FILL - залить фигуру

void dot(byte x, byte y, boolean en = 1);                 // нарисовать точку
void lineH(byte y, byte x0, byte x1, boolean en = 1);     // нарисовать горизонтальную линию
void lineV(byte x, byte y0, byte y1, boolean en = 1);     // нарисовать вертикальную линию
void rect(byte x0, byte y0, byte x1, byte y1, byte fill = 1); // нарисовать прямоугольник
void invert();                                            // инвертировать матрицу
void setCursor(byte ang_x, byte ang_y);                   // установить курсор для текста (левый верхний угол)
void setRotation(byte side = 0);                          // повернуть матрицу (0 - 3)

// семисегментный индикатор
void segment(byte seg, boolean en = 1);                   // зажечь один сегмент (сегмент)
void segment4(byte seg, byte digit = 0, boolean en = 1);  // зажечь один сегмент на четырехразрядном индикаторе (сегмент, индекс цифры)  
void digit(long num, boolean zero = 0);                   // вывести число (для четырехразрядного) 
```

<a id="example"></a>
## Примеры
### Семисегментный индикатор
```cpp
#include <LEDIndication.h>

byte pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

Indication disp(SEVSEGMENT, pins);

void setup() {

}

void loop() {
  // выводим цифры от 0 до 9
  for (int i = 0; i < 10; i++) {
    disp.number(i);
    delay(400);
  }
  disp.clear();

  // заполняем по одному светодиоду
  for (int i = 0; i < 8; i++) {
    disp.segment(i, 1);
    delay(200);
  }
  delay(500);

  // очищаем по одному светодиоду
  for (int i = 0; i < 8; i++) {
    disp.segment(i, 0);
    delay(200);
  }
}
```

### Четырехразрядный семисегментный индикатор
```cpp
#include <LEDIndication.h>

byte dig[] = {2, 3, 4, 5};
byte seg[] = {6, 7, 8, 9, 10, 11, 12, 13};

Indication disp(SEVSEGMENT, 4, 8, dig, seg);

void setup() {

}

void loop() {
  // рисуем рамку
  disp.segment4(A, 0);
  disp.delayUpdate(100);
  disp.segment4(A, 1);
  disp.delayUpdate(100);
  disp.segment4(A, 2);
  disp.delayUpdate(100);
  disp.segment4(A, 3);
  disp.delayUpdate(100);
  disp.segment4(B, 3);
  disp.delayUpdate(100);
  disp.segment4(C, 3);
  disp.delayUpdate(100);
  disp.segment4(D, 3);
  disp.delayUpdate(100);
  disp.segment4(D, 2);
  disp.delayUpdate(100);
  disp.segment4(D, 1);
  disp.delayUpdate(100);
  disp.segment4(D, 0);
  disp.delayUpdate(100);
  disp.segment4(E, 0);
  disp.delayUpdate(100);
  disp.segment4(F, 0);
  disp.delayUpdate(500);
  disp.clear();

  // включаем элемент G на всех цифрах
  for (int i = 0; i < 4; i++) {
    disp.segment4(G, i);
  }
  disp.delayUpdate(500);
  disp.clear();

  // считаем от 0 до 1000
  for (int i = 0; i <= 1000; i += 5) {
    disp.digit(i);
    disp.delayUpdate(10);
  }
  disp.delayUpdate(500);

  // выводим 1234
  disp.number(2, 1);
  disp.delayUpdate(500);
  disp.number(3, 2);
  disp.delayUpdate(500);
  disp.number(4, 3);
  disp.delayUpdate(500);

  // выводим точки по одной
  for (int i = 0; i < 4; i++) {
    disp.segment4(DP, i);
    disp.delayUpdate(500);
  }

  // очищаем дисплей по одной цифре
  for (int i = 0; i < 4; i++) {
    disp.clear(3 - i);
    disp.delayUpdate(500);
  }
}
```

### Матрица 8*8
```cpp
#include <LEDIndication.h>

byte x_pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte y_pin[] = {10, 11, 12, 13, A0, A1, A2, A3};

Indication mtrx(MATRIX, 8, 8, x_pin, y_pin);

void setup() {

}

void loop() {
  // рисуем крест
  for (int i = 0; i < 8; i++) {
    mtrx.dot(i, i);
  }
  for (int i = 0; i < 8; i++) {
    mtrx.dot(i, 7 - i);
  }
  mtrx.delayUpdate(500);

  // уменьшаем и увеличиваем незакрашенный квадрат
  for (int i = 5; i < 8; i++) {
    mtrx.rect(8 - i, 8 - i, i - 1, i - 1, CLEAR);
    mtrx.rect(7 - i, 7 - i, i, i);
    mtrx.delayUpdate(100);
  }
  for (int i = 7; i > 2; i--) {
    mtrx.clear();
    mtrx.rect(7 - i, 7 - i, i, i);
    mtrx.delayUpdate(100);
  }
  for (int i = 5; i < 8; i++) {
    mtrx.clear();
    mtrx.rect(7 - i, 7 - i, i, i);
    mtrx.delayUpdate(100);
  }
  mtrx.delayUpdate(500);

  // заливаем квадрат
  mtrx.rect(0, 0, 7, 7, STROKE_FILL);
  mtrx.delayUpdate(500);

  // рисуем смайлик (черным)
  mtrx.lineH(0, 2, 5, 0);
  mtrx.lineH(5, 3, 4, 0);
  mtrx.lineH(7, 2, 5, 0);
  mtrx.lineV(0, 2, 5, 0);
  mtrx.lineV(7, 2, 5, 0);
  mtrx.dot(1, 1, 0);
  mtrx.dot(6, 6, 0);
  mtrx.dot(1, 6, 0);
  mtrx.dot(6, 1, 0);
  mtrx.dot(2, 4, 0);
  mtrx.dot(5, 4, 0);
  mtrx.dot(2, 2, 0);
  mtrx.dot(5, 2, 0);
  mtrx.delayUpdate(500);

  // инвертируем изображение
  mtrx.invert();

  // крутим изображение по часовой стрелке
  for (int i = 0; i < 4; i++) {
    mtrx.setRotation(i);
    mtrx.delayUpdate(500);
  }
  mtrx.setRotation(0);
  mtrx.delayUpdate(500);

  // рисуем квадрат и уменьшаем его
  mtrx.rect(0, 0, 7, 7);
  mtrx.delayUpdate(100);
  for (int i = 6; i > 2; i--) {
    mtrx.rect(6 - i, 6 - i, i + 1, i + 1, CLEAR);
    mtrx.rect(7 - i, 7 - i, i, i);
    mtrx.delayUpdate(100);
  }

  // плавно рисуем крест
  for (int i = 5; i < 8; i++) {
    mtrx.dot(7 - i, 7 - i);
    mtrx.dot(i, i);
    mtrx.dot(7 - i, i);
    mtrx.dot(i, 7 - i);
    mtrx.delayUpdate(100);
  }
}
```

> Остальные примеры смотри в examples

<a id="versions"></a>
## Версии
- v1.0 - релиз