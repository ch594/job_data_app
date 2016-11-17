#include "ViewProcessor.h"
#include <iostream>
#include <vector>
#include "AbstractDataStruct.h"
using namespace std;

void ViewProcessor::process(const std::vector<std::string> &commands, AbstractDataContainer *job_data){
    if(commands.size() != 2){
        cout<<"View expects 1 arguments"<<endl;
    }
    else if(job_data->JobDataExists(commands[1])){
        const vector<AbstractDataStruct*> *job_vector = job_data->get(commands[1]);
        for(size_t i = 0; i < job_vector->size(); i++){
            AbstractDataStruct *job_struct = (*job_vector)[i];
            job_struct->print();
        }
    }
    else{
        cout<<"Job record not found"<<endl;
    }

}