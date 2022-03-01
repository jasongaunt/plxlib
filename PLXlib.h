// PLXlib - library for PLX iMFD serial decoding
// Collated by Jason Gaunt based on PLX published documentation

#ifndef PLX_LIB_LOADED

// Definitions

//// Serial protocol communications

////// Real Time Streaming
#define PLX_SERIAL_RTS_BAUD          19200
#define PLX_SERIAL_RTS_CONFIG        SERIAL_8N1

////// Fast Download
#define PLX_SERIAL_FASTDL_BAUD       150000
#define PLX_SERIAL_FASTDL_CONFIG     SERIAL_8E1

//// Sensor addresses
enum PLX_SENSOR {
  PLX_SENSOR_WIDEBAND_AIR_FUEL,        // 0
  PLX_SENSOR_EXHAUST_GAS_TEMPERATURE,  // 1
  PLX_SENSOR_FLUID_TEMPERATURE,        // 2
  PLX_SENSOR_VACUUM,                   // 3
  PLX_SENSOR_BOOST,                    // 4
  PLX_SENSOR_AIR_INTAKE_TEMPERATURE,   // 5
  PLX_SENSOR_RPM,                      // 6
  PLX_SENSOR_VEHICLE_SPEED,            // 7
  PLX_SENSOR_THROTTLE_POSITION,        // 8
  PLX_SENSOR_ENGINE_LOAD,              // 9
  PLX_SENSOR_FUEL_PRESSURE,            // 10
  PLX_SENSOR_TIMING,                   // 11
  PLX_SENSOR_MAP,                      // 12
  PLX_SENSOR_MAF,                      // 13
  PLX_SENSOR_SHORT_TERM_FUEL_TRIM,     // 14
  PLX_SENSOR_LONG_TERM_FUEL_TRIM,      // 15
  PLX_SENSOR_NARROWBAND_OXYGEN_SENSOR, // 16
  PLX_SENSOR_FUEL_LEVEL,               // 17
  PLX_SENSOR_VOLT_METER,               // 18
  PLX_SENSOR_KNOCK,                    // 19
  PLX_SENSOR_DUTY_CYCLE,               // 20
  PLX_SENSOR_FUEL_EFFICIENCY,          // 21
  PLX_SENSOR_ANALOG_VOLTAGE,           // 22
  PLX_SENSOR_SPEED_HERTZ,              // 23
  PLX_SENSOR_WIDEBAND_STATUS,          // 24
  PLX_SENSOR_WIDEBAND_HEALTH,          // 25
  PLX_SENSOR_WIDEBAND_REACTION         // 26
};

//// Units

////// Wideband Air/Fuel - SM-AFR
enum PLX_UNITS_WIDEBAND_AIR_FUEL {
  PLX_UNITS_WIDEBAND_AIR_FUEL_LAMBDA,   // 0
  PLX_UNITS_WIDEBAND_AIR_FUEL_GASOLINE, // 1
  PLX_UNITS_WIDEBAND_AIR_FUEL_DIESEL,   // 2
  PLX_UNITS_WIDEBAND_AIR_FUEL_METHANOL, // 3
  PLX_UNITS_WIDEBAND_AIR_FUEL_ETHANOL,  // 4
  PLX_UNITS_WIDEBAND_AIR_FUEL_LPG,      // 5
  PLX_UNITS_WIDEBAND_AIR_FUEL_CNG       // 6
};

////// Exhaust Gas Temperature - SM-EGT
enum PLX_UNITS_EGT {
  PLX_UNITS_EGT_CELSIUS,   // 0
  PLX_UNITS_EGT_FAHRENHEIT // 1
};

////// Fluid Temperature - SM-FluidTemp
enum PLX_UNITS_FLUID {
  PLX_UNITS_FLUID_TEMP_WATER_CELSIUS,    // 0
  PLX_UNITS_FLUID_TEMP_WATER_FAHRENHEIT, // 1
  PLX_UNITS_FLUID_TEMP_OIL_CELSIUS,      // 2
  PLX_UNITS_FLUID_TEMP_OIL_FAHRENHEIT    // 3
};

////// Vacuum - SM-Vac/Boost
enum PLX_UNITS_VAC_BOOST {
  PLX_UNITS_VAC_BOOST_INHG,         // 0
  PLX_UNITS_VAC_BOOST_MMHG,         // 1

  PLX_UNITS_VAC_BOOST_PSI_0_30 = 0, // 0
  PLX_UNITS_VAC_BOOST_KGCM_0_2,     // 1
  PLX_UNITS_VAC_BOOST_PSI_0_15,     // 2
  PLX_UNITS_VAC_BOOST_KGCM_0_1,     // 3
  PLX_UNITS_VAC_BOOST_PSI_0_60,     // 4
  PLX_UNITS_VAC_BOOST_KGCM_0_4      // 5
};

