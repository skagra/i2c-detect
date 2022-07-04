#include <Wire.h>

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        delay(10);
    }

    Wire.begin();

    Serial.println("\nI2C Detect\n");
}

bool listening(byte address)
{
    Wire.beginTransmission(address);
    return Wire.endTransmission() == 0;
}

char *hexString(byte value, char *buffer)
{
    sprintf(buffer, "%02X", value);
    buffer[2] = (byte)0;
    return buffer;
}

// Addresses are 7 bit (128 values)
// The following are reserved:
// 0b0000XXX and 0b1111XXX - 16 address, leaving 112 addresses available
void loop()
{
    byte addr;
    char *byteString = (char *)malloc(3);

    Serial.println("Scanning for I2C devices\n");

    // Start at a 8 to skip the low order group of reserved addresses
    // Stop at 119 to skip high order group of reserved addresses
    for (addr = 8; addr < 120; addr++)
    {
        if (addr % 8 == 0)
        {
            Serial.print(hexString(addr, byteString));
            Serial.print("  ");
        }

        if (listening(addr))
        {
            Serial.print(hexString(addr, byteString));
        }
        else
        {
            Serial.print("--");
        }

        Serial.print(" ");
        if ((addr + 1) % 8 == 0)
        {
            Serial.println();
        }
    }

    Serial.println("\nDone\n");

    while (1)
    {
        delay(5000);
    }
}