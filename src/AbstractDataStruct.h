#ifndef ABSTRACT_DATA_STRUCT_H
#define ABSTRACT_DATA_STRUCT_H
#include <string>
#include <ctime>

class AbstractDataStruct{
public:
    virtual std::string getName() const = 0;
    virtual std::time_t getDate() const = 0;
    virtual std::string getTitle() const = 0;
    virtual void print() const = 0;
    virtual void setBoolFields(std::string, bool) = 0;
    virtual std::string toCSVString() = 0;
    virtual ~AbstractDataStruct() = default;
};





#endif