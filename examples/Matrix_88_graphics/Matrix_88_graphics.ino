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
