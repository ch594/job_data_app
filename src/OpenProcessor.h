#ifndef LOAD_PROCESSOR_H
#define LOAD_PROCESSOR_H
#include "AbstractDataContainer.h"
#include "AbstractProcessor.h"
#include <string>

class OpenProcessor :public AbstractProcessor{
public:
    void process(const std::vector<std::string>&, AbstractDataContainer*);
private:
	const std::string file_name = "job.data";
};


#endif