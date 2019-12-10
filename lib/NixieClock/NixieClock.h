//NixieClock.h
#ifndef NIXIE_CLOCK_H
    #define NIXIE_CLOCK_H
    #include <ShiftRegister74HC595.h>

    #define LEFT_UP_DOT     0x01
    #define LEFT_DN_DOT     0x02
    #define RIGHT_UP_DOT    0x04
    #define RIGHT_DN_DOT    0x08
    #define NO_DOTS         0x00
    #define EMPTY_DIGIT     0x0F

    #define EMPTY_LEFT      0X0F    //EMPTY DIGIT
    #define EMPTY_RIGHT     0xF0    //EMPTY_LEFT << 4
    #define EMPTY_PAIR      0xFF    //EMPTY_LEFT || EMPTY_RIGHT
    #define LEFT_COLON      0x03    //LEFT_UP_DOT || LEFT_DN_DOT
    #define RIGHT_COLON     0x0C    //RIGHT_UP_DOT || RIGHT_DN_DOT
    #define DOTS            0x0A    //LEFT_DN_DOT || RIGHT_DN_DOT
    #define COLONS          0x0F    //LEFT_COLON || RIGHT_COLON

    class NixieClock
    {  
        ShiftRegister74HC595 sr;
        byte itob(int i, bool prependZero);
        const char* btoa(byte b);
        void debug(uint8_t pinValues[]);

        public:
            NixieClock(int numChips, int dataPin, int clockPin, int latchPin);
            void showTime(int h, int m, int s);
            void showDate(int d, int m, int y);
            void showTempHum(int temp, int hum);
            void showInt(int i, bool leadingZeros);
            void cycleTubes();
    };

#endif

