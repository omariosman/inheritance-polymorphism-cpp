// DailyEvent.h
#include "AbstractEvent.h"
#ifndef DAILYEVENT_H
#define DAILYEVENT_H

class DailyEvent : public AbstractEvent {
public:
    DailyEvent(const std::string& description, time_t start, time_t end, int numRecurrences);
    // Getter and setter methods for numRecurrences_
    int getNumRecurrences() const;
    void setNumRecurrences(int numRecurrences);

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
    int numRecurrences_;
    mutable int currentRecurrence_;
};

#endif