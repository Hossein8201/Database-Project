#include "Database_functions.h"

void displayRecords(Table* table) {
    struct Record* current = table->head;
    while (current) {
        printf("  Student Number: %d\n", current->studentNumber);
        printf("  General Course Name: %s\n", current->generalCourseName);
        printf("  General Course Instructor: %s\n", current->generalCourseInstructor);
        printf("  General Course Score: %d\n", current->generalCourseScore);
        printf("  Core Course Name: %s\n", current->coreCourseName);
        printf("  Core Course Instructor: %s\n", current->coreCourseInstructor);
        printf("  Core Course Score: %d\n", current->coreCourseScore);
        current = current->next;
    }
}