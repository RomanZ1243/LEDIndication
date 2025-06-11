#include "LEDIndication.h"
#include "number.h"

//---ИНИЦИАЛИЗАЦИЯ---
// создание объекта
Indication::Indication(typeMatrix type, byte x_num, byte y_num, byte *_x_pin, byte *_y_pin, boolean _signal) {
  x_max = x_num;
  y_max = y_num;
  _type = type;
  signal = _signal;
  switch (_type) {
    case SEVSEGMENT:
      type1 = 1;
      break;
    case MATRIX:
      type1 = 2;
      break;
  }
  if (type1 > 0) {
    for (int i = 0; i < x_max; i++) {
      x_pin[i] = _x_pin[i];
    }
    for (int i = 0; i < y_max; i++) {
      y_pin[i] = _y_pin[i];
    }
    for (int i = 0; i < x_max; i++) {
      pinMode(x_pin[i], OUTPUT);
    }
    for (int i = 0; i < y_max; i++) {
      pinMode(y_pin[i], OUTPUT);
    }
  }
}

// для одиночного семисегментного индиктора
Indication::Indication(typeMatrix type, byte *_x_pin, boolean _signal) {
  _type = type;
  x_max = 8;
  signal = _signal;
  if (_type == SEVSEGMENT) {
    type1 = 0;
    for (int i = 0; i < x_max; i++) {
      x_pin[i] = _x_pin[i];
    }
    for (int i = 0; i < x_max; i++) {
      pinMode(x_pin[i], OUTPUT);
    }
  }

}

