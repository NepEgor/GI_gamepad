#include "hidclass.h"
#include "hiddescriptor.h"

HIDMultitouch::HIDMultitouch(USBHID& HID, uint8_t reportID) 
    : HIDReporter(HID, NULL, (uint8_t*)&report, sizeof(report), reportID)
{
    report.buttons = 0;

    report.finger = 0;
    report.x = 0;
    report.y = 0;
}

void HIDMultitouch::move(uint16 x, uint16 y, uint8_t f)
{
    report.x = x;
    report.y = y;
    report.finger = f;

    sendReport();
}

void HIDMultitouch::buttons(uint8_t f, uint8_t b)
{
    report.buttons = b;
    report.finger = f;
    
    sendReport();
}

void HIDMultitouch::click(uint8_t f, uint8_t b)
{
    press(f, b);
    release(f, b);
}

void HIDMultitouch::press(uint8_t f, uint8_t b)
{
	buttons(f, report.buttons | b);
}

void HIDMultitouch::release(uint8_t f, uint8_t b)
{
	buttons(f, report.buttons & ~b);
}

void HIDMultitouch::click(uint16_t x, uint16_t y, uint8_t f, uint8_t b)
{
    press(x, y, f, b);
    release(x, y, f, b);
}

void HIDMultitouch::press(uint16_t x, uint16_t y, uint8_t f, uint8_t b)
{
    report.x = x;
    report.y = y;
    buttons(f, report.buttons | b);
}

void HIDMultitouch::release(uint16_t x, uint16_t y, uint8_t f, uint8_t b)
{
    report.x = x;
    report.y = y;
    buttons(f, report.buttons & ~b);
}