#include <iostream>
#include "DateTime.hpp"

int main() {
    DateTime dt(2024, 12, 13, 10, 30, 45, -300); // Dec 13, 2024, 10:30:45 AM UTC-5 (Eastern Standard Time)
    dt.display();

    // Adjust time to UTC
    dt.adjustToTimeZone(0);
    std::cout << "Adjusted to UTC: ";
    dt.display();

    // Handle DST (e.g., if DST is in effect)
    dt.adjustForDST(true);
    std::cout << "Adjusted for DST: ";
    dt.display();

    // Get day of the week
    std::cout << "Day of the week: " << dt.getDayOfWeek() << std::endl;

    // Get number of days in the month
    std::cout << "Days in month: " << dt.getDaysInMonth() << std::endl;

    // Serialize to string
    std::string serialized = dt.serialize();
    std::cout << "Serialized DateTime: " << serialized << std::endl;

    // Deserialize from string
    DateTime deserialized = DateTime::deserialize(serialized);
    std::cout << "Deserialized DateTime: ";
    deserialized.display();

    return 0;
}
