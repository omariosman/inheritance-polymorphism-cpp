#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include "AbstractEvent.h"
#include "Comparator.h"

class Planner {
public:
    Planner(int capacity);
    ~Planner();

    int size() const;
    bool addEvent(AbstractEvent* event);
    AbstractEvent* eventAt(int pos) const;
    void display(time_t date) const;
    void sort(const Comparator& comp);
    std::string toString() const;
    AbstractEvent* getEvent(const std::string& name);
    AbstractEvent* remove(const int pos);
    std::vector<AbstractEvent*> getEvents();
private:
    std::vector<AbstractEvent*> events;
    int capacity;
};

#endif // PLANNER_H
