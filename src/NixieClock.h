//NixieClock.h
#ifndef NIXIE_CLOCK_H
    #define NIXIE_CLOCK_H
    #include <ShiftRegister74HC595.h>

    class NixieClock
    {  
        ShiftRegister74HC595 sr;
        byte itob(int i);

        public:
            NixieClock(int numChips, int dataPin, int clockPin, int latchPin);
            void showTime(int h, int m, int s);
            void showInt(int i);
    };

#endif

