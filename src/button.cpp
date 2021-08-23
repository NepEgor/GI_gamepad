#include "button.h"

void Button::init(uint16_t x, uint16_t y, uint8_t f, HIDMultitouch* mt)
{
    this->x = x;
    this->y = y;
    this->f = f;
    this->mt = mt;
    this->state = 0;
}

void Button::press()
{
    mt->press(x, y, f);
}

void Button::release()
{
    mt->release(x, y, f);
}

void Button::click()
{
    press();
    release();
}

void Button::toggle(uint8_t s)
{
    if(state != s){
        state = s;
        
        if (s)
        {
            press();
        }
        else
        {
            release();
        }
    }
}
