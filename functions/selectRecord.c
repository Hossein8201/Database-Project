#include "Database_functions.h"

void selectRecord(const char* tableName, const char* column, const char* value, int sorted) {
    unsigned int index = hash(tableName);
    HashMap* currentTable = hashMapArray[index];
    while (currentTable) {
        if (strcmp(currentTable->table->tableName, tableName) == 0) {
            break;
        }
        currentTable = currentTable->next;
    }

    Table* temporaryTable = createTable("Temporary Table");
    Record* currentRecord = currentTable->table->head;
    while (currentRecord) {
        if (
            (strcmp(column, "studentNumber") == 0 && currentRecord->studentNumber == atoi(value)) ||
            (strcmp(column, "generalCourseName") == 0 && strcmp(currentRecord->generalCourseName, value) == 0) ||
            (strcmp(column, "generalCourseInstructor") == 0 && strcmp(currentRecord->generalCourseInstructor, value) == 0) ||
            (strcmp(column, "generalCourseScore") == 0 && currentRecord->generalCourseScore == atoi(value)) ||
            (strcmp(column, "coreCourseName") == 0 && strcmp(currentRecord->coreCourseName, value) == 0) ||
            (strcmp(column, "coreCourseInstructor") == 0 && strcmp(currentRecord->coreCourseInstructor, value) == 0) ||
            (strcmp(column, "coreCourseScore") == 0 && currentRecord->coreCourseScore == atoi(value))
        ) {
            char studentNumberString[10];
            sprintf(studentNumberString, "%d", currentRecord->studentNumber);
            char generalCourseNameString[33];
            strcpy(generalCourseNameString, currentRecord->generalCourseName);
            char generalCourseInstructorString[33];
            strcpy(generalCourseInstructorString, currentRecord->generalCourseInstructor);
            char generalCourseScoreString[10];
            sprintf(generalCourseScoreString, "%d", currentRecord->generalCourseScore);
            char coreCourseNameString[33];
            strcpy(coreCourseNameString, currentRecord->coreCourseName);
            char coreCourseInstructorString[33];
            strcpy(coreCourseInstructorString, currentRecord->coreCourseInstructor);
            char coreCourseScoreString[10];
            sprintf(coreCourseScoreString, "%d", currentRecord->coreCourseScore);
            addRecord(
                "Temporary Table",
                "studentNumber", studentNumberString,
                "generalCourseName", generalCourseNameString,
                "generalCourseInstructor", generalCourseInstructorString,
                "generalCourseScore", generalCourseScoreString,
                "coreCourseName", coreCourseNameString,
                "coreCourseInstructor", coreCourseInstructorString,
                "coreCourseScore", coreCourseScoreString
            );
        }
        currentRecord = currentRecord->next;
    }
    if (sorted == 1) {
        temporaryTable = sortedRecords(temporaryTable);
    }
    displayRecords(temporaryTable);
    deleteTable(temporaryTable->tableName);
}