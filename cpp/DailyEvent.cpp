// DailyEvent.cpp
#include "DailyEvent.h"
#include <ctime>
#include<iostream>
#include <sstream>
using namespace std;
#include "Utilis.h"

DailyEvent::DailyEvent(const std::string& description, time_t start, time_t end, int numRecurrences)
: AbstractEvent(description, start, end), numRecurrences_(numRecurrences), currentRecurrence_(0) {}

int DailyEvent::getNumRecurrences() const {
    return numRecurrences_;
}

void DailyEvent::setNumRecurrences(int numRecurrences) {
    numRecurrences_ = numRecurrences;
}

bool DailyEvent::hasMoreOccurrences() const {
    return currentRecurrence_ < numRecurrences_;
}

time_t DailyEvent::nextOccurrence() const {
    if (hasMoreOccurrences()) {
        time_t next = startTime_ + currentRecurrence_ * 86400; // 86400 seconds in a day
        currentRecurrence_++;
        return next;
    }
    return 0;
}

void DailyEvent::init() {
    currentRecurrence_ = 0;
}

time_t DailyEvent::lastOccurrence() const {
    return startTime_ + (numRecurrences_ - 1) * 86400;
}
/*
bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    time_t days = (date - startTime_) / 86400;
    return days >= 0 && days < numRecurrences_;
}

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    // Normalize the input date and start time to midnight (00:00:00)
    time_t normalized_date = date - date % 86400;
    time_t normalized_start_time = startTime_ - startTime_ % 86400;

    time_t days = (normalized_date - normalized_start_time) / 86400;
    return days >= 0 && days < numRecurrences_;
}

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    tm start_tm = *localtime(&startTime_);
    tm date_tm = *localtime(&date);

    // Check if the given date's weekday matches the event's start time weekday
    if (start_tm.tm_wday != date_tm.tm_wday) {
        return false;
    }

    time_t days = (date - startTime_) / 86400;
    // Check if the day difference is divisible by 7 and less than the number of occurrences * 7
    return days >= 0 && days % 7 == 0 && days < numRecurrences_ * 7;
}

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    time_t days = (date - startTime_) / 86400;
    return days >= 0 && days % 1 == 0 && days < numRecurrences_;
}

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    time_t days = (date - startTime_) / 86400;
    bool result = days >= 0 && days % 1 == 0 && days < numRecurrences_;
    
    std::cout << "DailyEvent: " << getDescription() << ", date: " << Utilis::timeToString(date)
              << ", startTime_: " << Utilis::timeToString(startTime_) << ", days: " << days
              << ", result: " << result << std::endl;
    
    return result;
}
*/

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    tm date_tm = *localtime(&date);
    tm start_tm = *localtime(&startTime_);

    // Adjust the given date to the start and end times of the event
    date_tm.tm_hour = start_tm.tm_hour;
    date_tm.tm_min = start_tm.tm_min;
    date_tm.tm_sec = start_tm.tm_sec;
    time_t adjusted_date = mktime(&date_tm);

    time_t days = (adjusted_date - startTime_) / 86400;

    bool result = days >= 0 && days < numRecurrences_;

    return result;
}


std::string DailyEvent::toString() const {
    std::stringstream ss;
    ss << "DailyEvent { description= " << description_ << ", start: " << Utilis::timeToString(startTime_)
    << ", end: " << Utilis::timeToString(endTime_) << ", numberOfOccurences: " << numRecurrences_ << " }";
    return ss.str();
}

void DailyEvent::printAllRecurrences() const {
    time_t current_time = startTime_;
    for (int i = 0; i < numRecurrences_; ++i) {
        cout << asctime(gmtime(&current_time)) << endl;
        current_time += 24 * 60 * 60; // Move to the next day (24 hours * 60 minutes * 60 seconds)
    }
}
