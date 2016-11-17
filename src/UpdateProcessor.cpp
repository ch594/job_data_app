
#include "UpdateProcessor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "AbstractDataStruct.h"
using namespace std;

void UpdateProcessor::process(const std::vector<std::string> &command, AbstractDataContainer* job_c){
	int id;
	if(command.size() != 5){
		cout<<"Update expects four arguments. [Company name] [field name]"<<
				" [local id] [yes/no]"<<endl;
	}
	else if(update_fields.find(command[2]) == update_fields.end()){
		cout<<"That field does not exist."<<endl;
	}
	else if(!is_number(command[3])){
		cout<<"Enter a positive integer for the locale id of the job you want to update"
			<<endl;
	}
	else if(!(command[4] == "yes" || command[4] == "no")){
		cout<<"Invalid value to update field with"<<endl;
	}
	else if(!job_c->JobDataExists(command[1], id = stoi(command[3]))){
		cout<<"Job with that company name and/or id does not exist"<<endl;
	}
	else{
		const vector<AbstractDataStruct*> *job_vector = job_c->get(command[1]);
		bool val = (command[4] == "yes") ? true: false;
		(*job_vector)[id]->setBoolFields(command[2], val);
	}
}


bool UpdateProcessor::is_number(const std::string& s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}