#include "header.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {	
	ToDoList* list = new ToDoList;

	fstream file;
	file.open("tasks.txt", fstream::in | fstream::out);
	try {
		filePrint(file);
	}
	catch(const runtime_error& e) {
		cout << e.what() << endl;
	}

	char pick = choose();

	if (pick == '1') {
		Task* newTask = new Task;
		setName(newTask);
		list->addTask(newTask);


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
