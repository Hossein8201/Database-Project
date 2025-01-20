#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {   
    int studentNumber; 
    char generalCourseName[33]; 
    char generalCourseInstructor[33]; 
    int generalCourseScore; 
    char coreCourseName[33]; 
    char coreCourseInstructor[33]; 
    int coreCourseScore;
    struct Record* next;
    struct Record* prev;
} Record;

typedef struct Table {
    char tableName[33];
    Record* head;
} Table;

typedef struct HashMap {
    Table* table;
    struct HashMap* next;
    struct HashMap* prev;
} HashMap;

typedef struct RedBlackNode {
    int studentNumber;
    char color; 
    struct RedBlackNode* left;
    struct RedBlackNode* right;
    struct RedBlackNode* parent;
} RedBlackNode;

typedef struct RedBlackTree {
    RedBlackNode* root;
    RedBlackNode* nil;
} RedBlackTree;

extern HashMap* hashMapArray[101];

unsigned int hash(const char* tableName);
Table* createTable(const char* tableName);
void deleteTable(const char* tableName);
int addRecord(
    const char* tableName,
    const char* column1, const char* value1,
    const char* column2, const char* value2,
    const char* column3, const char* value3,
    const char* column4, const char* value4,
    const char* column5, const char* value5,
    const char* column6, const char* value6,
    const char* column7, const char* value7
);
Record* findRecord(Table* table, int id);
void deleteRecord(const char* tableName, const char* column, const char* value);
void updateRecord(const char* tableName, const char* column, const char* value, const char* newValue);
void selectRecord(const char* tableName, const char* column, const char* value, int sorted);
Table* sortedRecords(Table* table);
void displayRecords(Table* table);

RedBlackTree* createIndex(const char* tableName);
RedBlackTree* createRedBlackTree();
void insertRedBlackTree(RedBlackTree* tree, int studentNumber);

#endif