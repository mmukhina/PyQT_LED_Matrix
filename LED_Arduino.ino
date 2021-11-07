#include <MaxMatrix.h>
int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 1;
byte buffer[20];
char text[] = "a";
int pinCS = 9;
MaxMatrix m(DIN, CS, CLK, maxInUse);

String x = "000";

byte full[] = {8, 8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
byte smile[] = {8, 8, 0x00, 0x20, 0x4e, 0x40, 0x40, 0x4e, 0x20, 0x00};
byte heart[] = {8, 8, 0x1c, 0x3e, 0x7e, 0xfc, 0xfc, 0x7e, 0x3e, 0x1c};
byte cat[] = {8, 8, 0xf8, 0x80, 0xc0, 0xe7, 0xea, 0xfe, 0xea, 0x87};
byte apple[] = {8, 8, 0x38, 0x7c, 0xfc, 0xfd, 0xfb, 0xfc, 0x7c, 0x38};
byte arrow[] = {8, 8, 0x08, 0x0c, 0x0e, 0xff, 0xff, 0x0e, 0x0c, 0x08};

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  m.init();
  m.setIntensity(8);
  m.clear();
}

void loop() {
  if (Serial.available() > 0){
    x = Serial.readString();
    if (x == "100"){m.setDot(0, 0, true);}
    else if (x == "110"){m.setDot(1, 0, true);}
    else if (x == "120"){m.setDot(2, 0, true);}
    else if (x == "130"){m.setDot(3, 0, true);}
    else if (x == "140"){m.setDot(4, 0, true);}
    else if (x == "150"){m.setDot(5, 0, true);}
    else if (x == "160"){m.setDot(6, 0, true);}
    else if (x == "170"){m.setDot(7, 0, true);}

    else if (x == "101"){m.setDot(0, 1, true);}
    else if (x == "111"){m.setDot(1, 1, true);}
    else if (x == "121"){m.setDot(2, 1, true);}
    else if (x == "131"){m.setDot(3, 1, true);}
    else if (x == "141"){m.setDot(4, 1, true);}
    else if (x == "151"){m.setDot(5, 1, true);}
    else if (x == "161"){m.setDot(6, 1, true);}
    else if (x == "171"){m.setDot(7, 1, true);}
  
    else if (x == "102"){m.setDot(0, 2, true);}
    else if (x == "112"){m.setDot(1, 2, true);}
    else if (x == "122"){m.setDot(2, 2, true);}
    else if (x == "132"){m.setDot(3, 2, true);}
    else if (x == "142"){m.setDot(4, 2, true);}
    else if (x == "152"){m.setDot(5, 2, true);}
    else if (x == "162"){m.setDot(6, 2, true);}
    else if (x == "172"){m.setDot(7, 2, true);}
  
    else if (x == "103"){m.setDot(0, 3, true);}
    else if (x == "113"){m.setDot(1, 3, true);}
    else if (x == "123"){m.setDot(2, 3, true);}
    else if (x == "133"){m.setDot(3, 3, true);}
    else if (x == "143"){m.setDot(4, 3, true);}
    else if (x == "153"){m.setDot(5, 3, true);}
    else if (x == "163"){m.setDot(6, 3, true);}
    else if (x == "173"){m.setDot(7, 3, true);}
  
    else if (x == "104"){m.setDot(0, 4, true);}
    else if (x == "114"){m.setDot(1, 4, true);}
    else if (x == "124"){m.setDot(2, 4, true);}
    else if (x == "134"){m.setDot(3, 4, true);}
    else if (x == "144"){m.setDot(4, 4, true);}
    else if (x == "154"){m.setDot(5, 4, true);}
    else if (x == "164"){m.setDot(6, 4, true);}
    else if (x == "174"){m.setDot(7, 4, true);}
  
    else if (x == "105"){m.setDot(0, 5, true);}
    else if (x == "115"){m.setDot(1, 5, true);}
    else if (x == "125"){m.setDot(2, 5, true);}
    else if (x == "135"){m.setDot(3, 5, true);}
    else if (x == "145"){m.setDot(4, 5, true);}
    else if (x == "155"){m.setDot(5, 5, true);}
    else if (x == "165"){m.setDot(6, 5, true);}
    else if (x == "175"){m.setDot(7, 5, true);}
  
    else if (x == "106"){m.setDot(0, 6, true);}
    else if (x == "116"){m.setDot(1, 6, true);}
    else if (x == "126"){m.setDot(2, 6, true);}
    else if (x == "136"){m.setDot(3, 6, true);}
    else if (x == "146"){m.setDot(4, 6, true);}
    else if (x == "156"){m.setDot(5, 6, true);}
    else if (x == "166"){m.setDot(6, 6, true);}
    else if (x == "176"){m.setDot(7, 6, true);}
  
    else if (x == "107"){m.setDot(0, 7, true);}
    else if (x == "117"){m.setDot(1, 7, true);}
    else if (x == "127"){m.setDot(2, 7, true);}
    else if (x == "137"){m.setDot(3, 7, true);}
    else if (x == "147"){m.setDot(4, 7, true);}
    else if (x == "157"){m.setDot(5, 7, true);}
    else if (x == "167"){m.setDot(6, 7, true);}
    else if (x == "177"){m.setDot(7, 7, true);}
  
    else if (x == "200"){m.setDot(0, 0, false);}
    else if (x == "210"){m.setDot(1, 0, false);}
    else if (x == "220"){m.setDot(2, 0, false);}
    else if (x == "230"){m.setDot(3, 0, false);}
    else if (x == "240"){m.setDot(4, 0, false);}
    else if (x == "250"){m.setDot(5, 0, false);}
    else if (x == "260"){m.setDot(6, 0, false);}
    else if (x == "270"){m.setDot(7, 0, false);}
  
    else if (x == "201"){m.setDot(0, 1, false);}
    else if (x == "211"){m.setDot(1, 1, false);}
    else if (x == "221"){m.setDot(2, 1, false);}
    else if (x == "231"){m.setDot(3, 1, false);}
    else if (x == "241"){m.setDot(4, 1, false);}
    else if (x == "251"){m.setDot(5, 1, false);}
    else if (x == "261"){m.setDot(6, 1, false);}
    else if (x == "271"){m.setDot(7, 1, false);}
  
    else if (x == "202"){m.setDot(0, 2, false);}
    else if (x == "212"){m.setDot(1, 2, false);}
    else if (x == "222"){m.setDot(2, 2, false);}
    else if (x == "232"){m.setDot(3, 2, false);}
    else if (x == "242"){m.setDot(4, 2, false);}
    else if (x == "252"){m.setDot(5, 2, false);}
    else if (x == "262"){m.setDot(6, 2, false);}
    else if (x == "272"){m.setDot(7, 2, false);}
  
    else if (x == "203"){m.setDot(0, 3, false);}
    else if (x == "213"){m.setDot(1, 3, false);}
    else if (x == "223"){m.setDot(2, 3, false);}
    else if (x == "233"){m.setDot(3, 3, false);}
    else if (x == "243"){m.setDot(4, 3, false);}
    else if (x == "253"){m.setDot(5, 3, false);}
    else if (x == "263"){m.setDot(6, 3, false);}
    else if (x == "273"){m.setDot(7, 3, false);}
  
    else if (x == "204"){m.setDot(0, 4, false);}
    else if (x == "214"){m.setDot(1, 4, false);}
    else if (x == "224"){m.setDot(2, 4, false);}
    else if (x == "234"){m.setDot(3, 4, false);}
    else if (x == "244"){m.setDot(4, 4, false);}
    else if (x == "254"){m.setDot(5, 4, false);}
    else if (x == "264"){m.setDot(6, 4, false);}
    else if (x == "274"){m.setDot(7, 4, false);}
  
    else if (x == "205"){m.setDot(0, 5, false);}
    else if (x == "215"){m.setDot(1, 5, false);}
    else if (x == "225"){m.setDot(2, 5, false);}
    else if (x == "235"){m.setDot(3, 5, false);}
    else if (x == "245"){m.setDot(4, 5, false);}
    else if (x == "255"){m.setDot(5, 5, false);}
    else if (x == "265"){m.setDot(6, 5, false);}
    else if (x == "275"){m.setDot(7, 5, false);}
  
    else if (x == "206"){m.setDot(0, 6, false);}
    else if (x == "216"){m.setDot(1, 6, false);}
    else if (x == "226"){m.setDot(2, 6, false);}
    else if (x == "236"){m.setDot(3, 6, false);}
    else if (x == "246"){m.setDot(4, 6, false);}
    else if (x == "256"){m.setDot(5, 6, false);}
    else if (x == "266"){m.setDot(6, 6, false);}
    else if (x == "276"){m.setDot(7, 6, false);}
  
    else if (x == "207"){m.setDot(0, 7, false);}
    else if (x == "217"){m.setDot(1, 7, false);}
    else if (x == "227"){m.setDot(2, 7, false);}
    else if (x == "237"){m.setDot(3, 7, false);}
    else if (x == "247"){m.setDot(4, 7, false);}
    else if (x == "257"){m.setDot(5, 7, false);}
    else if (x == "267"){m.setDot(6, 7, false);}
    else if (x == "277"){m.setDot(7, 7, false);}

    else if (x == "301"){m.clear(); m.writeSprite(0, 0, full);}
    else if (x == "302"){m.clear(); m.writeSprite(0, 0, smile);}
    else if (x == "303"){m.clear(); m.writeSprite(0, 0, heart);}
    else if (x == "304"){m.clear(); m.writeSprite(0, 0, cat);}
    else if (x == "305"){m.clear(); m.writeSprite(0, 0, apple);}
    else if (x == "306"){m.clear(); m.writeSprite(0, 0, arrow);}
    else if (x == "307"){m.clear();}
    
  }
}
