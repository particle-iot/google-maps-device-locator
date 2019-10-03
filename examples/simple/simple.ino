#include "google-maps-device-locator.h"

// Uncomment to show debugging logs
// SerialLogHandler logHandler(LOG_LEVEL_TRACE);

GoogleMapsDeviceLocator locator;

void setup() {
	Serial.begin(9600);
	locator.withLocatePeriodic(120); 
}

void loop() {
	locator.loop();
}

