//Button
#define ButtonMaju 2 
#define ButtonMundur 7 
int KondisiMaju = 0;
int KondisiMundur = 0;

//led
#define LED 13

//Motor A
int Motor2Pin1 = 3;//pinDigital
int Motor2Pin2 = 4;//pinDigital
int EnablePinA = 5;//pinPWM

// Motor B
int motor1Pin1 = 8; //pinDigital
int motor1Pin2 = 9;//pinDigital
int EnablePinB = 6;//pinPWM

//Variabel untuk Mengatur Kecepatan Motor
int PWM = 100;//Nilai PWM

void setup() {
  //Setting pin menjadi OUTPUT semua
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(EnablePinA, OUTPUT);
  pinMode(EnablePinB, OUTPUT);
  pinMode(ButtonMaju, INPUT_PULLUP);
  pinMode(ButtonMundur, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  //Variabel untuk membaca dan menyimpan data digital Button
  KondisiMaju = digitalRead(ButtonMaju);
  KondisiMundur = digitalRead(ButtonMundur);
  
  //Membuat Kondisi Button Maju
  if (KondisiMaju == LOW){
    digitalWrite(LED, HIGH);
    Maju();
    delay(1000);
  }
  
  //Membuat Kondisi Button Mundur
  if(KondisiMundur == LOW){
    digitalWrite(LED, HIGH);
    Mundur();
    delay(1000);
  }
    
  else{
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(motor1Pin2, LOW);
  }
  
}

//Function untuk menggerakan Motor Maju
void Maju(){
  Serial.println("Maju");
  digitalWrite(Motor2Pin2, HIGH);
  digitalWrite(motor1Pin2, HIGH);
  analogWrite(EnablePinA, PWM);
  analogWrite(EnablePinB, PWM);
}

//Function untuk menggerakan Motor Mundur
void Mundur(){
  Serial.println("Mundur");
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(motor1Pin1, HIGH);
  analogWrite(EnablePinA, PWM);
  analogWrite(EnablePinB, PWM);
}
