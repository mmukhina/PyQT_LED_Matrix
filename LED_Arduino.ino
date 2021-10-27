
String temp;
int val;
String x;
#define red 9
#define green 10
#define blue 11

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void loop() {
  while (!Serial.available());
  x = Serial.readString();
  String temp = x.substring(1);
  val = temp.toInt();
  if (x[0] == 'r'){
    analogWrite(red, val);
  }
  else if (x[0] == 'g'){
    analogWrite(green, val);
  }
  else if (x[0] == 'b'){
    analogWrite(blue, val);
  }
  
  
  
}
