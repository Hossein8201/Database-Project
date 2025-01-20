#include "Database_functions.h"

unsigned int hash(const char* tableName) {
    unsigned int hash = 0;
    while (*tableName) {
        hash = (hash << 5) + *tableName++;
    }
    return hash % 101;
}

