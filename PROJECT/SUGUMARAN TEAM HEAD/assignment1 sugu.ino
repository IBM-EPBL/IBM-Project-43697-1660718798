const int lm35_pin = A1; /* LM35 O/P pin */
int Buzz= 8; // Define Bizzer pin
int PIR= 3; // Define PIR pin
int val= 0; // Initializing the value as zero at the beginning

void setup() {
pinMode(Buzz, OUTPUT);
pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin); /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  delay(1000);
 
  if( temp_val>61)
    digitalWrite(Buzz, HIGH); // Turn Buzzer ON
   
  val = digitalRead(PIR); // The value read from PIR pin 3 will be assigned to 'val'
if(val == HIGH){
 
  digitalWrite(Buzz, HIGH); // Turn Buzzer ON
  Serial.println("Movement Detected"); // Print this text in Serial Monitor
}
else
{
 
  digitalWrite(Buzz, LOW);
  Serial.println("Movement not Detected");
}
}