#ifndef UPDATE_PROCESSOR
#define UPDATE_PROCESSOR
#include "AbstractDataContainer.h"
#include "AbstractProcessor.h"
#include <unordered_set>

class UpdateProcessor :public AbstractProcessor{
public:
    void process(const std::vector<std::string>&, AbstractDataContainer*);
private:
	const std::unordered_set<std::string> update_fields = {"phone", "interview", "offer"};
	bool is_number(const std::string &s);
};


#endif