// WeeklyEvent.h
#ifndef WEEKLYEVENT_H
#define WEEKLYEVENT_H

#include "AbstractEvent.h"

class WeeklyEvent : public AbstractEvent {
public:
    WeeklyEvent(const std::string& description, time_t start, time_t end, time_t limit);
    // Getter and setter methods for limit_
    time_t getLimit() const;
    void setLimit(time_t limit);

    // Overrides of pure virtual methods in AbstractEvent
    bool hasMoreOccurrences() const override;
    time_t nextOccurrence() const override;
    void init() override;
    time_t lastOccurrence() const override;
    bool hasRecurrenceOn(const time_t&) const override;
    std::string toString() const override;
    // Method to print all recurrences of the event
    void printAllRecurrences() const override;
private:
    time_t limit_;
    mutable time_t currentStartTime_;
};
#endif