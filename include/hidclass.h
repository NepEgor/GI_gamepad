#pragma once

#include <USBComposite.h>

#include "hiddescriptor.h"

typedef struct
{
    uint8_t reportID;
    uint8_t buttons;

    uint8_t finger;
    uint16_t x:12;
    uint16_t y:12;
} __packed MultitouchReport_t;

class HIDMultitouch : public HIDReporter
{
    private:

	void buttons(uint8_t f, uint8_t b);
    
    MultitouchReport_t report;
    
    public:
    
    void begin(void) {};
    void end(void) {};

    HIDMultitouch(USBHID& HID, uint8_t reportID = HID_DIGITIZER_REPORT_ID);

    void move(uint16_t x, uint16_t y, uint8_t f = 0);
	void click(uint8_t f = 0, uint8_t b = DIGITIZER_TOUCH_IN_RANGE);
	void press(uint8_t f = 0, uint8_t b = DIGITIZER_TOUCH_IN_RANGE);
	void release(uint8_t f = 0, uint8_t b = DIGITIZER_TOUCH_IN_RANGE);
	bool isPressed(uint8_t f = 0, uint8_t b = DIGITIZER_TOUCH_IN_RANGE);
};
