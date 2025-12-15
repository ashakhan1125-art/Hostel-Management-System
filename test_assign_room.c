#include "hostel.h"
#include "room_management.c"
#include <stdio.h>
#include <string.h>

#define TEST_FILE_NAME "students.csv"

// Helper: Sets up the CSV file with initial data for testing
void setup_students_csv() {
    FILE *fp = fopen(TEST_FILE_NAME, "w");
    if (fp != NULL) {
        fprintf(fp, "Alif,A001,1111,R101,Pending\n");
        fprintf(fp, "Bakar,B002,2222,R102,Paid\n");
        fclose(fp);
    } else {
        printf("ERROR: Could not setup students.csv for testing!\n");
    }
}

// Helper: Reads a student's room by ID
char* read_student_room(const char *id, char *room_buffer) {
    FILE *fp = fopen(TEST_FILE_NAME, "r");
    if (fp == NULL) {
        strcpy(room_buffer, "FILE_ERROR");
        return room_buffer;
    }

    char line[200];
    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);
        
        if(strcmp(id, s.id) == 0) {
            strcpy(room_buffer, s.room);
            fclose(fp);
            return room_buffer;
        }
    }

    fclose(fp);
    strcpy(room_buffer, "NOT_FOUND");
    return room_buffer;
}

void test_assign_room_success() {
    printf("\n--- Test 1: Successful Room Assignment (Input ID: A001, New Room: R201) ---\n");
    setup_students_csv();

    char id_to_change[] = "A001";
    char new_room[] = "R201";
    char room_buffer[20];
    
    printf("Initial Room for %s: %s. Please input '%s' and then '%s' when prompted.\n", 
           id_to_change, read_student_room(id_to_change, room_buffer), id_to_change, new_room);

    // CALL THE FUNCTION (Requires User Input: A001, R201)
    assignRoom(); 

    // Verification
    char actual_room[20];
    read_student_room(id_to_change, actual_room);
    
    char expected_room[] = "R201";

    int success = strcmp(actual_room, expected_room) == 0;

    printf("\nTEST RESULT: Successful Room Assignment\n");
    printf("expected: %s actual: %s, success:%d\n",
        expected_room, actual_room, success);
        
    setup_students_csv();
}


int main() {
    test_assign_room_success();
    return 0;
}