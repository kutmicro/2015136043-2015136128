//전체 아두이노 작동 센서
int echoPin1 = 8; //초음파1
int trigPin1 = 9;
int echoPin2 = 10; //초음파2
int trigPin2 = 11;
int motor1 = A5; //초음파1 진동모터
int motor2 = A7; //초음파2 진동모터
int POT_PIN = A6; //조도센서
int LED_PIN = A2;
int irDetectPin = 7; //적외선 Pin 설정
int motor3 = A3;   //적외선 진동모터

void setup() {
  
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motor2, OUTPUT);
  pinMode(LED_PIN, OUTPUT); //조도센서 led
  pinMode(irDetectPin, INPUT); //FC-51 입력으로 설정
  pinMode(motor3, OUTPUT);   


}

void U1() { //초음파1
  float duration, distance;
  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin1, HIGH);
  pinMode(echoPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin1, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  
  
  Serial.print(distance);
  Serial.println("cm");
  // 수정한 값을 출력
  if(distance<100){
   digitalWrite(motor1,HIGH);

  }
  else{
   digitalWrite(motor1,LOW);

  }
  delay(100);
}

void U2() { //초음파1
  float duration, distance;
  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin2, HIGH);
  pinMode(echoPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin2, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  
  
  Serial.print(distance);
  Serial.println("cm");
  // 수정한 값을 출력
  if(distance<50){
   digitalWrite(motor2,HIGH);

  }
  else{
   digitalWrite(motor2,LOW);

  }
  delay(100);
}

void led(){ //조도센서
  int val = 0;
  val = analogRead(POT_PIN); 

  //조도센서 값이 450이상이면 LED를 켠다
  if(val >450) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(300);
}
void indetect(){ //적외선센서
  int noDetect = digitalRead(irDetectPin); //FC-51 상태 읽어오기
  
  if(noDetect){ //FC-51포트가 HIGH이면 즉, 감지 안되었다면
    digitalWrite(motor3, LOW); //motor Off
  }
  else {       //LOW 즉, 감지 되었다면
    digitalWrite(motor3, HIGH); //motor ON   
}
delay(100);
}

void loop(){
  U1();
  U2();
  led();
  indetect();
}
