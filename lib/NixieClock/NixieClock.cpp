//NixieClock.cpp
#include <NixieClock.h>
#include <ShiftRegister74HC595.h>

NixieClock::NixieClock(int numChips, int dataPin, int clockPin, int latchPin) : sr (numChips, dataPin, clockPin, latchPin)
{   
}

/*
 * Shows h, m and s, separated by ':'
 */
void NixieClock::showTime(int h, int m, int s)
{     
    uint8_t pinValues[] = { itob(h, true), itob(m, true), itob(s, true), COLONS };
    sr.setAll(pinValues);
    //debug(pinValues);
}

/*
 * Shows d, m and y, separated by '.'
 */
void NixieClock::showDate(int d, int m, int y)
{     
    while (y>99)
        y-=100;
    uint8_t pinValues[] = { itob(d, false), itob(m, false), itob(y, true), DOTS };
    sr.setAll(pinValues);
    //debug(pinValues);
}

/*
 * Shows temp and hum. Temp shows on the leftmost two digits, hum can take 3 places on the right.
 */
void NixieClock::showTempHum(int temp, int hum)
{   
    byte middleDigits = hum > 99 ? itob(1, false) : EMPTY_PAIR;
    uint8_t pinValues[] = { itob(abs(temp), false), middleDigits, itob(hum > 99 ? hum-100 : hum, hum > 99), LEFT_UP_DOT };
    sr.setAll(pinValues);
    //debug(pinValues);
}

/*
 * Shows a number i
 */
void NixieClock::showInt(int i, bool leadingZeros)
{     
    byte leftDigits = i > 9999 ? itob(floor(i/10000), leadingZeros) : EMPTY_PAIR;
    byte middleDigits = i > 99 ? itob(floor((i % 10000)/100), leadingZeros) : EMPTY_PAIR;
    byte rightDigits = itob(i%100, leadingZeros);
    uint8_t pinValues[] = { leftDigits, middleDigits, rightDigits, NO_DOTS };
    sr.setAll(pinValues);
    //debug(pinValues);
}

void NixieClock::cycleTubes()
{
    for(uint16_t i = 0; i<1000000; i += 111111)
    {
        showInt(i, true);
    }
}

byte NixieClock::itob(int i, bool prependZero)
{
    //Serial.printf("Converting %i to binary with zero prepending %s.\n\r", i, prependZero ? "true" : "false" );
    int first = prependZero ? 0 : EMPTY_DIGIT;
    int second = 0;
    if(i>9)
    {        
        first = i/10;
        second = i%10;
        //Serial.printf("%i is bigger than 9. Split to %i, %i.\n\r", i, first, second);
    }
    else
    {
        second = i;
        //Serial.printf("%i is smaller than 10. Added zero: %i, %i.\n\r", i, first, second);
    }
    //Serial.printf("First half byte 0x%X, shifted0x%X\n\r", first, first<<4);
    //Serial.printf("Second half byte 0x%X; ", second);
    byte b = first + (second << 4);
    //Serial.printf("Assembled the byte 0x%02X\n\r", b);
    return b;
}

const char* NixieClock::btoa(byte b)
{
    int second = b >> 4;    
    int first = b - (second << 4);   

    char firsta = 'a';
    char seconda = 'a';
    itoa(first, &firsta, 10);
    itoa(second, &seconda, 10);

     
    char res = first < 9 ? firsta : ' ';
    res += second < 9 ? seconda : ' ';    

    Serial.printf("%s\n\r", &res);
    return &res;
}


void NixieClock::debug(uint8_t pinValues[])
{
    const char* first = "";
    first = btoa(pinValues[0]);
    
    const char* second = "";
    second = btoa(pinValues[1]);
   
    const char* third = "";
    third = btoa(pinValues[2]);    

    const char*  leftDots = "";
    const char* rightDots = "";
    
    uint8_t dots = pinValues[3];
    if((dots && LEFT_UP_DOT) == LEFT_UP_DOT)
        leftDots = "*";
    if((dots && LEFT_DN_DOT) == LEFT_DN_DOT)
        leftDots = ".";
    if((dots && LEFT_COLON) == LEFT_COLON)
        leftDots = ":";
    if((dots && RIGHT_UP_DOT) == RIGHT_UP_DOT)
        rightDots = "*";
    if((dots && RIGHT_DN_DOT) == RIGHT_DN_DOT)
        rightDots = ".";
    if((dots && RIGHT_COLON) == RIGHT_COLON)
        rightDots = ":";   

    Serial.printf("%s%s%s%s%s\n\r", first, leftDots, second, rightDots, third);
}