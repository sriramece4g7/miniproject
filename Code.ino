 int tempPin = A0; 
int fan = 11;
int led = 8; 
int temp;
int tempMin = 20; 
int tempMax = 25;
int fanSpeed;

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
pinMode(tempPin, INPUT); 
  Serial.begin(9600);
}

void loop()
{
temp = readTemp(); 
  Serial.println( temp );
  if(temp < tempMin)
{
fanSpeed = 0; 
    analogWrite(fan, fanSpeed);
    digitalWrite(fan, LOW);
}
if((temp >= tempMin) && (temp <= tempMax))
{
fanSpeed = temp; 
  fanSpeed=2.0*fanSpeed;
  analogWrite(fan, fanSpeed);
}

if(temp > tempMax)
{
digitalWrite(led, HIGH);
  { fanSpeed=100; 
   analogWrite(fan,fanSpeed);
}
}
else
{
digitalWrite(led, LOW);
}


delay(200);
}

int readTemp() {
temp = analogRead(tempPin); 
  return temp * 0.48828125;
}
