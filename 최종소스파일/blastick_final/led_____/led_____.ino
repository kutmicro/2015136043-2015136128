//조도센서 소스코드
int POT_PIN = A6; //조도센서
int LED_PIN = A2;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT); //led 출력 핀 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = 0; //조도센서값
  val = analogRead(POT_PIN); 

  //조도센서 값이 450이상면 LED를 켠다
  if(val >450) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}


