#include "functions/Database_functions.h"

HashMap* hashMapArray[101] = { NULL };

int main(){
    Table* table = createTable("student");
    
    RedBlackTree* tableIndex = createIndex("student");
    
    int num1 = addRecord("student", "studentNumber", "1", "generalCourseName", "Math", "generalCourseInstructor", "Ali", "generalCourseScore", "19", "coreCourseName", "Physics", "coreCourseInstructor", "Mahmoud", "coreCourseScore", "20");
    int num2 = addRecord("student", "studentNumber", "2", "generalCourseName", "Programming", "generalCourseInstructor", "Emad", "generalCourseScore", "17", "coreCourseName", "Chemistry", "coreCourseInstructor", "Mohammad", "coreCourseScore", "18");
    int num3 = addRecord("student", "studentNumber", "3", "generalCourseName", "English", "generalCourseInstructor", "Ahmed", "generalCourseScore", "15", "coreCourseName", "Biology", "coreCourseInstructor", "Hassan", "coreCourseScore", "16");
    int num4 = addRecord("student", "studentNumber", "4", "generalCourseName", "History", "generalCourseInstructor", "Ali", "generalCourseScore", "13", "coreCourseName", "Geography", "coreCourseInstructor", "Omar", "coreCourseScore", "14");

    printf("\nTable after adding records:\n");
    displayRecords(table);
    (num1 != -1) ? insertRedBlackTree(tableIndex, num1) : printf("Record already exists\n");
    (num2 != -1) ? insertRedBlackTree(tableIndex, num2) : printf("Record already exists\n");
    (num3 != -1) ? insertRedBlackTree(tableIndex, num3) : printf("Record already exists\n");
    (num4 != -1) ? insertRedBlackTree(tableIndex, num4) : printf("Record already exists\n");

    deleteRecord("student", "generalCourseInstructor", "Ali");
    tableIndex = createIndex("student");
    printf("\nTable after deleting records:\n");
    displayRecords(table);

    updateRecord("student", "coreCourseInstructor", "Hassan", "Mohammad");
    printf("\nTable after updating records:\n");
    displayRecords(table);

    int num5 = addRecord("student", "studentNumber", "4", "generalCourseName", "Alian", "generalCourseInstructor", "Ali", "generalCourseScore", "19", "coreCourseName", "Physics", "coreCourseInstructor", "Mahmoud", "coreCourseScore", "20");
    int num6 = addRecord("student", "studentNumber", "1", "generalCourseName", "History", "generalCourseInstructor", "Ali", "generalCourseScore", "13", "coreCourseName", "Geography", "coreCourseInstructor", "Mohammad", "coreCourseScore", "14");
    (num5 != -1) ? insertRedBlackTree(tableIndex, num5) : printf("Record already exists\n");
    (num6 != -1) ? insertRedBlackTree(tableIndex, num6) : printf("Record already exists\n");

    printf("\nTable after sorting records by coreCourseInstructor:\n");
    selectRecord("student", "coreCourseInstructor", "Mohammad", 1);

    printf("\nTable after selecting records by coreCourseInstructor:\n");
    selectRecord("student", "coreCourseInstructor", "Mohammad", 0);
}