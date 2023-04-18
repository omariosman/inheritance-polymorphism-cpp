// LastOccComparator.h
#ifndef LASTOCCCOMPARATOR_H
#define LASTOCCCOMPARATOR_H

#include "Comparator.h"

class LastOccComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // LASTOCCCOMPARATOR_H
