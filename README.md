# Google Maps Device Locator

**Library for using the Google Maps Device Locator Integration**

This library work with the [Google Maps Device Locator Integration](https://docs.particle.io/tutorials/integrations/google-maps/) to find a location based on Wi-Fi or cellular tower information via the [Google Geolocation API](https://developers.google.com/maps/documentation/geolocation/intro).


## Firmware Library API

### Creating an object

You normally create an locator object as a global variable in your program:

```
GoogleMapsDeviceLocator locator;
```

### Operating modes

There are three modes of operation:

If you want to only publish the location once when the device starts up, use withLocateOnce from your setup function.

```
locator.withLocateOnce();
```

To publish every *n* seconds while connected to the cloud, use withLocatePeriodic. The value is in seconds.

```
locator.withLocatePeriodic(120);
```

To manually connect, specify neither option and call publishLocation when you want to publish the location

```
locator.publishLocation();
```

### The loop

With periodic and locate once modes, you must call 

```
locator.loop();
```

from your loop. It doesn't hurt to always call it, even in manual location mode. It gives the library time to process the data.

### Customizing the event name

The default event name is **deviceLocator**. You can change that in setup using:

```
locator.withEventName("myEventName");
```

This also must be updated in the integration, since the eventName is what triggers the webhook. 

### Subscription

You can also have the library tell your firmware code what location was found. Use the withSubscribe option with a callback function.

This goes in setup() for example:

```
locator.withSubscribe(locationCallback).withLocatePeriodic(120);
```

The callback function looks like this:

```
void locationCallback(float lat, float lon, float accuracy)
```

One possibility is that you could display this information on a small OLED display, for example.

### Debugging

The library uses the logging feature of system firmware 0.6.0 or later when building for 0.6.0 or later. Adding this line to the top of your .ino file will enable debugging messages to the serial port.

```
SerialLogHandler logHandler;
```

### Special Notes for LTE (SARA-R410M-02B)

For LTE devices, it's strongly recommended to use this library with Device OS 1.2.1 or later only. 

The Boron LTE and B Series B402 SoM both require 1.2.1 to use the device locator and will not work with older versions of Device OS.

If you must use a version of Device OS older than 1.2.1:

- The Boron LTE cannot use the device locator with Device OS older than 1.2.1
- The E Series LTE and Electron LTE require the use of the `withOperator()` method to manually set the MCC, MNC, and operator if not 

The `withOperator(const char *oper, int mcc, int mnc)` method of the locator object allows you to pass in this information. The default is "AT&T", 310, 410.

Note that because `withOperator()` is no longer needed with Device OS 1.2.1 and later, it will eventually be removed.


## Version History

#### 0.0.7 (2020-08-12)

- Fix compiler warning with 2.0.0.

#### 0.0.6 (2019-10-03)

- Added support for the Boron LTE and B Series B402 SoM when using Device OS 1.2.1 and later.
- The `withOperator()` function is no longer needed for LTE when using Device OS 1.2.1 and later. 


#### 0.0.5 (2018-11-27) 

- Added support for LTE in the United States, upgrade to CellularHelper 0.0.7



