#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 9;
String data;
String row1;
String row2;
String row3;
String row4;
String row5;
String row6;
String row7;
String row8;

Max72xxPanel matrix = Max72xxPanel(pinCS, 1, 1);

void setup() {
    matrix.setIntensity(4); // яркость от 0 до 15
    Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
        data = Serial.readStringUntil('\n');
        data = data.substring(2);
        row1 = String(data[0]) + String(data[1]) + String(data[2]) + String(data[3]) + String(data[4]) + String(data[5]) + String(data[6]) + String(data[7]);
        row2 = String(data[8]) + String(data[9]) + String(data[10]) + String(data[11]) + String(data[12]) + String(data[13]) + String(data[14]) + String(data[15]);
        row3 = String(data[16]) + String(data[17]) + String(data[18]) + String(data[19]) + String(data[20]) + String(data[21]) + String(data[22]) + String(data[23]);
        row4 = String(data[24]) + String(data[25]) + String(data[26]) + String(data[27]) + String(data[28]) + String(data[29]) + String(data[30]) + String(data[31]);
        row5 = String(data[32]) + String(data[33]) + String(data[34]) + String(data[35]) + String(data[36]) + String(data[37]) + String(data[38]) + String(data[39]);
        row6 = String(data[40]) + String(data[41]) + String(data[42]) + String(data[43]) + String(data[44]) + String(data[45]) + String(data[46]) + String(data[47]);
        row7 = String(data[48]) + String(data[49]) + String(data[50]) + String(data[51]) + String(data[52]) + String(data[53]) + String(data[54]) + String(data[55]);
        row8 = String(data[56]) + String(data[57]) + String(data[58]) + String(data[59]) + String(data[60]) + String(data[61]) + String(data[62]) + String(data[63]);
     }
    matrix.drawPixel(3, 4, HIGH); // зажигаем пиксель с координатами {3,4}
    matrix.write(); // вывод всех пикселей на матрицу
    delay(300);
    matrix.drawPixel(3, 4, LOW); // гасим пиксель
    matrix.write();
    delay(300);
}
