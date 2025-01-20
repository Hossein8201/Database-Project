#include "Database_functions.h"

int addRecord(
    const char* tableName,
    const char* column1, const char* value1,
    const char* column2, const char* value2,
    const char* column3, const char* value3,
    const char* column4, const char* value4,
    const char* column5, const char* value5,
    const char* column6, const char* value6,
    const char* column7, const char* value7
) {
    int studentNumber;
    unsigned int index = hash(tableName);
    HashMap* currentTable = hashMapArray[index];
    while (currentTable) {
        if (strcmp(currentTable->table->tableName, tableName) == 0) {
            break;
        }
        currentTable = currentTable->next;
    }

    Record* newRecord = (Record*) malloc(sizeof(Record));
    const char* recordList[7][2] = {{ column1, value1}, { column2, value2}, { column3, value3}, 
        { column4, value4 }, { column5, value5 }, { column6, value6 }, { column7, value7 }};

    for (int i = 0; i < 7; i++) {
        if (strcmp(recordList[i][0], "studentNumber") == 0) {
            if (findRecord(currentTable->table, atoi(recordList[i][1]))) {
                printf("---> Record already exists\n");
                return -1;
            }
            newRecord->studentNumber = atoi(recordList[i][1]);
            studentNumber = newRecord->studentNumber;
        } else if (strcmp(recordList[i][0], "generalCourseName") == 0) {
            strncpy(newRecord->generalCourseName, recordList[i][1], sizeof(newRecord->generalCourseName) - 1);
            newRecord->generalCourseName[sizeof(newRecord->generalCourseName) - 1] = '\0';
        } else if (strcmp(recordList[i][0], "generalCourseInstructor") == 0) {
            strncpy(newRecord->generalCourseInstructor, recordList[i][1], sizeof(newRecord->generalCourseInstructor) - 1);
            newRecord->generalCourseInstructor[sizeof(newRecord->generalCourseInstructor) - 1] = '\0';
        } else if (strcmp(recordList[i][0], "generalCourseScore") == 0) {
            newRecord->generalCourseScore = atoi(recordList[i][1]);
        } else if (strcmp(recordList[i][0], "coreCourseName") == 0) {
            strncpy(newRecord->coreCourseName, recordList[i][1], sizeof(newRecord->coreCourseName) - 1);    
            newRecord->coreCourseName[sizeof(newRecord->coreCourseName) - 1] = '\0';
        } else if (strcmp(recordList[i][0], "coreCourseInstructor") == 0) { 
            strncpy(newRecord->coreCourseInstructor, recordList[i][1], sizeof(newRecord->coreCourseInstructor) - 1);
            newRecord->coreCourseInstructor[sizeof(newRecord->coreCourseInstructor) - 1] = '\0';
        } else if (strcmp(recordList[i][0], "coreCourseScore") == 0) {
            newRecord->coreCourseScore = atoi(recordList[i][1]);        
        }
    }
    newRecord->next = NULL;
    newRecord->prev = NULL;

    Record* currentRecord = currentTable->table->head;
    if (!currentRecord) {
        currentTable->table->head = newRecord;
    } else {
        currentRecord->prev = newRecord;
        newRecord->next = currentRecord;
        currentTable->table->head = newRecord;
    }

    return studentNumber;
}

Record* findRecord(Table* table, int id) {
    Record* current = table->head;
    while (current) {
        if (current->studentNumber == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}