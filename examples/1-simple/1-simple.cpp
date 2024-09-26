#include "google-maps-device-locator.h"

// Comment this line out to disable debugging logs or change to LOG_LEVEL_INFO for fewer logs
SerialLogHandler logHandler(LOG_LEVEL_TRACE);

GoogleMapsDeviceLocator locator;

void setup() {
	locator.withLocatePeriodic(120); 
}

void loop() {
	locator.loop();
}

