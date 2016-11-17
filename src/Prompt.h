#ifndef PROMPT_H
#define PROMPT_H
#include <unordered_set>
#include "JobDataContainer.h"
#include "AbstractDataContainer.h"
#include "JobDataContainer.h"
#include "AbstractProcessor.h"
//#include <vector>

class Prompt{

public:
    Prompt();
    void start();
    ~Prompt();
private:
    void printPrompt();
    void getInput();
    bool validCommand(std::string);
    void processInput(const std::vector<std::string>&);
    static AbstractDataContainer* jobContainerFactory();
    static AbstractProcessor* processorFactory(std::string);
    std::unordered_set<std::string> commands = 
            {"view", "add","update", "save", "open", "exit"};
    AbstractDataContainer *job_data;
};

#endif