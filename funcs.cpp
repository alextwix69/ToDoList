#include "header.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

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

	tasks.pop_back();
}

void filePrint(fstream& file) {
	cout << endl;
	if (!file.is_open()) {
		throw std::runtime_error("file hasn't been opened");
	}

	string currentS;
	while (getline(file, currentS)) {
		cout << currentS << endl;
	}
}

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
