#include <Wire.h>

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        delay(10);

    Wire.begin();

    Serial.println("\nI2C Detect\n");
}

bool listening(byte address)
{
    Wire.beginTransmission(address);
    return Wire.endTransmission() == 0;
}

// Addresses are 7 bit (128 values)
// The following are reserved:
// 0b0000XXX and 0b1111XXX - 16 address, leaving 112 addresses available
void loop()
{
    byte addr;
    byte numberFound = 0;

    char *byteString = (char *)malloc(3);
    byteString[2] = (byte)0;

    Serial.println("Scanning for I2C devices\n");

    // Start at a 8 to skip the low order group of reserved addresses
    // Stop at 119 to skip high order group of reserved addresses
    for (addr = 8; addr < 120; addr++)
    {
        if (listening(addr))
        {
            sprintf(byteString, "%02x", addr);
            Serial.print("I2C device found at address 0x");
            Serial.println(byteString);
            numberFound++;
        }
    }

    if (numberFound == 0)
    {
        Serial.println("\nNo I2C devices found\n");
    }

    Serial.println("\nDone\n");

    while (1)
    {
        delay(5000);
    }
}