#include <stdio.h>
#include <string.h>
#include "hostel.h" 

#include "fees_security.c" 

void setup_students_csv() {
    FILE *fp = fopen("students.csv", "w");
    if (fp != NULL) {
       
        fprintf(fp, "Alif,A001,1111,R101,Pending\n");
        fprintf(fp, "Bakar,B002,2222,R102,Paid\n");
        fclose(fp);
    } else {
        printf("ERROR: Could not setup students.csv for testing!\n");
    }
}


void get_fee_status(char *search_id, char *status_buffer) {
    FILE *fp = fopen("students.csv", "r");
    char line[200];
    Student s;
    
    strcpy(status_buffer, "NOT_FOUND");

    if (fp != NULL) {
        while(fgets(line, sizeof(line), fp)) {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
                   s.name, s.id, s.phone, s.room, s.fees);
            
            if(strcmp(search_id, s.id) == 0) {
                strcpy(status_buffer, s.fees);
                break;
            }
        }
        fclose(fp);
    }
}

void test_pay_fees_success() {
    printf("\n--- Test: Pay Fees Functionality ---\n");
    
   
    setup_students_csv();

   
    FILE *input_simulation = fopen("test_input.txt", "w");
    fprintf(input_simulation, "A001"); 
    fclose(input_simulation);
    
    
    freopen("test_input.txt", "r", stdin);


    payFees(); 

    
    char actual_status[20];
    get_fee_status("A001", actual_status);

    printf("\nExpected: Paid\n");
    printf("Actual:   %s\n", actual_status);

    if (strcmp(actual_status, "Paid") == 0) {
        printf("RESULT: [ PASS ]\n");
    } else {
        printf("RESULT: [ FAIL ]\n");
    }

    
    remove("test_input.txt");
    
    
    setup_students_csv();
}

int main() {
    test_pay_fees_success();
    return 0;
}