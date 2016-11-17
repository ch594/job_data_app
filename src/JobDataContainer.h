#ifndef JOB_DATA_CONTAINER_H
#define JOB_DATA_CONTAINER_H 
#include "AbstractDataStruct.h"
#include "AbstractDataContainer.h"
#include <unordered_map>
#include <string>

class JobDataContainer: public AbstractDataContainer{

public:
    JobDataContainer();
    void add(std::string, std::string);
    const std::vector<AbstractDataStruct*>* get(std::string) const;
    bool JobDataExists(const std::string&) const;
    bool JobDataExists(const std::string&, int) const;
    void saveToFile(std::ofstream &out);
    void openFromFile(std::ifstream &in);
    ~JobDataContainer();

private:
    void add(std::string, std::string, std::time_t,bool, bool, bool, int);
    std::unordered_map<std::string, std::vector<AbstractDataStruct*>* > jobs;
    std::vector<AbstractDataStruct*>* get(std::string);
    static AbstractDataStruct* JobDataFactory(std::string, std::string, int);
    static AbstractDataStruct* JobDataFactory(std::string, std::string,
    								 std::time_t,bool, bool, bool, int);
    std::vector<std::string> splitByDelim(const std::string&, char);
};

#endif