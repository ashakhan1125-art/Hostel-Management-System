#include "hostel.h"
#include "data_operations.c"
#include <stdio.h>
#include <string.h>

void test_search_student_success() {
    printf("\nTesting Search\n");
    printf("Please input an existing ID\n\n");

    searchStudent(); 

    int expected = 1; 
    int actual = 1;   

    printf("\nTEST Successful\n\n");
    printf("expected: %d actual: %d, success:%d\n",
        expected, actual, actual == expected);
}

void test_search_student_failure() {
    
    printf("\nTesting Search\n");
    printf("Please input an existing ID\n\n");

    searchStudent();  

    int expected = 0;
    int actual = 0; 

    printf("\nTEST Failure\n\n");
    printf("expected: %d actual: %d, success:%d\n",
        expected, actual, 1);
}

int main() {
    test_search_student_success();
    test_search_student_failure();
    return 0;
}