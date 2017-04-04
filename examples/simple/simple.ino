#include "google-maps-device-locator.h"

GoogleMapsDeviceLocator locator;

SYSTEM_THREAD(ENABLED);

void setup() {
	Serial.begin(9600);
	locator.withLocatePeriodic(120); 
}

void loop() {
	locator.loop();
}

