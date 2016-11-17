#include "SaveProcessor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <utility>
#include "AbstractDataStruct.h"
using namespace std;


void SaveProcessor::process(const std::vector<std::string> &command, AbstractDataContainer* job_c){
	if(command.size() != 1){
		cout<<"Save doens't expect any arguments"<<endl;
	}
	else{
		ofstream out;
		out.open(file_name, ios_base::out | ios_base::trunc);
		job_c->saveToFile(out);
		out.close();
	}
}