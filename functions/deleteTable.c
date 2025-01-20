#include "Database_functions.h"

void deleteTable(const char* tableName) {
    unsigned int index = hash(tableName);
    HashMap* current = hashMapArray[index];
    while (current) {
        if (strcmp(current->table->tableName, tableName) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            if (hashMapArray[index] == current) {
                hashMapArray[index] = current->next;
            }
            Record* currentRecord = current->table->head;
            while (currentRecord) {
                Record* next = currentRecord->next;
                free(currentRecord);
                currentRecord = next;
            } 
            free(current->table);
            free(current);
            return;
        }
        current = current->next;    
    }
    printf("---> Table not found\n"); 
}