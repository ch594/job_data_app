#ifndef ABSTRACT_PROCESSOR_H
#define ABSTRACT_PROCESSOR_H 
#include <vector>
#include <string>
#include "AbstractDataContainer.h"

class AbstractProcessor{
public:
    virtual void process(const std::vector<std::string>&, AbstractDataContainer*) = 0;
    virtual ~AbstractProcessor() = default;

};

#endif