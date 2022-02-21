void setup() {

  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    String num_str = Serial.readStringUntil("\n");//For test with Serial monitor.
    int num = num_str.toInt();
    Serial.print("num = ") ;
    Serial.println(num);
    speak_number(num);
  }
}

void speak_number(int num) {
  /* Play nymber from 0 to 99 in Thai language*/
  int unit_num = num % 10; //หลักหน่วย
  
  if (num >= 10) {
    int ten_th = (num / 10) % 10; // 
    
    if(ten_th == 2){//Special case "ยี่"
      speak_yeeh();
    }
    else if (ten_th > 1) {
      
      speak_digit(ten_th);
    }
    speak_ten();
    if (unit_num == 1) {
      //Special case (เอ็ด)
      speak_ed();
    }
    else if(unit_num != 0){
      
      speak_digit(unit_num);
    }
  }
  else {
    speak_digit(unit_num);
  }

}

void speak_digit(int digit) {
  /* Speak 0 to 9 in Thai language*/
  switch (digit) {
    case 0:
      Serial.println("\"ศูนย์\"");
      break;
    case 1:
      Serial.println("\"หนึ่ง\"");
      break;
    case 2:
      Serial.println("\"สอง\"");
      break;
    case 3:
      Serial.println("\"สาม\"");
      break;
    case 4:
      Serial.println("\"สี่\"");
      break;
    case 5:
      Serial.println("\"ห้า\"");
      break;
    case 6:
      Serial.println("\"หก\"");
      break;
    case 7:
      Serial.println("\"เจ็ด\"");
      break;
    case 8:
      Serial.println("\"แปด\"");
      break;
    case 9:
      Serial.println("\"เก้า\"");
      break;
  }
}
void speak_ed() {
  // "เอ็ด" special case in Thai language
  Serial.println("\"เอ็ด\"");
}
void speak_yeeh() {
  Serial.println("\"ยี่\"");
}
void speak_ten() {
  Serial.println("\"สิบ\"");
}
