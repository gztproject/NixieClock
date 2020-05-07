//NixieClock.h
#ifndef NIXIE_CLOCK_H
#define NIXIE_CLOCK_H
#include <ShiftRegister74HC595.h>

#define NUM_CHIPS 4

#define LEFT_UP_DOT 0x01
#define LEFT_DN_DOT 0x02
#define RIGHT_UP_DOT 0x04
#define RIGHT_DN_DOT 0x08
#define NO_DOTS 0x00

#define LEFT_COLON (LEFT_UP_DOT | LEFT_DN_DOT)
#define RIGHT_COLON (RIGHT_UP_DOT | RIGHT_DN_DOT)
#define DOTS (LEFT_DN_DOT | RIGHT_DN_DOT)
#define COLONS (LEFT_COLON | RIGHT_COLON)

#define EMPTY_DIGIT 0x0F

#define EMPTY_LEFT EMPTY_DIGIT
#define EMPTY_RIGHT (EMPTY_LEFT << 4)
#define EMPTY_PAIR (EMPTY_LEFT | EMPTY_RIGHT)


class NixieClock
{
public:
    NixieClock(int dataPin, int clockPin, int latchPin);
    void showTime(int h, int m, int s);
    void showDate(int d, int m, int y);
    void showTempHum(int temp, int hum);
    void showInt(uint32_t i, bool leadingZeros);
    void cycleTubes();
    void showIpFlashy(uint8_t *ip, uint8_t numOctets, uint16_t time);

private:
    ShiftRegister74HC595<NUM_CHIPS> sr;
    byte itob(int i, bool prependZero);
    const char *btoa(byte b);
    void debug(uint8_t pinValues[]);
    void updateClock();
    std::array<uint8_t, 4> pinValues;
    std::array<uint8_t, 4> lastValues;
};

#endif
