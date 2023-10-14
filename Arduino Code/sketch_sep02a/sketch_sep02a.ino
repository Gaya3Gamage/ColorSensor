int R_out = 0;
int G_out = 0;
int B_out = 0;
void setup() {
  // Setup the analog pin and led pin
  pinMode(A0, INPUT);

  pinMode(4, OUTPUT); //blue
  pinMode(3, OUTPUT); //green
  pinMode(2, OUTPUT); //red

  //starting serial at baud rate 9600
  Serial.begin(9600);

  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}

void loop() {
  // Reading blue
  digitalWrite(4, HIGH);
  delay(5);
  B_out = (B_out * 0.8) + (analogRead(A0) * 0.2); //complimentary filter 1:4
  digitalWrite(4, LOW);
  delay(10);

  // Reading Green
  digitalWrite(3, HIGH);
  delay(5);
  G_out = (B_out * 0.8) + (analogRead(A0) * 0.2); //complimentary filter 1:4
  digitalWrite(3, LOW);
  delay(10);

  // Reading Red
  digitalWrite(2, HIGH);
  delay(5);
  R_out = (B_out * 0.8) + (analogRead(A0) * 0.2); //complimentary filter 1:4
  digitalWrite(2, LOW);


Serial.print("R= ");Serial.print(R_out); 

Serial.print(" G= ");Serial.print(G_out); 

Serial.print(" B= ");Serial.println(B_out); 
}
