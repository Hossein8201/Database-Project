#include "Database_functions.h"

Table* createTable(const char* tableName) {
    Table* newTable = (Table*) malloc(sizeof(Table));
    strncpy(newTable->tableName, tableName, sizeof(newTable->tableName) - 1);
    newTable->tableName[sizeof(newTable->tableName) - 1] = '\0';
    newTable->head = NULL;

    unsigned int index = hash(tableName);
    HashMap* newEntry = (HashMap*) malloc(sizeof(HashMap));
    newEntry->table = newTable;
    newEntry->prev = NULL;
    newEntry->next = NULL;

    if (hashMapArray[index]) {
        hashMapArray[index]->prev = newEntry;
        newEntry->next = hashMapArray[index];
    }
    hashMapArray[index] = newEntry;
    
    return newTable;
}