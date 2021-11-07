int cycle_number = 0;
char incomingByte;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1);

  pinMode(16, OUTPUT);
}


void loop()
{

    if (Serial2.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial2.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);

    }

  cycle_number++;

Serial2.print(String(cycle_number)+" to PC  \n");

  delay(500);
}
