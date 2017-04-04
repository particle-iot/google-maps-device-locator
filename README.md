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
