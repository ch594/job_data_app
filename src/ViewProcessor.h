#ifndef VIEW_PROCESSOR_H
#define VIEW_PROCESSOR_H
#include "AbstractProcessor.h"

class ViewProcessor : public AbstractProcessor{
public:
    void process(const std::vector<std::string>&, AbstractDataContainer*);
private:
    
};

#endif