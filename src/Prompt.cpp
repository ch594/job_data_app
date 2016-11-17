#include "Prompt.h"
#include "AddProcessor.h"
#include "ViewProcessor.h"
#include "AbstractDataContainer.h"
#include "UpdateProcessor.h"
#include "SaveProcessor.h"
#include "OpenProcessor.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

Prompt::Prompt(){
    job_data = jobContainerFactory();

}

Prompt::~Prompt(){
    delete job_data;
}
void Prompt::start(){
    getInput();
}

void Prompt::printPrompt(){
    cout<<">: " <<flush;
}

void Prompt::getInput(){

    string input;
    printPrompt();
    while(getline(cin, input)){
        vector<string> words; 
        //cout <<input<<endl;
        stringstream ss(input);
        string buf;
        while( ss >> buf){
            words.push_back(buf);
        }   
        if(words.empty() || !validCommand(words[0])){
            cout<<"Invalid command"<<endl;
        }
        else if(words[0] == "exit"){
            return;
        }
        else{
            AbstractProcessor *processor = processorFactory(words[0]);
            if(processor != nullptr) processor->process(words, job_data);
        }

        printPrompt();
    }
    cout<<endl;
}

bool Prompt::validCommand(std::string command){
    return !(commands.find(command) == commands.end());
}

void Prompt::processInput(const std::vector<std::string>&){

}

AbstractDataContainer* Prompt::jobContainerFactory(){
    return new JobDataContainer();
}


AbstractProcessor* Prompt::processorFactory(string command){
    if(command == "add"){
        return new AddProcessor();
    }
    else if(command == "view"){
        return new ViewProcessor();
    }
    else if(command == "update"){
        return new UpdateProcessor();
    }
    else if(command =="save"){
        return new SaveProcessor();
    }
    else if(command =="open"){
        return new OpenProcessor();
    }
    else{
        return nullptr;
    }
}