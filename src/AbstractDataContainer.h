#ifndef ABSTRACT_DATA_CONTAINER_H
#define ABSTRACT_DATA_CONTAINER_H
#include <string>
#include <vector>
#include <fstream>
#include "AbstractDataStruct.h"

class AbstractDataContainer{

public:
    virtual void add(std::string, std::string) = 0;
    virtual const std::vector<AbstractDataStruct*>* get(std::string) const = 0;
    virtual bool JobDataExists(const std::string&) const = 0;
    virtual bool JobDataExists(const std::string&, int) const = 0;
    virtual void saveToFile(std::ofstream &out) = 0;
    virtual void openFromFile(std::ifstream &in) = 0;
    virtual ~AbstractDataContainer(){}

};

#endif