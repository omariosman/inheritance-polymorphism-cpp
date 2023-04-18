#include "Planner.h"
#include "AbstractEvent.h"
#include <algorithm>
#include <iostream>
using namespace std;

Planner::Planner(int capacity) : capacity(capacity) {}

Planner::~Planner() {
    for (AbstractEvent* event : events) {
        delete event;
    }
}

int Planner::size() const {
    return events.size();
}

bool Planner::addEvent(AbstractEvent* event) {
    if (size() < capacity) {
        events.push_back(event);
        return true;
    }
    return false;
}

AbstractEvent* Planner::eventAt(int pos) const {
    return events.at(pos);
}

AbstractEvent* Planner::remove(const int pos) {
    AbstractEvent* removedEvent = events.at(pos);
    events.erase(events.begin() + pos);
    return removedEvent;
}

void Planner::display(time_t date) const {
    for (const auto& event : events) {
        if (event->hasRecurrenceOn(date)) {
            std::cout << event->toString() << std::endl;
        }
    }
}

void Planner::sort(const Comparator& comp) {
    std::sort(events.begin(), events.end(),
              [&](AbstractEvent* e1, AbstractEvent* e2) { return comp.compare(*e1, *e2); });
}

std::string Planner::toString() const {
    std::string result;
    for (const auto& event : events) {
        result += event->toString() + "\n";
    }
    return result;
}

AbstractEvent* Planner::getEvent(const std::string& name) {
    for (const auto& e : events) {
        if (e->getDescription() == name) {
            return e;
        }
    }
    return nullptr;
}

std::vector<AbstractEvent*> Planner::getEvents() {
    return events;
}