//---ОБЩИЕ---
// очистить дисплей
void Indication::clear(byte index) {  // очистить дисплей
  if (type1 == 0) {
    for (int i = 0; i < x_max; i++) {
      digitalWrite(x_pin[i], !signal);
    }
  }
  else {
    if (index < 4 && type1 == 1) {
      for (int j = 0; j < y_max; j++) {
        matrix[index][j] = 0;
      }
    }
    else if (type1 == 1) {
      for (int i = 0; i < x_max; i++) {
        for (int j = 0; j < y_max; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    else {
      for (int i = 0; i < x_max; i++) {
        for (int j = 0; j < y_max; j++) {
          matrix[j][i] = 0;
        }
      }
    }
  }
}

// очистить дисплей (не очищая массив)
void Indication::clear_matrix() {   // очистить дисплей (не очищая массив)
  for (int i = 0; i < x_max; i++) {
    digitalWrite(x_pin[i], signal);
  }
  for (int i = 0; i < y_max; i++) {
    digitalWrite(y_pin[i], !signal);
  }
}

// полностью зажечь дисплей
void Indication::fill() {   // полностью зажечь дисплей
  if (type1 == 0) {
    for (int i = 0; i < x_max; i++) {
      digitalWrite(x_pin[i], signal);
    }
  }
  else if (type1 == 1) {
    for (int i = 0; i < x_max; i++) {
      for (int j = 0; j < y_max; j++) {
        matrix[i][j] = 1;
      }
    }
  }
  else {
    for (int i = 0; i < x_max; i++) {
      for (int j = 0; j < y_max; j++) {
        matrix[j][i] = 1;
      }
    }
  }
}

// полностью зажечь дисплей (не заполняя массив)
void Indication::fill_matrix() {  // полностью зажечь дисплей (не заполняя массив)
  for (int i = 0; i < x_max; i++) {
    digitalWrite(x_pin[i], !signal);
  }
  for (int i = 0; i < y_max; i++) {
    digitalWrite(y_pin[i], signal);
  }
}

// обновление дисплея
void Indication::update() {   // обновление дисплея
  if (enable == 1) {
    if (type1 == 1) {
      for (int i = 0; i < x_max; i++) {
        layer(i);
        for (int j = 0; j < y_max; j++) {
          digitalWrite(y_pin[j], (matrix[i][j] == 1) ? signal : !signal);
        }
        delay(_mill);
        for (int j = 0; j < y_max; j++) {
          digitalWrite(y_pin[j], !signal);
        }
      }
    }
    else {
      for (int i = 0; i < x_max; i++) {
        layer(i);
        for (int j = 0; j < y_max; j++) {
          digitalWrite(y_pin[j], (signal == 1) ? rotation(i, j) : !rotation(i, j));
        }
        delay(_mill);
        for (int j = 0; j < y_max; j++) {
          digitalWrite(y_pin[j], !signal);
        }
      }
    }
  }
  else {
    clear_matrix();
    delay(2 * x_max);
  }
}

// включаем один слой
void Indication::layer(byte x1) {   // включаем один слой
  if (type1 == 1) {
    for (int i = 0; i < x_max; i++) {
      digitalWrite(x_pin[i], (x1 == i) ? !signal : signal);
    }
  }
  else {
    for (int i = 0; i < x_max; i++) {
      digitalWrite(x_pin[i], (signal == 1) ? !(x1 == i) : (x1 == i));
    }
  }
}

// получить массив матрицы
void Indication::getMatrix() {    // получить массив матрицы
  if (type1 == 1) {
    for (int i = 0; i < x_max; i++) {
      for (int j = 0; j < y_max; j++) {
        Serial.print(matrix[i][j]);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
  else if (type1 == 2) {
    for (int i = 0; i < y_max; i++) {
      for (int j = 0; j < x_max; j++) {
        Serial.print(matrix[i][j]);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
  Serial.println();
}

void Indication::setSpeed(byte mill) {
  _mill = mill;
}

// включить/выключить светодиодный индикатор
void Indication::setEnable(boolean _enable) { // включить/выключить светодиодный
  enable = _enable;
}

// задержка с update
void Indication::delayUpdate(uint16_t mill) {
  uint16_t a = 0;
  uint16_t limit = 0;
  if (mill / (_mill * x_max) >= 1) {
    limit = mill / (_mill * x_max);
  }
  else {
    limit = 1;
  }
  while (a < limit) {
    a++;
    update();
    delay(1);
  }
}

//---МАТРИЦА---
// нарисовать точку
void Indication::dot(byte x, byte y, boolean en) {    // добавляем координаты точки в массив
  matrix[y][x] = en;
}

// нарисовать горизонтальную линию
void Indication::lineH(byte y, byte x0, byte x1, boolean en) {    // рисуем горизонтальную линию
  swap(x0, x1);
  for (int x = x0; x <= x1; x++) {
    dot(x, y, en);
  }
}

// нарисовать вертикальную линию
void Indication::lineV(byte x, byte y0, byte y1, boolean en) {    // рисуем вертикальную линию
  swap(y0, y1);
  for (int y = y0; y <= y1; y++) {
    dot(x, y, en);
  }
}

// нарисовать прямоугольник
void Indication::rect(byte x0, byte y0, byte x1, byte y1, byte fill) {    // рисуем прямоугольник
  swap(x0, x1);
  swap(y0, y1);
  if (fill < 2) {
    lineH(y0, x0 + 1, x1 - 1, fill);
    lineH(y1, x0 + 1, x1 - 1, fill);
    lineV(x0, y0, y1, fill);
    lineV(x1, y0, y1, fill);
  }
  else {
    for (int y = y0; y <= y1; y++) {
      lineH(y, x0, x1, fill - 2);
    }
  }
}

// инвертировать матрицу
void Indication::invert() {
  if (type1 == 2) {
    for (int i = 0; i < y_max; i++) {
      for (int j = 0; j < x_max; j++) {
        matrix[i][j] = !matrix[i][j];
      }
    }
  }
}

// установить курсор для текста
void Indication::setCursor(byte ang_x, byte ang_y) {
  _ang_x1 = ang_x;
  _ang_y1 = ang_y;
}

// повернуть матрицу
void Indication::setRotation(byte degr) {
  _degr = degr;
}

//---СЕМИСЕГМЕНТНЫЙ ИНДИКАТОР---
// зажечь один сегмент
void Indication::segment(byte seg, boolean en) {
  digitalWrite(x_pin[seg], (signal == 1) ? en : !en);
}

// зажечь один сегмент (для четырехразрядного)
void Indication::segment4(byte seg, byte digit, boolean en) {
  matrix[digit][seg] = en;
}

// вывести число (для четырехразрядного)
void Indication::digit(long num, boolean zero) {
  byte count = 0;
  int _num = 0;
  num = constrain(num, (-1 * pow_fast(10, x_max - 1)) + 1, pow_fast(10, x_max) - 1);
  _num = abs(num);
  while (_num > 0) {
    _num = _num / 10;
    count++;
  }
  if (num < 0) {
    if (zero) {
      segment4(G, 0);
      if (count < x_max - 1) {
        for (int i = 1; i - 1 < x_max - 1 - count; i++) {
          number(0, i);
        }
      }
    }
    else {
      for (int i = 0; i < x_max - count; i++) {
        clear(i);
      }
      segment4(G, x_max - 1 - count);
    }
  }
  else {
    if (zero && count < x_max) {
      for (int i = 0; i < x_max - count; i++) {
        number(0, i);
      }
    }
    else if (count < x_max) {
      for (int i = 0; i < x_max - count; i++) {
        clear(i);
      }
    }
  }
  num = abs(num);
  for (int i = 0; i < count; i++) {
    number((num - num / pow_fast(10, count - i) * pow_fast(10, count - i)) / pow_fast(10, count - i - 1), x_max - 1 - (count - 1) + i);
  }
}

//---СИСТЕМНЫЕ---
// сортировка чисел от меньшего к большему
void Indication::swap(byte & a, byte & b) {
  if (a > b) {
    byte c = a;
    a = b;
    b = c;
  }
}

// возведение числа base в степень exp
int Indication::pow_fast(int base, unsigned exp) {
  int result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    base *= base;
    exp >>= 1;
  }
  return result;
}

// загрузка данных в массив матрицы с учетом поворота
boolean Indication::rotation(byte x, byte y) {
  switch (_degr) {
    case 0:
      return matrix[y][x];
      break;
    case 1:
      return matrix[y_max - 1 - x][y];
      break;
    case 2:
      return matrix[y_max - 1 - y][x_max - 1 - x];
      break;
    case 3:
      return matrix[x][abs(x_max - 1 - y)];
      break;
  }
}