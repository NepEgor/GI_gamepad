#pragma once

#include "hidclass.h"

class Button
{
    private:

    volatile uint16_t x, y;
    volatile uint8_t f;
    HIDMultitouch* mt;
    volatile uint8_t state;

    public:

    Button() {}
    void init(uint16_t x, uint16_t y, uint8_t f, HIDMultitouch* mt);
    
    void press();
    void release();
    void click();

    void toggle(uint8_t state);
};
