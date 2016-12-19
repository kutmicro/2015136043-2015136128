//초음파 센서 소스코드
int echoPin1 = 8; //초음파1
int trigPin1 = 9;
int echoPin2 = 10; //초음파2
int trigPin2 = 11;
int motor1 = A5; //초음파1
int motor2 = A7; //초음파2
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);
  pinMode(motor1, OUTPUT); //진동모터 출력
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motor2, OUTPUT); //진동모터 출력

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
  if(distance<100){ //100cm이하일때 장애물감지 모터 작동
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
  if(distance<50){ //50cm이하일때 장애물 감지
   digitalWrite(motor2,HIGH);
  }
  else{
   digitalWrite(motor2,LOW);
  }
  delay(100);
}
void loop() {
  // put your main code here, to run repeatedly:
  U1();
  U2();
}
