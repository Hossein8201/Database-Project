#include "Database_functions.h"

void updateRecord(const char* tableName, const char* column, const char* value, const char* newValue) {
    unsigned int index = hash(tableName);
    HashMap* currentTable = hashMapArray[index];
    while (currentTable) {
        if (strcmp(currentTable->table->tableName, tableName) == 0) {
            break;
        }
        currentTable = currentTable->next;
    }

    Record* currentRecord = currentTable->table->head;
    while (currentRecord) {
        if (strcmp(column, "studentNumber") == 0 && currentRecord->studentNumber == atoi(value)) {
            currentRecord->studentNumber = atoi(newValue);
        } else if (strcmp(column, "generalCourseName") == 0 && strcmp(currentRecord->generalCourseName, value) == 0) {
            strncpy(currentRecord->generalCourseName, newValue, sizeof(currentRecord->generalCourseName) - 1);
            currentRecord->generalCourseName[sizeof(currentRecord->generalCourseName) - 1] = '\0';
        } else if (strcmp(column, "generalCourseInstructor") == 0 && strcmp(currentRecord->generalCourseInstructor, value) == 0) {
            strncpy(currentRecord->generalCourseInstructor, newValue, sizeof(currentRecord->generalCourseInstructor) - 1);
            currentRecord->generalCourseInstructor[sizeof(currentRecord->generalCourseInstructor) - 1] = '\0';
        } else if (strcmp(column, "generalCourseScore") == 0 && currentRecord->generalCourseScore == atoi(value)) {
            currentRecord->generalCourseScore = atoi(newValue);
        } else if (strcmp(column, "coreCourseName") == 0 && strcmp(currentRecord->coreCourseName, value) == 0) {
            strncpy(currentRecord->coreCourseName, newValue, sizeof(currentRecord->coreCourseName) - 1);
            currentRecord->coreCourseName[sizeof(currentRecord->coreCourseName) - 1] = '\0';
        } else if (strcmp(column, "coreCourseInstructor") == 0 && strcmp(currentRecord->coreCourseInstructor, value) == 0) {
            strncpy(currentRecord->coreCourseInstructor, newValue, sizeof(currentRecord->coreCourseInstructor) - 1);
            currentRecord->coreCourseInstructor[sizeof(currentRecord->coreCourseInstructor) - 1] = '\0';
        } else if (strcmp(column, "coreCourseScore") == 0 && currentRecord->coreCourseScore == atoi(value)) {
            currentRecord->coreCourseScore = atoi(newValue);
        }
        currentRecord = currentRecord->next;
    }
}