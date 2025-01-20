#include "Database_functions.h"

void deleteRecord(const char* tableName, const char* column, const char* value) {
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
        if (
            (strcmp(column, "studentNumber") == 0 && currentRecord->studentNumber == atoi(value)) || 
            (strcmp(column, "generalCourseName") == 0 && strcmp(currentRecord->generalCourseName, value) == 0) || 
            (strcmp(column, "generalCourseInstructor") == 0 && strcmp(currentRecord->generalCourseInstructor, value) == 0) ||  
            (strcmp(column, "generalCourseScore") == 0 && currentRecord->generalCourseScore == atoi(value)) ||
            (strcmp(column, "coreCourseName") == 0 && strcmp(currentRecord->coreCourseName, value) == 0) ||
            (strcmp(column, "coreCourseInstructor") == 0 && strcmp(currentRecord->coreCourseInstructor, value) == 0) ||
            (strcmp(column, "coreCourseScore") == 0 && currentRecord->coreCourseScore == atoi(value))
        ) {
            if (currentRecord->prev) {
                currentRecord->prev->next = currentRecord->next;
            }
            if (currentRecord->next) {
                currentRecord->next->prev = currentRecord->prev;
            }
            if (currentTable->table->head == currentRecord) {
                currentTable->table->head = currentRecord->next;
            }
            free(currentRecord);
        }
        currentRecord = currentRecord->next;
    }
}