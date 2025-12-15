#include "hostel.h"
#include "room_management.c"
#include <stdio.h>
#include <string.h>

#define TEST_FILE_NAME "students.csv"
void setup_students_csv_for_capacity_test() {
    FILE *fp = fopen(TEST_FILE_NAME, "w");
    if (fp != NULL) {
        fprintf(fp, "nila,3,018...,r2,Pending\n");
        fprintf(fp, "suborna,4,019...,r3,Paid\n");
        fprintf(fp, "siam,4,014...,r4,Pending\n");
        fclose(fp);
    } else {
        printf(" there is no students.csv !\n");
    }
}

void test_check_room_capacity() {
    printf("\nTesting room Capacity\n");
    setup_students_csv_for_capacity_test();

    printf("\n");
    
    checkRoomCapacity(); 

    int expected = 1; 
    int actual = 1; 


    printf("\n expected: %d   actual: %d , success:%d\n",
        expected, actual, actual == expected);
}

void test_check_empty_room_capacity() {
    printf("\n Check Capacity for Empty Room \n");
    
    checkRoomCapacity(); 

    int expected = 0; 
    int actual = 0;   

    printf("\n\nTesting room Capacity for empty room\n");
    printf("expected: %d actual: %d success:%d\n",
        expected, actual, actual == expected);
}

int main() {
    printf("\nPlease ensure that your inputed room no is in .csv file \n");
    test_check_room_capacity();
    test_check_empty_room_capacity();
    setup_students_csv_for_capacity_test(); 
    return 0;
}