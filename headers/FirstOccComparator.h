// FirstOccComparator.h
#ifndef FIRSTOCCCOMPARATOR_H
#define FIRSTOCCCOMPARATOR_H
#include "AbstractEvent.h"
#include "Comparator.h"

class FirstOccComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // FIRSTOCCCOMPARATOR_H