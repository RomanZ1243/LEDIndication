#include <LEDIndication.h>

byte x_pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte y_pin[] = {10, 11, 12, 13, A0, A1, A2, A3};

Indication mtrx(MATRIX, 8, 8, x_pin, y_pin);

void setup() {

}

void loop() {
  // считаем от 0 до 20 маленьким шрифтом
  for (int i = 0; i < 21; i++) {
    mtrx.clear();
    mtrx.setCursor(0, 2);
    mtrx.number(i / 10);
    mtrx.setCursor(4, 2);
    mtrx.number(i % 10);
    mtrx.delayUpdate(100);
  }
  mtrx.delayUpdate(500);

  // считаем от 0 до 4 средним шрифтом, рисуем белым по черному
  mtrx.setCursor(1, 1);
  for (int i = 0; i < 5; i++) {
    mtrx.clear();
    mtrx.number(i, 1);
    mtrx.delayUpdate(200);
  }
  mtrx.delayUpdate(500);

  //рисуем черным по белому
  mtrx.fill();
  mtrx.number(4, 1, 0);
  mtrx.delayUpdate(500);

  // считаем от 5 до 9 средним шрифтом, рисуем черным по белому
  for (int i = 5; i < 10; i++) {
    mtrx.fill();
    mtrx.number(i, 1, 0);
    mtrx.delayUpdate(400);
  }
  mtrx.delayUpdate(500);

  // считаем от 0 до 9 большим шрифтом
  for (int i = 0; i < 10; i++) {
    mtrx.clear();
    mtrx.number(i, 2);
    mtrx.delayUpdate(400);
  }
  mtrx.delayUpdate(500);
}
