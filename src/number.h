// нарисовать цифру
void Indication::number(byte num, byte typeText, boolean en) {   // рисуем обычные цифры
  if (type1 == 0) {
    switch (num) {
      case 0:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], !signal);
        break;
      case 1:
        digitalWrite(x_pin[A], !signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], !signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], !signal);
        digitalWrite(x_pin[G], !signal);
        break;
      case 2:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], !signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], signal);
        digitalWrite(x_pin[F], !signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 3:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], !signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 4:
        digitalWrite(x_pin[A], !signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], !signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 5:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], !signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 6:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], !signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 7:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], !signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], !signal);
        digitalWrite(x_pin[G], !signal);
        break;
      case 8:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], signal);
        break;
      case 9:
        digitalWrite(x_pin[A], signal);
        digitalWrite(x_pin[B], signal);
        digitalWrite(x_pin[C], signal);
        digitalWrite(x_pin[D], signal);
        digitalWrite(x_pin[E], !signal);
        digitalWrite(x_pin[F], signal);
        digitalWrite(x_pin[G], signal);
        break;
    }
  }
  else if (type1 == 1) {
    switch (num) {
      case 0:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = !en;
        break;
      case 1:
        matrix[typeText][A] = !en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = !en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = !en;
        matrix[typeText][G] = !en;
        break;
      case 2:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = !en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = en;
        matrix[typeText][F] = !en;
        matrix[typeText][G] = en;
        break;
      case 3:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = !en;
        matrix[typeText][G] = en;
        break;
      case 4:
        matrix[typeText][A] = !en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = !en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = en;
        break;
      case 5:
        matrix[typeText][A] = en;
        matrix[typeText][B] = !en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = en;
        break;
      case 6:
        matrix[typeText][A] = en;
        matrix[typeText][B] = !en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = en;
        break;
      case 7:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = !en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = !en;
        matrix[typeText][G] = !en;
        break;
      case 8:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = en;
        break;
      case 9:
        matrix[typeText][A] = en;
        matrix[typeText][B] = en;
        matrix[typeText][C] = en;
        matrix[typeText][D] = en;
        matrix[typeText][E] = !en;
        matrix[typeText][F] = en;
        matrix[typeText][G] = en;
        break;
    }
  }
  else {
    if (x_max == 5 && typeText == 1) {
      _ang_x = 0;
      _ang_y = 0;
    }
    else {
      _ang_x = _ang_x1;
      _ang_y = _ang_y1;
    }
    switch (num + 10 * typeText) {
      case 0:
        rect(_ang_x, _ang_y, _ang_x + 2, _ang_y + 4, en);
        break;
      case 1:
        lineH(_ang_y + 4, _ang_x, _ang_x + 2, en);
        lineV(_ang_x + 1, _ang_y, _ang_y + 4, en);
        dot(_ang_x, _ang_y + 1, en);
        break;
      case 2:
        lineH(_ang_y, _ang_x, _ang_x + 2, en);
        lineH(_ang_y + 2, _ang_x, _ang_x + 2, en);
        lineH(_ang_y + 4, _ang_x, _ang_x + 2, en);
        dot(_ang_x + 2, _ang_y + 1, en);
        dot(_ang_x, _ang_y + 3, en);
        break;
      case 3:
        lineH(_ang_y, _ang_x, _ang_x + 1, en);
        lineH(_ang_y + 2, _ang_x, _ang_x + 1, en);
        lineH(_ang_y + 4, _ang_x, _ang_x + 2, en);
        lineV(_ang_x + 2, _ang_y, _ang_y + 4, en);
        break;
      case 4:
        lineH(_ang_y + 2, _ang_x, _ang_x + 1, en);
        lineV(_ang_x, _ang_y, _ang_y + 1, en);
        lineV(_ang_x + 2, _ang_y, _ang_y + 4, en);
        break;
      case 5:
        lineH(_ang_y, _ang_x, _ang_x + 2, en);
        lineH(_ang_y + 2, _ang_x, _ang_x + 2, en);
        lineH(_ang_y + 4, _ang_x, _ang_x + 2, en);
        dot(_ang_x, _ang_y + 1, en);
        dot(_ang_x + 2, _ang_y + 3, en);
        break;
      case 6:
        rect(_ang_x, _ang_y + 2, _ang_x + 2, _ang_y + 4, en);
        lineH(_ang_y, _ang_x, _ang_x + 2, en);
        dot(_ang_x, _ang_y + 1, en);
        break;
      case 7:
        lineH(_ang_y, _ang_x, _ang_x + 2, en);
        lineV(_ang_x + 1, _ang_y + 2, _ang_y + 4, en);
        dot(_ang_x + 2, _ang_y + 1, en);
        break;
      case 8:
        rect(_ang_x, _ang_y, _ang_x + 2, _ang_y + 2, en);
        rect(_ang_x, _ang_y + 2, _ang_x + 2, _ang_y + 4, en);
        break;
      case 9:
        rect(_ang_x, _ang_y, _ang_x + 2, _ang_y + 2, en);
        lineH(_ang_y + 4, _ang_x, _ang_x + 2, en);
        dot(_ang_x + 2, _ang_y + 3, en);
        break;
      case 10:
        rect(_ang_x, _ang_y, _ang_x + 4, _ang_y + 6, en);
        break;
      case 11:
        lineH(_ang_y + 6, _ang_x, _ang_x + 4, en);
        lineV(_ang_x + 2, _ang_y, _ang_y + 6, en);
        dot(_ang_x + 1, _ang_y + 1, en);
        break;
      case 12:
        lineH(_ang_y, _ang_x, _ang_x + 4, en);
        lineH(_ang_y + 3, _ang_x, _ang_x + 4, en);
        lineH(_ang_y + 6, _ang_x, _ang_x + 4, en);
        lineV(_ang_x + 4, _ang_y + 1, _ang_y + 2, en);
        lineV(_ang_x, _ang_y + 4, _ang_y + 5, en);
        break;
      case 13:
        lineH(_ang_y, _ang_x, _ang_x + 3, en);
        lineH(_ang_y + 3, _ang_x, _ang_x + 3, en);
        lineH(_ang_y + 6, _ang_x, _ang_x + 3, en);
        lineV(_ang_x + 4, _ang_y, _ang_y + 6, en);
        break;
      case 14:
        lineH(_ang_y + 3, _ang_x, _ang_x + 3, en);
        lineV(_ang_x, _ang_y, _ang_y + 2, en);
        lineV(_ang_x + 4, _ang_y, _ang_y + 6, en);
        break;
      case 15:
        lineH(_ang_y, _ang_x, _ang_x + 4, en);
        lineH(_ang_y + 3, _ang_x, _ang_x + 4, en);
        lineH(_ang_y + 6, _ang_x, _ang_x + 4, en);
        lineV(_ang_x, _ang_y + 1, _ang_y + 2, en);
        lineV(_ang_x + 4, _ang_y + 4, _ang_y + 5, en);
        break;
      case 16:
        rect(_ang_x, _ang_y + 3, _ang_x + 4, _ang_y + 6, en);
        lineH(_ang_y, _ang_x, _ang_x + 4, en);
        lineV(_ang_x, _ang_y + 1, _ang_y + 2, en);
        break;
      case 17:
        lineH(_ang_y, _ang_x, _ang_x + 4, en);
        lineV(_ang_x + 3, _ang_y + 2, _ang_y + 3, en);
        lineV(_ang_x + 2, _ang_y + 4, _ang_y + 6, en);
        dot(_ang_x + 4, _ang_y + 1, en);
        break;
      case 18:
        rect(_ang_x, _ang_y, _ang_x + 4, _ang_y + 3, en);
        rect(_ang_x, _ang_y + 3, _ang_x + 4, _ang_y + 6, en);
        break;
      case 19:
        rect(_ang_x, _ang_y, _ang_x + 4, _ang_y + 3, en);
        lineH(_ang_y + 6, _ang_x, _ang_x + 4, en);
        lineV(_ang_x + 4, _ang_y + 4, _ang_y + 5, en);
        break;
      case 20:
        if (x_max == 8) {
          lineV(1, 1, 6, en);
          lineV(6, 1, 6, en);
          rect(2, 0, 5, 7, en);
        }
        break;
      case 21:
        if (x_max == 8) {
          lineV(3, 0, 7, en);
          lineV(4, 0, 7, en);
          lineH(7, 2, 5, en);
          dot(2, 1, en);
        }
        break;
      case 22:
        if (x_max == 8) {
          lineH(1, 1, 2, en);
          lineH(0, 2, 5, en);
          lineH(7, 2, 6, en);
          lineV(6, 1, 2, en);
          lineV(5, 2, 3, en);
          lineV(4, 3, 4, en);
          lineV(3, 4, 5, en);
          lineV(2, 5, 6, en);
          lineV(1, 6, 7, en);
          dot(5, 1, en);
        }
        break;
      case 23:
        if (x_max == 8) {
          lineV(5, 1, 6, en);
          lineV(6, 1, 2, en);
          lineV(6, 4, 6, en);
          lineH(1, 1, 2, en);
          lineH(0, 2, 5, en);
          lineH(6, 1, 2, en);
          lineH(7, 2, 5, en);
          dot(4, 3, en);
        }
        break;
      case 24:
        if (x_max == 8) {
          lineV(4, 1, 7, en);
          lineV(5, 0, 7, en);
          lineH(5, 1, 3, en);
          dot(1, 4, en);
          dot(2, 3, en);
          dot(3, 2, en);
          dot(6, 5, en);
        }
        break;
      case 25:
        if (x_max == 8) {
          lineV(1, 0, 3, en);
          lineV(2, 0, 3, en);
          lineV(5, 4, 7, en);
          lineV(6, 4, 6, en);
          lineH(0, 3, 6, en);
          lineH(3, 3, 5, en);
          lineH(7, 2, 5, en);
          lineH(6, 1, 2, en);
        }
        break;
      case 26:
        if (x_max == 8) {
          lineV(1, 1, 6, en);
          lineV(2, 1, 2, en);
          lineV(6, 4, 6, en);
          lineH(1, 5, 6, en);
          lineH(0, 2, 5, en);
          rect(2, 3, 5, 7, en);
        }
        break;
      case 27:
        if (x_max == 8) {
          lineV(3, 3, 7, en);
          lineV(4, 3, 7, en);
          lineH(0, 1, 6, en);
          lineH(1, 5, 6, en);
          lineH(2, 4, 5, en);
        }
        break;
      case 28:
        if (x_max == 8) {
          lineV(1, 1, 2, en);
          lineV(1, 4, 6, en);
          lineV(6, 1, 2, en);
          lineV(6, 4, 6, en);
          rect(2, 0, 5, 3, en);
          rect(2, 3, 5, 7, en);
        }
        break;
      case 29:
        if (x_max == 8) {
          lineV(1, 1, 3, en);
          lineV(6, 1, 6, en);
          lineV(5, 5, 7, en);
          lineH(7, 2, 4, en);
          lineH(6, 1, 2, en);
          rect(2, 0, 5, 4, en);
        }
        break;
    }
  }
}