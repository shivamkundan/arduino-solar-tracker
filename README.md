# Arduino Solar Tracker

[![Docs](https://img.shields.io/badge/docs-online-blue)](https://shivamkundan.github.io/arduino-solar-tracker)

This Arduino project calculates solar elevation, azimuth, and direct irradiance based on user input.

## 📌 Description

This Arduino code calculates:
- **Solar elevation angle** (degrees above the horizon)
- **Solar azimuth angle** (degrees from North, clockwise 0°–360°)
- **Estimated direct solar irradiance** (W/m²) using the Haurwitz clear-sky model

### 📥 Input Format (via Serial Monitor)
year,month,day,hour,minute,second


### 💡 Example Input
2025,6,13,22,14,0


### 📤 Output
The program prints:
- Solar Elevation (degrees)
- Solar Azimuth (from North, clockwise)
- Estimated Irradiance (W/m²)
- Time zone offset (UTC-5 or UTC-6, auto-adjusted for DST)

### ✅ Features
- Automatically adjusts for **Daylight Saving Time** (U.S. rules since 2007)
- Accurate solar position using simplified NOAA/SPA models
- Location set to **Carbondale, IL** (latitude 37.7272, longitude -89.2168)

## 🧭 Validity Range

| Component            | Valid Years      | Notes |
|---------------------|------------------|-------|
| Solar Position       | 1901 – 2099      | Within ~0.5° accuracy of high-precision models |
| Daylight Saving Time| 2007 – Present   | U.S. rules per Energy Policy Act |
| Leap Year Logic      | 1582 – 2400+     | Gregorian calendar valid |
| Irradiance Model     | All years        | Clear-sky estimate only |

## 🛠 How to Use

1. Connect your Arduino or ESP32 to your computer
2. Open the **Serial Monitor** at **115200 baud**
3. Enter date/time in the format shown above
4. View real-time solar elevation, azimuth, and irradiance data

## 📄 Documentation
This project includes Doxygen-compatible documentation in `solar_tracker.h`.
You can generate a wiki-style HTML output by running:

```bash
doxygen Doxyfile
