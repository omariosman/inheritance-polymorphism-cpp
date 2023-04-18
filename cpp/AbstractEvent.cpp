// AbstractEvent.cpp
#include "AbstractEvent.h"

AbstractEvent::AbstractEvent(const std::string& description, time_t start, time_t end)
: description_(description), startTime_(start), endTime_(end) {}

const std::string& AbstractEvent::getDescription() const {
    return description_;
}

time_t AbstractEvent::getStartTime() const {
    return startTime_;
}

time_t AbstractEvent::getEndTime() const {
    return endTime_;
}

void AbstractEvent::setDescription(const std::string& description) {
    description_ = description;
}

void AbstractEvent::setStartTime(time_t start) {
    startTime_ = start;
}

void AbstractEvent::setEndTime(time_t end) {
    endTime_ = end;
}
