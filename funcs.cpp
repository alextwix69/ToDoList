#include "header.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>


/*

	ToDoList Funstions

*/


void ToDoList::addTask(Task* actual) {
	tasks.push_back(*actual);
}

void ToDoList::renameTask(Task& actual, string newName) {
	size_t size = newName.size();
	if (size <= 50 && size != 0) {
		actual.name = newName;
	}
	else {
		throw std::invalid_argument("invalid name");
	}
}

void ToDoList::switchTask(Task& actual) {
	actual.completed = !actual.completed;
}

int ToDoList::getQuant(){
	return tasks.size();
}

void ToDoList::writeToVector(fstream& file) {
	if (!file.is_open()) {
		throw std::runtime_error("file has not been opened");
	}
	string currentS;
	short i = 1; // 1 - name, 2 - desc, 3 - completed
	while (getline(file, currentS)) {
		size_t n = tasks.size();

		if (currentS == "#end#" || n == 0) {
			tasks.resize(n + 1);
			n++;
		}
		
		if (currentS != "#end#") {
			switch (i % 3) {
				case 1: tasks[n - 1].name = currentS; break;
				case 2: tasks[n - 1].description = currentS; break;
				case 0: tasks[n - 1].completed = (currentS == "Completed"); break;
			}
			i++;
		}
			
	}
	if (tasks.size() != 0) {
		tasks.pop_back();
	}
}

void ToDoList::vectorOutput() {
	cout << "---------------------------------------------------------------" << endl;

	int taskAmount = tasks.size();
	cout << "Task amount:\t" << taskAmount << endl;

	int completedCount = 0;
	for (int i = 0; i < taskAmount; i++) {
		if (tasks[i].completed == true) {
			completedCount++;
		}
	}

	cout << "Completed:\t" << completedCount << endl;
	cout << "Incompleted:\t" << taskAmount - completedCount << endl;
	cout << endl;

	for (int current = 1; current <= taskAmount; current++) {
		cout << "Task " << current << ":" << endl;
		cout << tasks[current - 1].name << endl;
		cout << tasks[current - 1].description << endl;
		if (tasks[current - 1].completed) {
			cout << "Completed" << endl;
		}
		else {
			cout << "Incompleted" << endl;
		}
		cout << endl;
	}
}

void ToDoList::switchTask() {
	int taskNum = 0;
	int i = 0;
	while (taskNum == 0 || taskNum > tasks.size()) {
		if (i > 0) {
			cout << "choose existing task" << endl;
		}
		else {
			cout << "choose task" << endl;
		}
        
		cin >> taskNum;

		i++;
	}
	tasks[taskNum - 1].completed = !tasks[taskNum - 1].completed;
}

void ToDoList::eraseTask() {
	int taskNum = 0;
	int i = 0;
	while (taskNum == 0 || taskNum > tasks.size()) {
		if (i > 0) {
			cout << "choose existing task" << endl;
		}
		else {
			cout << "choose task" << endl;
		}
        
		cin >> taskNum;

		i++;
	}
	tasks.erase(tasks.begin() + taskNum - 1);
}

string ToDoList::getInfo(int task, int info) {
	switch (info) {
		case 1: return tasks[task].name;
		case 2: return tasks[task].description;
		case 3:
			if (tasks[task].completed) {
				return "Completed";
			}
			else {
				return "Incompleted";
			}
	}
	return "invalid input";
}
/*
string ToDoList::TESTFUNC(int n) {
	if (n > tasks.size() - 1) {
		return "failed";
	}
	string s = "";
	s.append(tasks[n].name);
	s.append(" ");
	s.append(tasks[n].description);
	s.append(" ");
	if (tasks[n].completed) {
		s.append("True");
	}
	else {
		s.append("False");
	}
	return s;
}
*/

/*

	Other Functions

*/


void setName(Task* task) {
	string taskName = "";
	int i = 0;
	cout << "set task name" << endl;
	while (taskName.length() == 0 || taskName.length() > 50) {
		if (i > 0) {
			cout << "put from 1 to 50 symbols" << endl;
		}
		
		getline(cin, taskName);
		if (taskName.length() != 0) {
			i++;
		}			
	}

	task->name = taskName;

	string desc = "";
	i = 0;
	cout << "add task description" << endl;
	while (desc.length() == 0) {
		if (i > 0) {
			cout << "put at least 1 symbol" << endl;
		}
		i++;
		getline(cin, desc);
	}
	task->description = desc;
	return;
}

char choose() {
	cout << endl;
	char pick = {}; //pick
	int i = 0;
	while (pick - '0' > 4 || pick - '0' < 1) {
		if (i > 0) {
			cout << "Put a valid number" << endl;
		}

		cout << "1 - add task" << endl
			<< "2 - switch complete status" << endl
			<< "3 - erase task" << endl
			<< "4 - save n exit" << endl;
		cin >> pick;
	
		i++;
	}
	return pick;
}

void fileRewrite(fstream& file, ToDoList* list) {
	for (int t = 0; t < list->getQuant(); t++) {
		for (int i = 1; i <= 3; i++) {
			file << list->getInfo(t, i) << endl;
		}
		file << "#end#" << endl;
	}
}

