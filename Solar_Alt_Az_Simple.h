#ifndef SOLAR_TRACKER_H
#define SOLAR_TRACKER_H

#include <Arduino.h>

/**
 * @brief Computes the day of the year (1–365/366) from a given date.
 * 
 * @param year  Gregorian calendar year (e.g., 2025)
 * @param month Month of year (1–12)
 * @param day   Day of month (1–31)
 * @return int  Day of year (1–366)
 */
int dayOfYear(int year, int month, int day);

/**
 * @brief Calculates fractional year (gamma) in radians for solar geometry.
 * 
 * @param doy   Day of year (1–366)
 * @param hour  Hour in 24-hour format (0–23)
 * @return float Gamma in radians
 */
float getGamma(int doy, int hour);

/**
 * @brief Computes solar declination angle in radians.
 * 
 * @param gamma Fractional year (radians)
 * @return float Declination angle in radians
 */
float getDeclination(float gamma);

/**
 * @brief Computes solar hour angle in radians.
 * 
 * @param gamma     Fractional year (radians)
 * @param longitude Longitude of the observer (degrees, negative for West)
 * @param hour      Local hour (0–23)
 * @param minute    Minute (0–59)
 * @param second    Second (0–59)
 * @param tz_offset Time zone offset from UTC (e.g., -5 for CDT)
 * @return float    Hour angle in radians
 */
float getHourAngle(float gamma, float longitude, int hour, int minute, int second, int tz_offset);

/**
 * @brief Estimates direct solar irradiance using the Haurwitz clear-sky model.
 * 
 * @param elevation_deg Solar elevation angle in degrees
 * @return float        Estimated direct irradiance in W/m²
 */
float getIrradiance(float elevation_deg);

/**
 * @brief Determines whether a given date/time is in Daylight Saving Time (U.S. rules, post-2007).
 * 
 * @param year  Year (e.g., 2025)
 * @param month Month (1–12)
 * @param day   Day of month
 * @param hour  Local hour (0–23)
 * @return true If DST is active
 * @return false If Standard Time is active
 */
bool isDST(int year, int month, int day, int hour);

/**
 * @brief Computes and prints solar elevation, azimuth, and irradiance.
 * 
 * @param latitude  Observer latitude (degrees, positive = North)
 * @param longitude Observer longitude (degrees, negative = West)
 * @param year      Year (e.g., 2025)
 * @param month     Month (1–12)
 * @param day       Day of month (1–31)
 * @param hour      Local hour (0–23)
 * @param minute    Minute (0–59)
 * @param second    Second (0–59)
 * @param tz_offset Time zone offset from UTC (e.g., -5 for CDT)
 */
void computeSolar(float latitude, float longitude, int year, int month, int day,
                  int hour, int minute, int second, int tz_offset);

#endif // SOLAR_TRACKER_H
