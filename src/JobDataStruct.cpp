#include "JobDataStruct.h"
#include <iostream>

JobDataStruct::JobDataStruct(std::string name, std::string title, int id)
            : name(name), title(title), phone_screen(false), onsite(false),
              offer(false), id(id)
{
    time_created = std::time(nullptr);
}

JobDataStruct::JobDataStruct(std::string name, std::string title,
    std::time_t t_created, bool p, bool o, bool i, int id)
            : name(name), title(title), time_created(t_created), 
              phone_screen(p), onsite(i), offer(o), id(id)
{
}


std::string JobDataStruct::getName() const{
    return name;
}

std::string JobDataStruct::getTitle() const{
    return title;
}

std::time_t JobDataStruct::getDate() const{
    return time_created;
}

void JobDataStruct::print() const{
    using namespace std;
    cout<<endl;
    cout<<"Company name: " <<name<<endl;
    cout<<"Job title: " <<title<<endl;
    cout <<"Date applied: "<< asctime(localtime(&time_created));
    cout<< "Phone screen: " << ((phone_screen) ? "yes" : "no") <<endl;
    cout<< "Onsite interview offer: " << ((onsite) ? "yes" : "no") <<endl;
    cout<< "Job offer: " << ((offer) ? "yes" : "no") <<endl;
    cout<<"Local id: "<<id<<endl;
}


void JobDataStruct::setBoolFields(std::string field, bool val){
    if(field == "phone") setPhone(val);
    else if(field == "offer") setOffer(val);
    else if(field == "onsite") setOnsite(val);

}

void JobDataStruct::setPhone(bool val){
    phone_screen = val;
}

void JobDataStruct::setOnsite(bool val){
    onsite = val;
}

void JobDataStruct::setOffer(bool val){
    offer = val;
}

std::string JobDataStruct::toCSVString(){
    using namespace std;
    return name +","  +title +"," + to_string(time_created) + ","+
            to_string(phone_screen) + "," + to_string(onsite) + "," + 
            to_string(onsite) +"," + to_string(id);
}