# DateTime Class Enhancement Project

This project implements a `DateTime` class in C++ that handles time zone conversions, daylight saving time adjustments, calendar operations, and serialization/deserialization. The goal is to demonstrate object-oriented programming concepts in C++ while enhancing the functionality of the `DateTime` class.

## Features

1. **Time Zone Conversion:**
   - Adjusts a `DateTime` object to a different time zone.

2. **Daylight Saving Time (DST) Adjustments:**
   - Adds one hour to the time for DST when required.

3. **Day of the Week Calculation:**
   - Calculates the day of the week using Zeller's Congruence algorithm.

4. **Days in Month Calculation:**
   - Returns the number of days in the given month, accounting for leap years in February.

5. **Serialization and Deserialization:**
   - Serializes a `DateTime` object to a string.
   - Deserializes a string back into a `DateTime` object.

## File Structure

The project is divided into three files:

1. **`DateTime.hpp`** - Header file that declares the `DateTime` class.
2. **`DateTime.cpp`** - Source file that implements the methods of the `DateTime` class.
3. **`main.cpp`** - Main program that demonstrates the use of the `DateTime` class.

## Compilation Instructions

To compile the project, use the following command:

```bash
g++ -o DateTimeApp DateTime.cpp main.cpp
