#include "header.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {	
	ToDoList* list = new ToDoList;
	fstream file;
	file.open("tasks.bin", fstream::in | fstream::binary);
	try {
		list->writeToVector(file);
	}
	catch(const runtime_error& e) {
		cout << e.what() << endl;
	}
	file.close();

	while (true) {
		list->vectorOutput();

		char pick = choose();

		if (pick == '1') {
			Task* newTask = new Task;
			setName(newTask);
			list->addTask(newTask);

			file.open("tasks.bin", fstream::app | fstream::binary);
			file << newTask->name.c_str() << endl << newTask->description << endl << "Incompleted" << endl;

			file << "#end#" << endl; //#end# - key, which means the end of a task
			file.close();
		}

		if (pick == '2') {
			list->switchTask(); 
		}
		
		if (pick == '3') {
			list->eraseTask();
		}
		
		if (pick == '4') {
			ofstream fileToDel;
			fileToDel.open("tasks.bin", ios::trunc);
			fileToDel.close();

			fstream file;
			file.open("tasks.bin", fstream::app | fstream::binary);
			fileRewrite(file, list);
			file.close();
			break;
		}
	}
	return 1;
}
//
