#ifndef JOB_DATA_STRUCT_H
#define JOB_DATA_STRUCT_H
#include <string>
#include <ctime>
#include "AbstractDataStruct.h"

class JobDataStruct : public AbstractDataStruct {
public:
    JobDataStruct();
    JobDataStruct(std::string name, std::string title, int id =0);
    JobDataStruct(std::string, std::string, std::time_t,bool, bool, bool, int);

    std::string getName() const;
    std::time_t getDate() const;
    std::string getTitle() const;
    void print() const;
    void setBoolFields(std::string field, bool val);
    std::string toCSVString();
private:
    std::string name, title;
    std::time_t time_created;
    bool phone_screen;
    bool onsite;
    bool offer;
    int id;
    void setPhone(bool val);
    void setOnsite(bool val);
    void setOffer(bool val);
};

#endif