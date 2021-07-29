#pragma once

#include "hid_def.h"

static const uint8_t MultitouchReportDescriptor[] = {
    HID_USAGE_PAGE(DIGITIZER),
    HID_USAGE(TOUCH_SCREEN),
    HID_COLLECTION(APPLICATION),
        HID_REPORT_ID(HID_DIGITIZER_REPORT_ID),
        HID_USAGE(FINGER),
        HID_COLLECTION(LOGICAL),

            HID_USAGE(TIP_SWITCH),
            HID_USAGE(IN_RANGE),
            HID_LOGICAL_MINIMUM(1, 0),
            HID_LOGICAL_MAXIMUM(1, 1),
            HID_REPORT_SIZE(1),
            HID_REPORT_COUNT(8),
            HID_INPUT(DATA, VARIABLE, ABSOLUTE),

            HID_USAGE(CONTACT_IDENTIFIER),
            HID_REPORT_SIZE(8),
            HID_REPORT_COUNT(1),
            HID_INPUT(DATA, VARIABLE, ABSOLUTE),

            HID_USAGE_PAGE(GENERIC_DESKTOP),
            HID_USAGE(POINTER),
            HID_COLLECTION(PHYSICAL),

                HID_USAGE(X),
                HID_LOGICAL_MINIMUM(2, 0),
                HID_LOGICAL_MAXIMUM(2, 1440),
                HID_PHYSICAL_MINIMUM(2, 0),
                HID_PHYSICAL_MAXIMUM(2, 1440),
                HID_UNIT(NONE),
                HID_REPORT_SIZE(12),
                HID_REPORT_COUNT(1),
                HID_INPUT(DATA, VARIABLE, ABSOLUTE),

                HID_USAGE(Y),
                HID_LOGICAL_MINIMUM(2, 0),
                HID_LOGICAL_MAXIMUM(2, 2960),
                HID_PHYSICAL_MINIMUM(2, 0),
                HID_PHYSICAL_MAXIMUM(2, 2960),
                HID_UNIT(NONE),
                HID_REPORT_SIZE(12),
                HID_REPORT_COUNT(1),
                HID_INPUT(DATA, VARIABLE, ABSOLUTE),

            HID_END_COLLECTION(PHYSICAL),
        HID_END_COLLECTION(LOGICAL),
    HID_END_COLLECTION(APPLICATION),
};
