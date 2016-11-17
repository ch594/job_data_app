#include "AddProcessor.h"
#include <iostream>
using namespace std;

void AddProcessor::process(const std::vector<std::string> &commands, AbstractDataContainer *job_data){
    if(commands.size() != 3){
        cout<<"Add expects 2 arguments"<<endl;
    }
    else{
        job_data->add(commands[1], commands[2]);
    }

}