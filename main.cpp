#include "header.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {	
	ToDoList* list = new ToDoList;
	fstream file;
	file.open("tasks.txt", fstream::in);
	try {
		filePrint(file);
	}
	catch(const runtime_error& e) {
		cout << e.what() << endl;
	}
	file.close();
	char pick = choose();

	if (pick == '1') {
		Task* newTask = new Task;
		setName(newTask);
		list->addTask(newTask);

		file.open("tasks.txt", fstream::app);
		file << newTask->name.c_str() << endl << newTask->description << endl << "Incompleted" << endl;

		file << "#end#" << endl; //#end# - key, which means the end of a task
		file.close();
	}

	if (pick == '2') {
        
	}
    
    if (pick == '3') {
        
    }
    
    if (pick == '4') {
        
    }
	return 1;
}
//
