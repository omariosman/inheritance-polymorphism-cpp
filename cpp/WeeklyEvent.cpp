// WeeklyEvent.cpp
#include "WeeklyEvent.h"
#include <ctime>
#include<cmath>
#include <sstream>
#include<iostream>
using namespace std;
#include "Utilis.h"

WeeklyEvent::WeeklyEvent(const std::string& description, time_t start, time_t end, time_t limit)
: AbstractEvent(description, start, end), limit_(limit), currentStartTime_(start) {}

time_t WeeklyEvent::getLimit() const {
    return limit_;
}

void WeeklyEvent::setLimit(time_t limit) {
    limit_ = limit;
}

bool WeeklyEvent::hasMoreOccurrences() const {
    return currentStartTime_ < limit_;
}

time_t WeeklyEvent::nextOccurrence() const {
    if (hasMoreOccurrences()) {
        time_t next = currentStartTime_;
        currentStartTime_ += 86400 * 7; // 86400 seconds in a day * 7 days
        return next;
    }
    return 0;
}

void WeeklyEvent::init() {
    currentStartTime_ = startTime_;
}

time_t WeeklyEvent::lastOccurrence() const {
    time_t diff = (limit_ - startTime_) / (86400 * 7);
    return startTime_ + diff * 86400 * 7;
}
/*
bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    time_t days = (date - startTime_) / 86400;
    return days >= 0 && days % 7 == 0 && date < limit_;
}

bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    // Normalize the input date and start time to midnight (00:00:00)
    time_t normalized_date = date - date % 86400;
    time_t normalized_start_time = startTime_ - startTime_ % 86400;

    time_t days = (normalized_date - normalized_start_time) / 86400;
    return days >= 0 && days % 7 == 0 && normalized_date < limit_;
}

bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    tm start_tm = *localtime(&startTime_);
    tm date_tm = *localtime(&date);
    
    // Calculate the weekday (0-6, Sunday = 0) of the event's start time and the given date
    int start_weekday = start_tm.tm_wday;
    int date_weekday = date_tm.tm_wday;
    
    // Check if the given date's weekday matches the event's start time weekday
    if (start_weekday != date_weekday) {
        return false;
    }
    
    time_t days = (date - startTime_) / 86400;
    return days >= 0 && days % 7 == 0 && date < limit_;
}

bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    tm start_tm = *localtime(&startTime_);
    tm date_tm = *localtime(&date);
    
    // Calculate the weekday (0-6, Sunday = 0) of the event's start time and the given date
    int start_weekday = start_tm.tm_wday;
    int date_weekday = date_tm.tm_wday;
    
    // Check if the given date's weekday matches the event's start time weekday
    if (start_weekday != date_weekday) {
        return false;
    }
    
    time_t days = (date - startTime_) / 86400;
    double weeks_passed = static_cast<double>(days) / 7;
    // Check if weeks_passed is a whole number
    return weeks_passed >= 0 && floor(weeks_passed) == weeks_passed && date < limit_;
}


bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    time_t days = (date - startTime_) / 86400;
    bool result = days >= 0 && days % 7 == 0 && date < limit_;
    std::cout << "WeeklyEvent: " << getDescription() << ", date: " << Utilis::timeToString(date)
              << ", startTime_: " << Utilis::timeToString(startTime_) << ", days: " << days
              << ", result: " << result << std::endl;
    return result;
}

bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    tm date_tm = *localtime(&date);
    tm start_tm = *localtime(&startTime_);

    bool same_weekday = date_tm.tm_wday == start_tm.tm_wday;
    time_t days = (date - startTime_) / 86400;

    bool result = days >= 0 && days % 7 == 0 && date < limit_ && same_weekday;

    // Debugging output
    
    std::cout << "WeeklyEvent: " << getDescription() << ", date: " << Utilis::timeToString(date)
              << ", startTime_: " << Utilis::timeToString(startTime_) << ", days: " << days
              << ", same_weekday: " << same_weekday << ", result: " << result << std::endl;

    return result;
}
*/
bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    tm date_tm = *localtime(&date);
    tm start_tm = *localtime(&startTime_);

    // Adjust the given date to the start and end times of the event
    date_tm.tm_hour = start_tm.tm_hour;
    date_tm.tm_min = start_tm.tm_min;
    date_tm.tm_sec = start_tm.tm_sec;
    time_t adjusted_date = mktime(&date_tm);

    bool same_weekday = date_tm.tm_wday == start_tm.tm_wday;
    time_t days = (adjusted_date - startTime_) / 86400;

    bool result = days >= 0 && days % 7 == 0 && adjusted_date < limit_ && same_weekday;

    return result;
}

std::string WeeklyEvent::toString() const {
    std::stringstream ss;
    ss << "WeeklyEvent { description= " << description_ << ", start: " <<  Utilis::timeToString(startTime_)
    << ", end: " <<  Utilis::timeToString(endTime_) << ", limit: " <<  Utilis::timeToString(limit_) << " }";
    return ss.str();
}

void WeeklyEvent::printAllRecurrences() const {
    time_t current_time = startTime_;
    int recurrence_count = 0;
    while (current_time <= limit_) {
        cout << asctime(gmtime(&current_time)) << endl;
        current_time += 7 * 24 * 60 * 60; // Move to the next week (7 days * 24 hours * 60 minutes * 60 seconds)
        ++recurrence_count;
    }
}