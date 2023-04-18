// DescriptionComparator.h
#ifndef DESCRIPTIONCOMPARATOR_H
#define DESCRIPTIONCOMPARATOR_H

#include "Comparator.h"

class DescriptionComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // DESCRIPTIONCOMPARATOR_H