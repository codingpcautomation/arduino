#include <ModbusMaster.h>
ModbusMaster node;

void setup()
{
  // Modbus communication runs at 19200 baud
  Serial.begin(9600);
  Serial2.begin(19200, SERIAL_8E1);
  node.begin(8, Serial2);

}
void loop()
{
  //Serial.println("---------------------------------------------");
  uint8_t result;
  result = node.readHoldingRegisters(4005, 4);
    delay(1000);
  if (result == node.ku8MBSuccess)
  {
    Serial.println("---------------------------------------------");
    Serial.print("Temp PV: ");
    Serial.println(node.getResponseBuffer(1));
    Serial.print("Temp SP: ");
    Serial.println(node.getResponseBuffer(3));
  }
}

