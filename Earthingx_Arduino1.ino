

#define spdLeft 3   //speed of left motors
#define spdRight 6  //speed of right motors
#define dir1Left 2  //direction 1 of left motors
#define dir2Left 4  //direction 2 of left motors
#define dir1Right 5 //direction 1 of right motors
#define dir2Right 7 //direction 2 of right motors

void setup() {
  
  Serial.begin(115200);
  while(!Serial) {
    ;
  }
  pinMode(spdLeft, OUTPUT);
  pinMode(spdRight, OUTPUT);
  pinMode(dir1Left, OUTPUT);
  pinMode(dir2Left, OUTPUT);
  pinMode(dir1Right, OUTPUT);
  pinMode(dir2Right, OUTPUT);

}

char uart_rec;  //uart receive from ESP32

void loop() {
  if (Serial.available()) {
    uart_rec = char(Serial.read());
    Serial.println(uart_rec);
  }

  if (uart_rec == 'w') {        // Stands for WASD keyboards as controller
    moveForward();
  }
  else if (uart_rec == 's') {   // Stands for WASD keyboards as controller
    moveBackward();
  }
  else if (uart_rec == 'a') {   // Stands for WASD keyboards as controller
    moveLeft();
  }
  else if (uart_rec == 'd') {   // Stands for WASD keyboards as controller
    moveRight();
  }
  else if (uart_rec == 'q') {   // Stands for "quit" to stop
    stopMove();
  }
}

void moveForward() {
  
  analogWrite(spdLeft,255);
  analogWrite(spdRight,255);
  digitalWrite(dir1Left,HIGH);
  digitalWrite(dir2Left,LOW);
  digitalWrite(dir1Right,HIGH);
  digitalWrite(dir2Right,LOW);
  delay(30);
}

void moveBackward() {
  
  analogWrite(spdLeft,255);
  analogWrite(spdRight,255);
  digitalWrite(dir1Left,LOW);
  digitalWrite(dir2Left,HIGH);
  digitalWrite(dir1Right,LOW);
  digitalWrite(dir2Right,HIGH);
  delay(30);
}

void moveLeft() {
  
  analogWrite(spdLeft,255);
  analogWrite(spdRight,255);
  digitalWrite(dir1Left,LOW);
  digitalWrite(dir2Left,HIGH);
  digitalWrite(dir1Right,HIGH);
  digitalWrite(dir2Right,LOW);
  delay(30);
}

void moveRight() {

  analogWrite(spdLeft,255);
  analogWrite(spdRight,255);
  digitalWrite(dir1Left,HIGH);
  digitalWrite(dir2Left,LOW);
  digitalWrite(dir1Right,LOW);
  digitalWrite(dir2Right,HIGH);
  delay(30);
}

void stopMove() {
  
  analogWrite(spdLeft,0);
  analogWrite(spdRight,0);
  digitalWrite(dir1Left,LOW);
  digitalWrite(dir2Left,LOW);
  digitalWrite(dir1Right,LOW);
  digitalWrite(dir2Right,LOW);
  delay(30);
}