////// Air Intake Temperature - SM-AIT
enum PLX_UNITS_AIR_INTAKE_TEMP {
  PLX_UNITS_AIR_INTAKE_TEMP_CELSIUS,   // 0
  PLX_UNITS_AIR_INTAKE_TEMP_FAHRENHEIT // 1
};

////// Revolutions Per Minute - OBD
enum PLX_UNITS_REVOLUTIONS {
  PLX_UNITS_REVOLUTIONS_PER_MINUTE // 0
};

////// Speed - OBD
enum PLX_UNITS_SPEED {
  PLX_UNITS_SPEED_MPH, // 0
  PLX_UNITS_SPEED_KPH  // 1
};

////// Throttle Position Sensor - OBD
enum PLX_UNITS_THROTTLE_POSITION {
  PLX_UNITS_THROTTLE_POSITION_PERCENT // 0
};

////// Engine Load - OBD
enum PLX_UNITS_ENGINE_LOAD {
  PLX_UNITS_ENGINE_LOAD_PERCENT // 0
};

////// Fluid Pressure - SM-FluidPressure
enum PLX_UNITS_FLUID_PRES {
  PLX_UNITS_FLUID_PRES_FUEL_PSI,  // 0
  PLX_UNITS_FLUID_PRES_FUEL_KGCM, // 1
  PLX_UNITS_FLUID_PRES_FUEL_BAR,  // 2
  PLX_UNITS_FLUID_PRES_OIL_PSI,   // 3
  PLX_UNITS_FLUID_PRES_OIL_KGCM,  // 4
  PLX_UNITS_FLUID_PRES_OIL_BAR    // 5
};

////// Engine Timing - OBD
enum PLX_UNITS_ENGINE_TIMING {
  PLX_UNITS_ENGINE_TIMING_DEGREES // 0
};

////// Manifold Pressure - OBD
enum PLX_UNITS_MAP {
  PLX_UNITS_MAP_KPA, // 0
  PLX_UNITS_MAP_INHG // 1
};

////// Mass Air Flow - OBD
enum PLX_UNITS_MAF {
  PLX_UNITS_MAF_GS,   // 0
  PLX_UNITS_MAF_LBMIN // 1
};

////// Fuel Trim - OBD
enum PLX_UNITS_FT {
  PLX_UNITS_STFT_PERCENT = 0, // 0
  PLX_UNITS_LTFT_PERCENT = 0  // 0
};

////// Narrowband Air/Fuel - OBD
enum PLX_UNITS_NARROWBAND_AIR_FUEL {
  PLX_UNITS_NARROWBAND_AIR_FUEL_PERCENT, // 0
  PLX_UNITS_NARROWBAND_AIR_FUEL_VOLTS    // 1
};

////// Fuel Level - OBD
enum PLX_UNITS_FUEL_LEVEL {
  PLX_UNITS_FUEL_LEVEL_PERCENT // 0
};

////// Volts - OBD
enum PLX_UNITS_VOLTS {
  PLX_UNITS_VOLTAGE // 0
};

////// Knock / Fuel Detonation - OBD
enum PLX_UNITS_KNOCK {
  PLX_UNITS_KNOCK_VOLTAGE // 0
};

////// Duty Cycle - OBD
enum PLX_UNITS_DUTY_CYCLE {
  PLX_UNITS_DUTY_CYCLE_POSITIVE, // 0
  PLX_UNITS_DUTY_CYCLE_NEGATIVE  // 1
};

////// Fuel Efficiency - OBD
enum PLX_UNITS_FUEL_EFFICIENCY {
  PLX_UNITS_FUEL_EFFICIENCY_MPG,    // 0
  PLX_UNITS_FUEL_EFFICIENCY_KM_L,   // 1
  PLX_UNITS_FUEL_EFFICIENCY_L_100KM // 2
};

////// Speed (Hertz)
enum PLX_UNITS_HERTZ {
  PLX_UNITS_SPEED_HERTZ // 0
};

////// Wideband Status - SM-AFR
enum PLX_UNITS_WIDEBAND_STATUS {
  PLX_UNITS_WIDEBAND_STATUS_HEATING_READY // 0
};

////// Wideband Health - SM-AFR
enum PLX_UNITS_WIDEBAND_HEALTH {
  PLX_UNITS_WIDEBAND_HEALTH_PERCENT // 0
};

////// Wideband Reaction Time - SM-AFR
enum PLX_UNITS_WIDEBAND_REACTION {
  PLX_UNITS_WIDEBAND_REACTION_MS // 0
};

// Functions

#ifdef __cplusplus
extern "C" {
#endif

// PLX_Decode_iMFD - Converts raw iMFD serial value to human-readable format
// This function returns char 1 or 0 as TRUE or FALSE if the value was decoded successfully
// Params:
// int sensor     - the sensor the reading came from
// int units      - the type of measurement units of data
// int value      - the raw value of measurement units
// double &result - pointer to store the converted value
char PLX_Decode_iMFD(int sensor, int units, int value, double *result);

#ifdef __cplusplus
}
#endif

#define PLX_LIB_LOADED
#endif // PLX_LIB_LOADED
