#include "Header.h"
#include <vector>
#include <stdexcept>
#include <iostream>

void ToDoList::addTask(Task* actual) {
	if (actual != nullptr) {
		tasks.push_back(*actual);
	}
	else {
		throw std::invalid_argument("task hasn't been found");
	}
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

void filePrint(ifstream& file) {
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
		i++;
		cin >> taskName;
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
		cin >> desc;		
	}
	task->description = desc;
	return;
}

char choose() {
	cout << endl;
	char dec = {}; //decision
	int i = 0;
	while (dec - '0' > 4 || dec - '0' < 1) {
		if (i > 0) {
			cout << "введите цифру от 1 до 4" << endl;
		}

		cout << "1 - add task" << endl
			<< "2 - switch complete status" << endl
			<< "3 - erase task" << endl
			<< "4 - save n exit" << endl;
		cin >> dec;

		i++;
	}
	return dec;
}
