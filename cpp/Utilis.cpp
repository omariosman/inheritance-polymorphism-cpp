#include "Utilis.h"
#include <iomanip>
#include <sstream>
using namespace std;

string Utilis::timeToString(const time_t& time) {
    struct tm* timeinfo = localtime(&time);
    char buffer[80];
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", timeinfo);
    return string(buffer);
}

time_t Utilis::createTime(int year, int month, int day, int hour, int minute) {
    struct tm timeinfo;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = 0;
    timeinfo.tm_isdst = -1;
    return mktime(&timeinfo);
}
