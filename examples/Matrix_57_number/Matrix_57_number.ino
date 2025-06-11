#include <LEDIndication.h>

byte x_pin[] = {2, 3, 4, 5, 6};
byte y_pin[] = {7, 8, 9, 10, 11, 12, 13};

Indication mtrx(MATRIX, 5, 7, x_pin, y_pin, 0);

void setup() {

}

void loop() {
  mtrx.setCursor(1, 1);
  // считаем от 0 до 4 маленьким шрифтом, рисуем белым по черному
  for (int i = 0; i < 5; i++) {
    mtrx.clear();
    mtrx.number(i);
    mtrx.delayUpdate(400);
  }

  //рисуем черным по белому
  mtrx.fill();
  mtrx.number(4, 0, 0);
  mtrx.delayUpdate(500);

  // считаем от 5 до 9 маленьким шрифтом, рисуем черным по белому
  for (int i = 5; i < 10; i++) {
    mtrx.fill();
    mtrx.number(i, 0, 0);
    mtrx.delayUpdate(400);
  }
  mtrx.delayUpdate(500);

  // считаем от 1 до 9 большим шрифтом
  for (int i = 1; i < 10; i++) {
    mtrx.clear();
    mtrx.number(i, 1);
    mtrx.delayUpdate(400);
  }
  mtrx.delayUpdate(500);
}
