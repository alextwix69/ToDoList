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

		if (pick == '5') {
			string p{};
			cout << "are you sure? (Y)" << endl;			
			cin >> p;
			if (p == "Y") {
				break;
			}
		}
	}
	return 1;
}
//
