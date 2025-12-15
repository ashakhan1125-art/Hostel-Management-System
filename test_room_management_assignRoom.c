#include "hostel.h"
#include "room_management.c"
#include <stdio.h>
#include <string.h>

#define TEST_FILE_NAME "students.csv"

void setup_students_csv() {
    FILE *fp = fopen(TEST_FILE_NAME, "w");
    if (fp != NULL) {
        fprintf(fp, "iffat,176,013444,212,Pending\n");
        fprintf(fp, "Rubi,102,0143333,333,Paid\n");
        fclose(fp);
    } else {
        printf("ERROR: Could not setup students.csv for testing!\n");
    }
}

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
    printf("\n Testing Successful Room Assign\n\n");
    setup_students_csv();

    char id_to_change[] = "176";
    char new_room[] = "333";
    char room_buffer[20];

    assignRoom(); 

    char actual_room[20];
    read_student_room(id_to_change, actual_room);
    
    char expected_room[] = "333";

    printf("\nTEST RESULT: Successful Room Assignment\n");
    printf("expected: %s actual: %s, success:%d\n",
        expected_room, actual_room, strcmp(actual_room, expected_room) == 0);
        
    setup_students_csv();
}


int main() {
    test_assign_room_success();
    return 0;
}