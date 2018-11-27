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

The E Series LTE has a slightly different command set than the SARA-U and SARA-G used in the previous Electrons. It is unfortunately missing the environment command (AT+CGED) used to get the cellular tower information.

You can still get approximate (1 tower) location information in the United States on AT&T, which is currently the only place you can use the E Series LTE.

Because there is no efficient command to get the operator, MCC, and MNC on the LTE modem, if you are using a 3rd-party SIM card in a Boron LTE, you would need to pass the information in manually. Thus you can only get location information if you know approximately where you are. This is not ideal, but better than nothing. The `withOperator(const char *oper, int mcc, int mnc)` method of the locator object allows you to pass in this information.

The default is "AT&T", 310, 410.

## Version History

- 0.0.5 (2018-11-27) Added support for LTE in the United States, upgrade to CellularHelper 0.0.7



