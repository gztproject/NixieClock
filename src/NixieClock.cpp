//NixieClock.cpp
#include <NixieClock.h>
#include <ShiftRegister74HC595.h>

NixieClock::NixieClock(int numChips, int dataPin, int clockPin, int latchPin) : sr (numChips, dataPin, clockPin, latchPin)
{   
}

void NixieClock::showTime(int h, int m, int s)
{     
    uint8_t pinValues[] = { itob(h), itob(m), itob(s) };
    sr.setAll(pinValues);
}

void NixieClock::showInt(int i)
{         
    uint8_t pinValues[] = { itob(i) };
    sr.setAll(pinValues);
}

byte NixieClock::itob(int i)
{
    Serial.printf("Converting %i to binary.\n\r", i);
    int first = 0;
    int second = 0;
    if(i>10)
    {        
        first = i/10;
        second = i%10;
        Serial.printf("%i is bigger than 10. Split to %i, %i.\n\r", i, first, second);
    }
    else
    {
        second = i;
        Serial.printf("%i is smaller than 10. Added zero: %i, %i.\n\r", i, first, second);
    }
    Serial.printf("First half byte 0x%X, shifted0x%X\n\r", first, first<<4);
    Serial.printf("Second half byte 0x%X", second);
    byte b = (first << 4) + second;
    Serial.printf("Assembled the byte 0x%02X\n\r", b);
    return b;
}