#include <LEDIndication.h>

byte x_pin[] = {2, 3, 4, 5, 6};
byte y_pin[] = {7, 8, 9, 10, 11, 12, 13};

Indication mtrx(MATRIX, 5, 7, x_pin, y_pin, 0);

void setup() {
  
}

void loop() {
  // рисуем крест
  for (int i = 0; i < 5; i++) {
    mtrx.dot(i, i + 1);
    mtrx.dot(i, 5 - i);
  }
  mtrx.dot(0, 0);
  mtrx.dot(4, 6);
  mtrx.dot(0, 6);
  mtrx.dot(4, 0);
  mtrx.delayUpdate(500);

  // увеличиваем незакрашенный квадрат
  mtrx.rect(2, 2, 2, 4);
  mtrx.delayUpdate(100);
  mtrx.rect(2, 2, 2, 4, CLEAR);
  mtrx.rect(1, 1, 3, 5);
  mtrx.delayUpdate(100);
  mtrx.rect(1, 1, 3, 5, CLEAR);
  mtrx.rect(0, 0, 4, 6);
  mtrx.delayUpdate(100);

  // уменьшаем незакрашенный квадрат
  mtrx.rect(0, 0, 4, 6, CLEAR);
  mtrx.rect(1, 1, 3, 5);
  mtrx.delayUpdate(100);
  mtrx.rect(1, 1, 3, 5, CLEAR);
  mtrx.lineV(2, 2, 4);
  mtrx.delayUpdate(100);

  // увеличиваем незакрашенный квадрат
  mtrx.rect(2, 2, 2, 4, CLEAR);
  mtrx.rect(1, 1, 3, 5);
  mtrx.delayUpdate(100);
  mtrx.rect(1, 1, 3, 5, CLEAR);
  mtrx.rect(0, 0, 4, 6);
  mtrx.delayUpdate(100);

  // рисуем линии (ходят вверх вниз)
  for (int i = 6; i >= 0; i--) {
    mtrx.lineH(i, 0, 4);
    mtrx.delayUpdate(100);
  }
  for (int i = 0; i < 7; i++) {
    mtrx.lineH(i, 0, 4, 0);
    mtrx.delayUpdate(100);
  }
  mtrx.delayUpdate(100);

  // плавно рисуем крест
  for (int i = 2; i < 5; i++) {
    mtrx.dot(4 - i, 5 - i);
    mtrx.dot(i, i + 1);
    mtrx.dot(4 - i, i + 1);
    mtrx.dot(i, 5 - i);
    mtrx.delayUpdate(100);
  }
}
