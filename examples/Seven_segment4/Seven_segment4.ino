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
