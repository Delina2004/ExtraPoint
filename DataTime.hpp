#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <string>

class DateTime {
private:
    int year, month, day, hour, minute, second, timezone_offset;

public:
    DateTime(int y, int m, int d, int h, int min, int sec, int tz_offset);
    void adjustToTimeZone(int new_offset);
    void adjustForDST(bool isDST);
    std::string getDayOfWeek();
    int getDaysInMonth();
    std::string serialize();
    static DateTime deserialize(const std::string& str);
    void display();
};

#endif // DATETIME_HPP
