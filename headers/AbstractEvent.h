// AbstractEvent.h
#include <ctime>
#include <string>
#ifndef ABSTRACTEVENT_H
#define ABSTRACTEVENT_H

class AbstractEvent {
public:
    AbstractEvent(const std::string& description, time_t start, time_t end);

    // Getter methods
    const std::string& getDescription() const;
    time_t getStartTime() const;
    time_t getEndTime() const;

    // Setter methods
    void setDescription(const std::string& description);
    void setStartTime(time_t start);
    void setEndTime(time_t end);

    // Pure virtual methods
    virtual bool hasMoreOccurrences() const = 0;
    virtual time_t nextOccurrence() const = 0;
    virtual void init() = 0;
    virtual time_t lastOccurrence() const = 0;
    virtual bool hasRecurrenceOn(const time_t&) const = 0;
    virtual std::string toString() const = 0;
    virtual void printAllRecurrences() const = 0;
protected:
    std::string description_;
    time_t startTime_;
    time_t endTime_;
};

#endif