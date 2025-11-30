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
		if (size == 0) {
			throw std::invalid_argument("cannot add empty name");
		}
		else {
			throw std::invalid_argument("cannot add name longer than 50 symbols");
		}
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