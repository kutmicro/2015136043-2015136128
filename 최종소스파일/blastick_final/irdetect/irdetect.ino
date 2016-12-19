//적외선 센서 소스코드
int irDetectPin = 7; //적외선 Pin 설정
int motor3 = A3;  // 진동모터 연결 핀
void setup() {
  // put your setup code here, to run once:
  pinMode(irDetectPin, INPUT); //FC-51 입력으로 설정
  pinMode(motor3, OUTPUT);  //진동모터 출력
}

void loop() {
  // put your main code here, to run repeatedly:
 int noDetect = digitalRead(irDetectPin); //FC-51 상태 읽어오기
  if(noDetect){ //FC-51포트가 HIGH이면 즉, 감지 안되었다면
    digitalWrite(motor3, LOW); //motor off
  }
  else {       //LOW 즉, 감지 되었다면
    digitalWrite(motor3, HIGH); //motor on   
}
delay(400);
}
