#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "AbstractEvent.h"

class Comparator {
public:
    virtual ~Comparator() = default;
    virtual bool compare(AbstractEvent& e1, AbstractEvent& e2) const = 0;
};

#endif // COMPARATOR_H
