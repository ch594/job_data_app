#ifndef ADD_PROCESSOR_H
#define ADD_PROCESSOR_H
#include "AbstractProcessor.h"

class AddProcessor: public AbstractProcessor{

public:
    void process(const std::vector<std::string>&, AbstractDataContainer*);

};


#endif