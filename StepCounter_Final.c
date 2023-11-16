#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
char choice;
char filename[20];
char line[100];
int counter, i;
char steps_str[100];

// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
void menu(){
    printf("A: Specify the filename to be imported\n");
   printf("B: Display the total number of records in the file\n");
   printf("C: Find the date and time of the timeslot with the fewest steps\n");
   printf("D: Find the data and time of the timeslot with the largest number of steps\n");
   printf("E: Find the mean step count of all the records in the file\n");
   printf("F: Find the longest continuous period where the step count is above 500 steps\n");
   printf("Q: Exit\n");
   printf("Enter choice: ");
}

int main() {
   menu();
   FITNESS_DATA fitnessdata[100];
    choice = getchar();
    while (getchar() != '\n');
   switch (choice)
   {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);
            FILE *input = fopen(filename, "r");
            if (!input)
            {
            printf("Error: File could not be opened\n");
            return 1;
            }
            break;

        case 'B':
        case 'b':
            i = 0;
            while(line, 100, input != NULL) {
                i++;
            }
            printf("Total records: %d", i);
            break;

        case 'C':
        case 'c':
            counter = 0;
            while (fgets(line, 100, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", fitnessdata[counter].date, fitnessdata[counter].time, steps_str);
                fitnessdata[counter].steps = atoi(steps_str);
                counter++;
            }
            int min = fitnessdata[0].steps;
            for (int i = 0; i < counter; i++)
            {
                if (fitnessdata[i].steps < min)
                {
                    min = fitnessdata[i].steps;
                }
            }
            printf("Fewest steps: %s %s\n", fitnessdata[i].date, fitnessdata[i].time);
            break;

   
}










