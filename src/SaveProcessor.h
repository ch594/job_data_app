#ifndef SAVE_PROCESSOR_H
#define SAVE_PROCESSOR_H
#include "AbstractDataContainer.h"
#include "AbstractProcessor.h"
#include <string>

class SaveProcessor :public AbstractProcessor{
public:
    void process(const std::vector<std::string>&, AbstractDataContainer*);
private:
	const std::string file_name = "job.data";
};


#endif