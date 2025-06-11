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
