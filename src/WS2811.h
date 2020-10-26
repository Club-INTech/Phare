//
// Created by rene on 25/10/2020.
//
#include "Arduino.h"
#ifndef PHARE_WS2811_H
#define PHARE_WS2811_H
#define LED 14

class WorldSemi{
public:
    void SEND_ONE(void);
    void SEND_ZERO(void);

private:
    static inline void T0H(void);
    static inline void T0L(void);
};


#endif //PHARE_WS2811_H
