#include "DateTime.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>

DateTime::DateTime(int y, int m, int d, int h, int min, int sec, int tz_offset)
    : year(y), month(m), day(d), hour(h), minute(min), second(sec), timezone_offset(tz_offset) {}

void DateTime::adjustToTimeZone(int new_offset) {
    int diff = new_offset - timezone_offset;
    int total_minutes = (hour * 60 + minute) + diff;
    hour = (total_minutes / 60) % 24;
    minute = total_minutes % 60;
    timezone_offset = new_offset;
}

void DateTime::adjustForDST(bool isDST) {
    if (isDST) {
        hour += 1; // Add one hour for DST
    }
}

std::string DateTime::getDayOfWeek() {
    int m = month;
    int y = year;
    if (m <= 2) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int day_of_week = (day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    switch (day_of_week) {
    case 0: return "Saturday";
    case 1: return "Sunday";
    case 2: return "Monday";
    case 3: return "Tuesday";
    case 4: return "Wednesday";
    case 5: return "Thursday";
    case 6: return "Friday";
    default: return "Unknown";
    }
}

int DateTime::getDaysInMonth() {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
        return 28;
    default:
        return 0;
    }
}

std::string DateTime::serialize() {
    std::ostringstream oss;
    oss << year << "-" << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day << " "
        << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second << " UTC"
        << (timezone_offset >= 0 ? "+" : "") << timezone_offset / 60 << ":" << std::setw(2) << std::setfill('0') << std::abs(timezone_offset % 60);
    return oss.str();
}

DateTime DateTime::deserialize(const std::string& str) {
    std::istringstream iss(str);
    int y, m, d, h, min, sec, tz_offset;
    char dash, colon, space, plus, colon2;
    if (!(iss >> y >> dash >> m >> dash >> d >> space >> h >> colon >> min >> colon >> sec >> space >> plus >> tz_offset)) {
        throw std::invalid_argument("Invalid format");
    }
    tz_offset *= 60;  // Convert to minutes
    return DateTime(y, m, d, h, min, sec, tz_offset);
}

void DateTime::display() {
    std::cout << "DateTime: " << serialize() << std::endl;
}
