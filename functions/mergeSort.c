#include "Database_functions.h"

Table* mergeSortedTables(Table* left, Table* right) {
    Table* result = createTable("Merged Table");
    Record* leftCurrent = left->head;
    Record* rightCurrent = right->head;
    Record* tail = NULL;

    while (leftCurrent && rightCurrent) {
        Record* newRecord = (Record*) malloc(sizeof(Record));
        if (leftCurrent->studentNumber <= rightCurrent->studentNumber) {
            *newRecord = *leftCurrent;
            leftCurrent = leftCurrent->next;
        } else {
            *newRecord = *rightCurrent;
            rightCurrent = rightCurrent->next;
        }
        newRecord->next = NULL;
        newRecord->prev = tail;

        if (tail) {
            tail->next = newRecord;
        } else {
            result->head = newRecord;
        }
        tail = newRecord;
    }

    while (leftCurrent) {
        Record* newRecord = (Record*) malloc(sizeof(Record));
        *newRecord = *leftCurrent;
        newRecord->next = NULL;
        newRecord->prev = tail;
        if (tail) {
            tail->next = newRecord;
        } else {
            result->head = newRecord;
        }
        tail = newRecord;
        leftCurrent = leftCurrent->next;
    }

    while (rightCurrent) {
        Record* newRecord = (Record*) malloc(sizeof(Record));
        *newRecord = *rightCurrent;
        newRecord->next = NULL;
        newRecord->prev = tail;
        if (tail) {
            tail->next = newRecord;
        } else {
            result->head = newRecord;
        }
        tail = newRecord;
        rightCurrent = rightCurrent->next;
    }
    return result;
}

Table* mergeSortRecords(Record* head) {
    if (!head || !head->next) {
        Table* singleRecordTable = createTable("Single Record Table");
        singleRecordTable->head = head;
        return singleRecordTable;
    }

    Record* slow = head;
    Record* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Record* mid = slow->next;
    slow->next = NULL;

    Table* left = mergeSortRecords(head);
    Table* right = mergeSortRecords(mid);

    return mergeSortedTables(left, right);
}

Table* sortedRecords(Table* table) {
    return mergeSortRecords(table->head);    
}