#include <LEDIndication.h>

byte dig[] = {2, 3, 4, 5};
byte seg[] = {6, 7, 8, 9, 10, 11, 12, 13};

Indication disp(SEVSEGMENT, 4, 8, dig, seg);

void setup() {

}

void loop() {
  // считаем от 100 до -100 без нулей вначале
  for (int i = 100; i >= -100; i--) {
    disp.digit(i);
    disp.delayUpdate(10);
  }
  disp.delayUpdate(500);

  // считаем от -100 до 100 с нулями вначале
  for (int i = -100; i <= 100; i++) {
    disp.digit(i, 1);
    disp.delayUpdate(10);
  }
  disp.delayUpdate(500);
}
