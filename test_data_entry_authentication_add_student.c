#include "data_entry.c"
#include "hostel.h"
int get_current_file_count()
{
    FILE *fp = fopen("students.csv", "r");
    if (fp == NULL) {
        return 0;
    }

    int count = 0;
    char line[500];
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }

    fclose(fp);
    return count;
}

void test_add_student()
{
    printf("\nTesting addStudent function:\n\n");
    int initial = get_current_file_count(); 

    addStudent(); 

    int expected = initial + 1;
    int actual = get_current_file_count();

    printf("\nexpected: %d actual: %d, success:%d\n",
        expected, actual, actual == expected);
}

int main() {
    test_add_student();
    return 0;
}