#include <Arduino.h>

#include "hidclass.h"

USBHID HID;
HIDMultitouch USBMultitouch(HID);

void setup(){
    HID.setReportDescriptor(MultitouchReportDescriptor, sizeof(MultitouchReportDescriptor));
    HID.registerComponent();

    USBComposite.begin();
    while(!USBComposite);

    delay(300);
    
    /*
    static const uint8_t n = 30;

    for (uint8_t i = 1; i < n; ++i)
    {
        for (uint8_t j = 1; j < n; ++j)
        {
            USBMultitouch.move(1440 * i / n, 2960 * j / n);
            USBMultitouch.click();

            delay(100);
        }
    }
    */

    /*
    USBMultitouch.move(100, 100, 0);
    USBMultitouch.move(600, 300, 1);
    USBMultitouch.press(1);
    USBMultitouch.press(0);

    delay(300);

    USBMultitouch.move(100, 200, 0);
    USBMultitouch.move(600, 200, 1);
    
    delay(300);

    USBMultitouch.move(100, 300, 0);
    USBMultitouch.move(600, 100, 1);

    USBMultitouch.release(0);
    USBMultitouch.release(1);
    */

    USBMultitouch.move(1440 * 0.1, 2960 * 0.3, 0);
    USBMultitouch.move(1440 * 0.1, 2960 * 0.7, 1);

    USBMultitouch.press(0);
    USBMultitouch.press(1);

    delay(100);

    static const uint8_t n = 10;
    
    for (uint8_t i = 2; i < n; ++i)
    {
        USBMultitouch.move(1440 * i / n, 2960 * 0.3, 0);
        USBMultitouch.move(1440 * i / n, 2960 * 0.7, 1);

        delay(100);
    }

    USBMultitouch.release(0);
    USBMultitouch.release(1);

}

void loop(){
    
    
}