#include <Arduino.h>

#include "hidclass.h"
#include "button.h"

USBHID HID;
HIDMultitouch USBMultitouch(HID);

const uint16_t MAX_X = 1440;
const uint16_t MAX_Y = 2960;

Button attack_b;
Button skill_b;
Button jump_b;
Button dash_b;

void setup()
{
    HID.setReportDescriptor(MultitouchReportDescriptor, sizeof(MultitouchReportDescriptor));
    HID.registerComponent();

    USBComposite.begin();
    while(!USBComposite);

    delay(300);
    /*
    attack_b.init(MAX_X * 0.23, MAX_Y * 0.80, 1, &USBMultitouch);
    skill_b.init (MAX_X * 0.14, MAX_Y * 0.72, 2, &USBMultitouch);
    jump_b.init  (MAX_X * 0.35, MAX_Y * 0.88, 3, &USBMultitouch);
    dash_b.init  (MAX_X * 0.14, MAX_Y * 0.88, 4, &USBMultitouch);
    */
    attack_b.init(MAX_X * 0.77, MAX_Y * 0.20, 1, &USBMultitouch);
    skill_b.init (MAX_X * 0.86, MAX_Y * 0.28, 2, &USBMultitouch);
    jump_b.init  (MAX_X * 0.65, MAX_Y * 0.12, 3, &USBMultitouch);
    dash_b.init  (MAX_X * 0.86, MAX_Y * 0.12, 4, &USBMultitouch);

    pinMode(PA1, INPUT_PULLDOWN);
    pinMode(PA2, INPUT_PULLDOWN);
    pinMode(PA3, INPUT_PULLDOWN);
    pinMode(PA4, INPUT_PULLDOWN);
}

void loop()
{
    attack_b.toggle(digitalRead(PA1));
    skill_b.toggle(digitalRead(PA2));
    jump_b.toggle(digitalRead(PA3));
    dash_b.toggle(digitalRead(PA4));
}
