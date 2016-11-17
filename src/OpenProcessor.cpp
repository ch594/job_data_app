#include "OpenProcessor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <utility>
#include "AbstractDataStruct.h"
using namespace std;


void OpenProcessor::process(const std::vector<std::string> &command, AbstractDataContainer* job_c){
	if(command.size() != 1){
		cout <<"Open does not expect any arguments"<<endl;
	}
	else{
		ifstream in;
		in.open(file_name);
		if(in)job_c->openFromFile(in);
	}
}