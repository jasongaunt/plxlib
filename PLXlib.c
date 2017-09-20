#include "PLXlib.h";

char PLX_Decode_iMFD(int sensor, int units, int value, double *result) {
  switch (sensor) {
    case PLX_SENSOR_WIDEBAND_AIR_FUEL:
      switch (units) {
        case PLX_UNITS_WIDEBAND_AIR_FUEL_LAMBDA:   *result = ((value / 3.75) + 68) / 100;    return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_GASOLINE: *result = ((value / 2.55) + 100) / 10;    return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_DIESEL:   *result = ((value / 2.58) + 100) / 10;    return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_METHANOL: *result = ((value / 5.856) + 43.5) / 10;  return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_ETHANOL:  *result = ((value / 4.167) + 61.7) / 10;  return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_LPG:      *result = ((value / 2.417) + 105.6) / 10; return 1; break;
        case PLX_UNITS_WIDEBAND_AIR_FUEL_CNG:      *result = ((value / 2.18) + 117) / 10;    return 1; break;
      }; break;
    case PLX_SENSOR_EXHAUST_GAS_TEMPERATURE:
      switch (units) {
        case PLX_UNITS_EGT_CELSIUS:                 *result = value;                  return 1; break;
        case PLX_UNITS_EGT_FAHRENHEIT:              *result = ((value / 0.555) + 32); return 1; break;
      }; break;
    case PLX_SENSOR_FLUID_TEMPERATURE:
      switch (units) {
        case PLX_UNITS_FLUID_TEMP_WATER_CELSIUS:
        case PLX_UNITS_FLUID_TEMP_OIL_CELSIUS:      *result = value;                  return 1; break;
        case PLX_UNITS_FLUID_TEMP_WATER_FAHRENHEIT:
        case PLX_UNITS_FLUID_TEMP_OIL_FAHRENHEIT:   *result = ((value / 0.555) + 32); return 1; break;
      }; break;
    case PLX_SENSOR_AIR_INTAKE_TEMPERATURE:
      switch (units) {
        case PLX_UNITS_AIR_INTAKE_TEMP_CELSIUS:    *result = value;                  return 1; break;
        case PLX_UNITS_AIR_INTAKE_TEMP_FAHRENHEIT: *result = ((value / 0.555) + 32); return 1; break;
      }; break;
    case PLX_SENSOR_VACUUM:
      switch (units) {
        case PLX_UNITS_VAC_BOOST_INHG: *result = -((value / 11.39) - 29.93); return 1; break;
        case PLX_UNITS_VAC_BOOST_MMHG: *result = -((value * 2.23) + 760.4);  return 1; break;
      }; break;
    case PLX_SENSOR_BOOST:
      switch (units) {
        case PLX_UNITS_VAC_BOOST_PSI_0_30:
        case PLX_UNITS_VAC_BOOST_PSI_0_15:
        case PLX_UNITS_VAC_BOOST_PSI_0_60: *result = value / 22.73;  return 1; break;
        case PLX_UNITS_VAC_BOOST_KGCM_0_2:
        case PLX_UNITS_VAC_BOOST_KGCM_0_1:
        case PLX_UNITS_VAC_BOOST_KGCM_0_4: *result = value / 329.47; return 1; break;
      }; break;
    case PLX_SENSOR_RPM:
      switch (units) {
        case PLX_UNITS_REVOLUTIONS_PER_MINUTE: *result = value * 19.55; return 1; break;
      }; break;
    case PLX_SENSOR_VEHICLE_SPEED:
      switch (units) {
        case PLX_UNITS_SPEED_MPH: *result = value / 6.39; return 1; break;
        case PLX_UNITS_SPEED_KPH: *result = value / 3.97; return 1; break;
      }; break;
    case PLX_SENSOR_THROTTLE_POSITION:
      switch (units) {
        case PLX_UNITS_THROTTLE_POSITION_PERCENT: *result = value; return 1; break;
      }; break;
    case PLX_SENSOR_ENGINE_LOAD:
      switch (units) {
        case PLX_UNITS_ENGINE_LOAD_PERCENT: *result = value; return 1; break;
      }; break;
    case PLX_SENSOR_FUEL_PRESSURE:
      switch (units) {
        case PLX_UNITS_FLUID_PRES_FUEL_PSI:
        case PLX_UNITS_FLUID_PRES_OIL_PSI:   *result = value / 5.115; return 1; break;
        case PLX_UNITS_FLUID_PRES_FUEL_KGCM:
        case PLX_UNITS_FLUID_PRES_OIL_KGCM:  *result = value / 72.73; return 1; break;
        case PLX_UNITS_FLUID_PRES_FUEL_BAR:
        case PLX_UNITS_FLUID_PRES_OIL_BAR:   *result = value / 74.22; return 1; break;
      }; break;
    case PLX_SENSOR_TIMING:
      switch (units) {
        case PLX_UNITS_ENGINE_TIMING_DEGREES: *result = value - 64; return 1; break;
      }; break;
    case PLX_SENSOR_MAP:
      switch (units) {
        case PLX_UNITS_MAP_KPA:  *result = value;         return 1; break;
        case PLX_UNITS_MAP_INHG: *result = value / 3.386; return 1; break;
      }; break;
    case PLX_SENSOR_MAF:
      switch (units) {
        case PLX_UNITS_MAF_GS:    *result = value;        return 1; break;
        case PLX_UNITS_MAF_LBMIN: *result = value / 7.54; return 1; break;
      }; break;
    case PLX_SENSOR_SHORT_TERM_FUEL_TRIM:
      switch (units) {
        case PLX_UNITS_STFT_PERCENT: *result = value - 100; return 1; break;
      }; break;
    case PLX_SENSOR_LONG_TERM_FUEL_TRIM:
      switch (units) {
        case PLX_UNITS_LTFT_PERCENT: *result = value - 100; return 1; break;
      }; break;
    case PLX_SENSOR_FUEL_LEVEL:
      switch (units) {
        case PLX_UNITS_FUEL_LEVEL_PERCENT: *result = value - 100; return 1; break;
      }; break;
    case PLX_SENSOR_NARROWBAND_OXYGEN_SENSOR:
      switch (units) {
        case PLX_UNITS_NARROWBAND_AIR_FUEL_PERCENT: *result = value;         return 1; break;
        case PLX_UNITS_NARROWBAND_AIR_FUEL_VOLTS:   *result = value / 78.43; return 1; break;
      }; break;
    case PLX_SENSOR_VOLT_METER:
      switch (units) {
        case PLX_UNITS_VOLTAGE: *result = value / 51.15; return 1; break;
      }; break;
    case PLX_SENSOR_KNOCK:
      switch (units) {
        case PLX_UNITS_KNOCK_VOLTAGE: *result = value / 204.6; return 1; break;
      }; break;
    case PLX_SENSOR_DUTY_CYCLE:
      switch (units) {
        case PLX_UNITS_DUTY_CYCLE_POSITIVE: *result = value / 10.23;        return 1; break;
        case PLX_UNITS_DUTY_CYCLE_NEGATIVE: *result = 100 - (value / 10.23); return 1; break;
      }; break;
  }
  return 0; // No valid combination of sensor vs units could be found
}

