#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "header.h"

TEST_CASE("ToDoList class test") {
    ToDoList testList;
    Task* testTask = new Task;

    SUBCASE ("getQuant() | addTask()") {
        CHECK(testList.getQuant() == 0);

        testList.addTask(testTask);

        CHECK(testList.getQuant() == 1);

        for (int i = 0; i < 9; i++) {
            testList.addTask(testTask);
        }

        CHECK(testList.getQuant() == 10);
    }

    SUBCASE ("renameTask()") {
        CHECK(testTask->name == "new task");

        testList.renameTask(*testTask, "test name");

        CHECK(testTask->name == "test name");

        try {
            testList.renameTask(*testTask, "");
        }
        catch (const invalid_argument& e) {
            CHECK(e.what() == string("invalid name"));
        }

        try {
            testList.renameTask(*testTask, "this name is too long to be valid 676767676767676767676767676767");                                                                      
        }
        catch (const invalid_argument& e) {
            CHECK(e.what() == string("invalid name"));
        }
        
    }

    SUBCASE ("switchTask()") {
        CHECK(testTask->completed == false);

        testList.switchTask(*testTask);

        CHECK(testTask->completed == true);

        testList.switchTask(*testTask);

        CHECK(testTask->completed == false);
    }
}