#include "JobDataContainer.h"
#include "JobDataStruct.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

JobDataContainer::JobDataContainer(){
}

JobDataContainer::~JobDataContainer(){
    for(auto it: jobs){
        for(auto j: *(it.second)){
            delete j;
        }
        delete it.second;
    }
}

void JobDataContainer::add(std::string name, std::string title){
    if(JobDataExists(name)){
        std::vector<AbstractDataStruct*> *v = get(name);
        AbstractDataStruct *j = JobDataFactory(name, title, v->size());
        v->push_back(j);
    }
    else{
        std::vector<AbstractDataStruct*> *v = new std::vector<AbstractDataStruct*>();
        AbstractDataStruct *j = JobDataFactory(name, title, 0);
        v->push_back(j);
        jobs[name] = v;
    }


}

void JobDataContainer::add(std::string name, std::string title,
    std::time_t t_c, bool phone, bool offer, bool interview, int id){
    if(JobDataExists(name)){
        std::vector<AbstractDataStruct*> *v = get(name);
        AbstractDataStruct *j = JobDataFactory(name, title, t_c, 
                                        phone, offer, interview,id);
        v->push_back(j);
    }
    else{
        std::vector<AbstractDataStruct*> *v = new std::vector<AbstractDataStruct*>();
        AbstractDataStruct *j = JobDataFactory(name, title, t_c, 
                                        phone, offer, interview,id);
        v->push_back(j);
        jobs[name] = v;
    }


}


const std::vector<AbstractDataStruct*>* JobDataContainer::get(std::string name) const{
    const auto it = jobs.find(name);
    return it->second;

}

std::vector<AbstractDataStruct*>* JobDataContainer::get(std::string name){
    
    auto ptr = (jobs[name]);
    return ptr;
}



AbstractDataStruct* JobDataContainer::JobDataFactory(std::string name, std::string title, int id){
    return new JobDataStruct(name, title, id);
}

AbstractDataStruct* JobDataContainer::JobDataFactory(std::string name, 
    std::string title, std::time_t t_c, bool phone, bool offer,
    bool interview, int id){
    return new JobDataStruct(name, title, t_c, phone, offer, interview,id);
}

bool JobDataContainer::JobDataExists(const std::string &name) const{
    return !(jobs.find(name) == jobs.end());
}


bool JobDataContainer::JobDataExists(const std::string &name, int id) const{
    using namespace std;
    if(JobDataExists(name)){
        const std::vector<AbstractDataStruct*> *v = get(name);
        return id >= 0 && id < v->size();
    }
    return false;
}

void JobDataContainer::saveToFile(std::ofstream &out){
    for(auto it: jobs){
        for(auto j: *(it.second)){
            out << j->toCSVString() <<std::endl;
        }
    }
}

void JobDataContainer::openFromFile(std::ifstream &in){
    using namespace std;
    string line;
    while(getline(in,line)){
        vector<string> fields = splitByDelim(line, ',');
        assert(fields.size() == 7);
        string name = fields[0];
        string title = fields[1];
        time_t t_c = stoi(fields[2]);
        bool p = (fields[3] == "1") ? true : false; 
        bool o = (fields[4] == "1") ? true : false; 
        bool i = (fields[5] == "1") ? true : false; 
        int id = stoi(fields[6]);
        add(name, title, t_c, p, o, i, id);        
    }
}

std::vector<std::string> JobDataContainer::splitByDelim(const std::string &str, char delim){
    using namespace std;
    vector<string> fields;
    size_t prev = 0;
    for(size_t i = 0; i < str.size(); i++){
        if(str[i] == delim){
            fields.push_back(str.substr(prev, i - prev));
            prev = i+1;
        }
    }
    if(prev <str.size()){
        fields.push_back(str.substr(prev));
    }
    return fields;
}