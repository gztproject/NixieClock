//NixieClock.cpp
#include <NixieClock.h>
#include <ShiftRegister74HC595.h>

NixieClock::NixieClock(int dataPin, int clockPin, int latchPin) : sr(dataPin, clockPin, latchPin)
{   
}

/*
 * Shows h, m and s, separated by ':'
 */
void NixieClock::showTime(int h, int m, int s)
{     
    pinValues[0] = itob(h, true);
    pinValues[1] = itob(m, true);
    pinValues[2] = itob(s, true);
    pinValues[3] = COLONS;
    //sr.setAll(pinValues);
    updateClock();
    //debug(pinValues);
}

/*
 * Shows d, m and y, separated by '.'
 */
void NixieClock::showDate(int d, int m, int y)
{     
    while (y>99)
        y-=100;
    pinValues[0] = itob(d, false);
    pinValues[1] = itob(m, false);
    pinValues[2] = itob(y, true);
    pinValues[3] = DOTS;
    //sr.setAll(pinValues);
    updateClock();
    //debug(pinValues);
}

/*
 * Shows temp and hum. Temp shows on the leftmost two digits, hum can take 3 places on the right.
 */
void NixieClock::showTempHum(int temp, int hum)
{   
    pinValues[0] = itob(abs(temp), false);
    pinValues[1] = hum > 99 ? itob(1, false) : EMPTY_PAIR;
    pinValues[2] = itob(hum > 99 ? hum-100 : hum, hum > 99);
    pinValues[3] = LEFT_UP_DOT;
    //sr.setAll(pinValues);
    updateClock();
    //debug(pinValues);
}

/*
 * Shows a number i
 */
void NixieClock::showInt(uint32_t i, bool leadingZeros)
{     
    pinValues[0] = i > 9999 ? itob(floor(i/10000), leadingZeros) : leadingZeros ? itob(0, leadingZeros) : EMPTY_PAIR;
    pinValues[1] = i > 99 ? itob(floor((i % 10000)/100), leadingZeros) : leadingZeros ? itob(0, leadingZeros) : EMPTY_PAIR;
    pinValues[2] = itob(i%100, leadingZeros);
    pinValues[3] = NO_DOTS;
    
    //sr.setAll(pinValues);
    updateClock();
    //debug(pinValues);
}

void NixieClock::cycleTubes()
{    
    showInt(rand()%1000000, true);
    delay(20);    
}

void NixieClock::updateClock()
{
    if (pinValues != lastValues)
    {
        Serial.println("Got new values, updating the clock.");
        sr.setAll(pinValues.cbegin());
        std::copy(std::begin(pinValues), std::end(pinValues), std::begin(lastValues));        
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