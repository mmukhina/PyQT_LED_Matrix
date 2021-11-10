#include <MaxMatrix.h>
int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 1;
byte buffer[20];
char text[] = "a";
MaxMatrix m(DIN, CS, CLK, maxInUse);

String x = "000";

// массивы для готовых картинок
byte full[] = {8, 8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
byte smile[] = {8, 8, 0x00, 0x20, 0x4e, 0x40, 0x40, 0x4e, 0x20, 0x00};
byte heart[] = {8, 8, 0x1c, 0x3e, 0x7e, 0xfc, 0xfc, 0x7e, 0x3e, 0x1c};
byte cat[] = {8, 8, 0xf8, 0x80, 0xc0, 0xe7, 0xea, 0xfe, 0xea, 0x87};
byte apple[] = {8, 8, 0x38, 0x7c, 0xfc, 0xfd, 0xfb, 0xfc, 0x7c, 0x38};
byte arrow[] = {8, 8, 0x08, 0x0c, 0x0e, 0xff, 0xff, 0x0e, 0x0c, 0x08};

byte anim101[] = {8, 8, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff};
byte anim102[] = {8, 8, 0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00};
byte anim103[] = {8, 8, 0x00, 0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00};
byte anim104[] = {8, 8, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00};
byte anim105[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

byte anim201[] = {8, 8, 0x3c, 0x42, 0x81, 0x81, 0x00, 0x00, 0x00, 0x00};
byte anim202[] = {8, 8, 0x3c, 0x7e, 0xc3, 0x81, 0x00, 0x00, 0x00, 0x00};
byte anim203[] = {8, 8, 0x3c, 0x7e, 0xff, 0xc3, 0x00, 0x00, 0x00, 0x00};
byte anim204[] = {8, 8, 0x3c, 0x7e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00};
byte anim205[] = {8, 8, 0x3c, 0x7e, 0xff, 0xff, 0x3c, 0x00, 0x00, 0x00};
byte anim206[] = {8, 8, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00};
byte anim207[] = {8, 8, 0x3c, 0x7e, 0xff, 0xff, 0xff, 0x7e, 0x3c, 0x00};
byte anim208[] = {8, 8, 0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c};
byte anim209[] = {8, 8, 0x00, 0x3c, 0x7e, 0xff, 0xff, 0xff, 0x7e, 0x3c};
byte anim210[] = {8, 8, 0x00, 0x00, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c};
byte anim211[] = {8, 8, 0x00, 0x00, 0x00, 0x3c, 0xff, 0xff, 0x7e, 0x3c};
byte anim212[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7e, 0x3c};
byte anim213[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x81, 0xff, 0x7e, 0x3c};
byte anim214[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x7e, 0x3c};
byte anim215[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x42, 0x3c};

byte anim301[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0};
byte anim302[] = {8, 8, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0};
byte anim303[] = {8, 8, 0xf4, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0};
byte anim304[] = {8, 8, 0xfe, 0xf4, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0};
byte anim305[] = {8, 8, 0xf0, 0xfe, 0xf4, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0};
byte anim306[] = {8, 8, 0xd0, 0xf0, 0xfe, 0xf4, 0xd0, 0xc0, 0xc0, 0xc0};
byte anim307[] = {8, 8, 0xc0, 0xd0, 0xf0, 0xfe, 0xf4, 0xd0, 0xc0, 0xc0};
byte anim308[] = {8, 8, 0xc0, 0xc0, 0xd0, 0xf0, 0xfe, 0xf4, 0xd0, 0xc0};
byte anim309[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xd0, 0xf0, 0xfe, 0xf4, 0xd0};
byte anim310[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0, 0xf0, 0xfe, 0xf4};
byte anim311[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0, 0xf0, 0xfe};
byte anim312[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0, 0xf0};
byte anim313[] = {8, 8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0};

byte anim401[] = {8, 8, 0x8e, 0x44, 0x24, 0x10, 0x08, 0x24, 0x22, 0x71};
byte anim402[] = {8, 8, 0x44, 0x24, 0x10, 0x08, 0x24, 0x22, 0x71, 0x22};
byte anim403[] = {8, 8, 0x24, 0x10, 0x08, 0x24, 0x22, 0x71, 0x22, 0x24};
byte anim404[] = {8, 8, 0x10, 0x08, 0x24, 0x22, 0x71, 0x22, 0x24, 0x08};
byte anim405[] = {8, 8, 0x08, 0x24, 0x22, 0x71, 0x22, 0x24, 0x08, 0x10};
byte anim406[] = {8, 8, 0x24, 0x22, 0x71, 0x22, 0x24, 0x08, 0x10, 0x24};
byte anim407[] = {8, 8, 0x22, 0x71, 0x22, 0x24, 0x08, 0x10, 0x24, 0x44};
byte anim408[] = {8, 8, 0x71, 0x22, 0x24, 0x08, 0x10, 0x24, 0x44, 0x8e};
byte anim409[] = {8, 8, 0x22, 0x24, 0x08, 0x10, 0x24, 0x44, 0x8e, 0x44};
byte anim410[] = {8, 8, 0x24, 0x08, 0x10, 0x24, 0x44, 0x8e, 0x44, 0x24};
byte anim411[] = {8, 8, 0x08, 0x10, 0x24, 0x44, 0x8e, 0x44, 0x24, 0x10};
byte anim412[] = {8, 8, 0x10, 0x24, 0x44, 0x8e, 0x44, 0x24, 0x10, 0x08};
byte anim413[] = {8, 8, 0x24, 0x44, 0x8e, 0x44, 0x24, 0x10, 0x08, 0x24};
byte anim414[] = {8, 8, 0x44, 0x8e, 0x44, 0x24, 0x10, 0x08, 0x24, 0x22};

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  m.init();
  m.setIntensity(8);
  m.clear();
}

void loop() {
  // проверяем какой код был получен
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

    else if (x == "308"){
      while (not Serial.available()){
        m.writeSprite(0, 0, anim101);
        delay(200);
        m.writeSprite(0, 0, anim102);
        delay(200);
        m.writeSprite(0, 0, anim103);
        delay(200);
        m.writeSprite(0, 0, anim104);
        delay(200);
        m.writeSprite(0, 0, anim105);
        delay(200);
      }
    }

    else if (x == "309"){
      while (not Serial.available()){
        m.writeSprite(0, 0, anim201);
        delay(130);
        m.writeSprite(0, 0, anim202);
        delay(130);
        m.writeSprite(0, 0, anim203);
        delay(130);
        m.writeSprite(0, 0, anim204);
        delay(130);
        m.writeSprite(0, 0, anim205);
        delay(130);
        m.writeSprite(0, 0, anim206);
        delay(130);
        m.writeSprite(0, 0, anim207);
        delay(130);
        m.writeSprite(0, 0, anim208);
        delay(130);
        m.writeSprite(0, 0, anim209);
        delay(130);
        m.writeSprite(0, 0, anim210);
        delay(130);
        m.writeSprite(0, 0, anim211);
        delay(130);
        m.writeSprite(0, 0, anim212);
        delay(130);
        m.writeSprite(0, 0, anim213);
        delay(130);
        m.writeSprite(0, 0, anim214);
        delay(130);
        m.writeSprite(0, 0, anim215);
        delay(130);
      }
    }

    else if (x == "310"){
      while (not Serial.available()){
        m.writeSprite(0, 0, anim301);
        delay(150);
        m.writeSprite(0, 0, anim302);
        delay(150);
        m.writeSprite(0, 0, anim303);
        delay(150);
        m.writeSprite(0, 0, anim304);
        delay(150);
        m.writeSprite(0, 0, anim305);
        delay(150);
        m.writeSprite(0, 0, anim306);
        delay(150);
        m.writeSprite(0, 0, anim307);
        delay(150);
        m.writeSprite(0, 0, anim308);
        delay(150);
        m.writeSprite(0, 0, anim309);
        delay(150);
        m.writeSprite(0, 0, anim310);
        delay(150);
        m.writeSprite(0, 0, anim311);
        delay(150);
        m.writeSprite(0, 0, anim312);
        delay(150);
        m.writeSprite(0, 0, anim313);
        delay(150);
      }
    }

    else if (x == "311"){
      while (not Serial.available()){
        m.writeSprite(0, 0, anim401);
        delay(140);
        m.writeSprite(0, 0, anim402);
        delay(140);
        m.writeSprite(0, 0, anim403);
        delay(140);
        m.writeSprite(0, 0, anim404);
        delay(140);
        m.writeSprite(0, 0, anim405);
        delay(140);
        m.writeSprite(0, 0, anim406);
        delay(140);
        m.writeSprite(0, 0, anim407);
        delay(140);
        m.writeSprite(0, 0, anim408);
        delay(140);
        m.writeSprite(0, 0, anim409);
        delay(140);
        m.writeSprite(0, 0, anim410);
        delay(140);
        m.writeSprite(0, 0, anim411);
        delay(140);
        m.writeSprite(0, 0, anim412);
        delay(140);
        m.writeSprite(0, 0, anim413);
        delay(140);
        m.writeSprite(0, 0, anim414);
        delay(140);
      }
    }
  }
}
