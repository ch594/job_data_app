CC = g++
CFLAGS = -Wall -std=c++11 -c
LFLAGS = -Wall
OBJS = main.o JobDataStruct.o JobDataContainer.o Prompt.o AddProcessor.o \
		ViewProcessor.o UpdateProcessor.o SaveProcessor.o OpenProcessor.o
S_DIR = src

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o job_data_app

main.o : $(S_DIR)/main.cpp
	$(CC) $(CFLAGS) $(S_DIR)/main.cpp 

JobDataStruct.o: $(S_DIR)/JobDataStruct.cpp $(S_DIR)/JobDataStruct.h
	$(CC) $(CFLAGS) $(S_DIR)/JobDataStruct.cpp

JobDataContainer.o: $(S_DIR)/JobDataContainer.cpp $(S_DIR)/JobDataContainer.h \
					$(S_DIR)/JobDataStruct.h
	$(CC) $(CFLAGS) $(S_DIR)/JobDataContainer.cpp

Prompt.o: $(S_DIR)/JobDataContainer.cpp $(S_DIR)/Prompt.h $(S_DIR)/ViewProcessor.h \
$(S_DIR)/AddProcessor.h $(S_DIR)/AbstractDataStruct.h $(S_DIR)/UpdateProcessor.h \
$(S_DIR)/OpenProcessor.h
	$(CC) $(CFLAGS) $(S_DIR)/Prompt.cpp

AddProcessor.o: $(S_DIR)/AddProcessor.cpp $(S_DIR)/AddProcessor.h 
	$(CC) $(CFLAGS) $(S_DIR)/AddProcessor.cpp

ViewProcessor.o: $(S_DIR)/ViewProcessor.cpp $(S_DIR)/ViewProcessor.h \
	$(S_DIR)/AbstractDataStruct.h 
	$(CC) $(CFLAGS) $(S_DIR)/ViewProcessor.cpp

UpdateProcessor.o: $(S_DIR)/UpdateProcessor.cpp $(S_DIR)/UpdateProcessor.h \
	$(S_DIR)/AbstractDataStruct.h 
	$(CC) $(CFLAGS) $(S_DIR)/UpdateProcessor.cpp

SaveProcessor.o: $(S_DIR)/SaveProcessor.cpp $(S_DIR)/SaveProcessor.h \
	$(S_DIR)/AbstractDataStruct.h 
	$(CC) $(CFLAGS) $(S_DIR)/SaveProcessor.cpp

OpenProcessor.o: $(S_DIR)/OpenProcessor.cpp $(S_DIR)/OpenProcessor.h \
	$(S_DIR)/AbstractDataStruct.h 
	$(CC) $(CFLAGS) $(S_DIR)/OpenProcessor.cpp
clean:
	rm -rf *.o job_data_app