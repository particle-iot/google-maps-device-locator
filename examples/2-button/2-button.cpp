#include "google-maps-device-locator.h"

// Comment this line out to disable debugging logs or change to LOG_LEVEL_INFO for fewer logs
SerialLogHandler logHandler(LOG_LEVEL_TRACE);

GoogleMapsDeviceLocator locator;
const pin_t buttonPin = D2;
unsigned long lastPublish = 0;
const std::chrono::milliseconds minimumPublishPeriod = 20s;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
	locator.loop();

    if (digitalRead(buttonPin) == LOW) {
        if (lastPublish == 0 || millis() - lastPublish >= minimumPublishPeriod.count()) {
            lastPublish = millis();

            locator.publishLocation();
        }
    }
}

