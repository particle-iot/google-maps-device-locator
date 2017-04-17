#include "google-maps-device-locator.h"

GoogleMapsDeviceLocator locator;

void setup() {
	Serial.begin(9600);
	locator.withLocatePeriodic(120); 
}

void loop() {
	locator.loop();
}

