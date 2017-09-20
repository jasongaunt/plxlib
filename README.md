# PLXlib
PLX iMFD Serial Libraries for Arduino and compatibles

PLXlib is a small library intended for use with Arduinos to interact with their iMFD-compatible devices such as the SM-AFR Wideband O2 Sensor.

Please pay close attention to the LICENSE file - there is absolutely no warranty implied using this library and you do so at your own risk. Although it could support generating serial messages, it's intended for logging (read-only) use only. Misuse could result in an expensive repair bill or worse.

The best starting point is PLXlib.h - this file outlines all the constants used by the library and associated functions.

The most useful function this library provides is *PLX_Decode_iMFD* - this lets you convert iMFD values to human readable format;

```C
// PLX_Decode_iMFD - Converts raw iMFD serial value to human-readable format
// This function returns char 1 or 0 as TRUE or FALSE if the value was decoded successfully
// Params:
// int sensor     - the sensor the reading came from
// int units      - the type of measurement units of data
// int value      - the raw value of measurement units
// double &result - pointer to store the converted value
char PLX_Decode_iMFD(int sensor, int units, int value, double *result);
```

Usage example:

```C
double mydata;
char successful;

void example() {
  successful = PLX_Decode_iMFD(
    PLX_SENSOR_WIDEBAND_AIR_FUEL,
    PLX_UNITS_WIDEBAND_AIR_FUEL_GASOLINE,
    10,
    &mydata
  );
}
```

If you can think of any improvements, please fork and offer a merge request with clear and concise documentation.
