#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *aPointer;
FILE *studentInfo;

//Declaration for Part A
void reverseArray(void);
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//Declaration for Part B/C
typedef struct student{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
}Student;

void newStudents();
void readAndWriteFile();

//Declarations for Part D/E
void vowelCheck();
void consonantCheck();
void pickingFromMenu();
void uppercaseString();
void lowercaseString();
void newString();
void displayMenu();
void reversedString();

char a;
char b;
char string[100];
int variable = 1;


int main(void){
/*  //Part A
    reverseArray();*/
   
/*  //Part B
    newStudents();*/
    
/*  //Part C
    readAndWriteFile();*/
    
    //Part D and Part E
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    displayMenu();
    pickingFromMenu(string);
    return 0;
}

//--------------------------------------------------------------------------

void reverseArray(){
    int reversedArray[10];
    for(int i=0; i<10; i++){
        reversedArray[i] = array[9-i];
    }
    for(int i=0; i<10; i++){
        array[i] = reversedArray[i];
        printf("%d ", reversedArray[i]);
    }
    printf("\n");
}

//--------------------------------------------------------------------------

void newStudents(){
    int num;
    printf("Students in Class: ");
    scanf("%d", &num);
    Student **arrayOfStudents = (Student **)malloc(num*sizeof(Student *));
    for(int i = 0; i < num; i++) {
        arrayOfStudents[i] = (Student*) malloc(sizeof(Student));
    }
    
    for(int j = 0; j < num; j++){
        printf("\nEnter student ID: ");
        scanf("%d",&arrayOfStudents[j]->ID);
        printf("Enter student first name: ");
        scanf("%s",&arrayOfStudents[j]->firstName);
        printf("Enter student last name: ");
        scanf("%s",&arrayOfStudents[j]->lastName);
        printf("Enter student GPA: ");
        scanf("%f",&arrayOfStudents[j]->GPA);
    }
    
    for(int x = 0; x < num; x++){
        for(int y = x; y<num;y++){
            if(arrayOfStudents[x]->GPA<arrayOfStudents[y]->GPA){
                Student *count = arrayOfStudents[x];
                arrayOfStudents[x] = arrayOfStudents[y];
                arrayOfStudents[y] = count;
            }
        }
    }
    
    aPointer = fopen("Lab_3/text.txt", "w+");
    fprintf(aPointer,"Students in class: %d\n", num);
    for(int z = 0; z < num; z++){
        fprintf(aPointer, "%d\n",arrayOfStudents[z]->ID);
        fprintf(aPointer, "%s\n",arrayOfStudents[z]->firstName);
        fprintf(aPointer, "%s\n",arrayOfStudents[z]->lastName);
        fprintf(aPointer, "%f\n",arrayOfStudents[z]->GPA);
    }
    fclose(aPointer);
    free(arrayOfStudents);
}

void readAndWriteFile(){
    int numberOfStudents, ID;
    char firstName[30], lastName[30];
    float gpa, averageGPA, count = 0;
    aPointer = fopen("Lab_3/text.txt","r");

    printf("\n--------- The Report ---------");
    fscanf(aPointer, "Students in class: %d\n", &numberOfStudents);
    printf("\nStudents in class: %d\n", numberOfStudents);
    for(int a = 0; a < numberOfStudents; a++){
        fscanf(aPointer, "%d\n", &ID);
        fscanf(aPointer,"%s\n", firstName);
        fscanf(aPointer,"%s\n", lastName);
        fscanf(aPointer,"%f\n", &gpa);
        printf("\nStudent's ID: %d\n", ID);
        printf("Student's First Name: %s\n", firstName);
        printf("Student's Last Name: %s\n", lastName);
        printf("Student's GPA: %f\n", gpa);
        count++;
        averageGPA += gpa;
    }

    averageGPA = averageGPA/count;
    printf("\nAverage Class GPA: %f", averageGPA);
    printf("\n-------------------------------\n\n");
    fclose(aPointer);
}

//--------------------------------------------------------------------------

void pickingFromMenu(char *string){
    do{
        printf("Pick an option: ");
        a = getchar();
        b = getchar();
        switch(a){
            case 'A':
                vowelCheck(string);
                break;
            case 'B': 
                consonantCheck(string);
                break;
            case 'C':
                uppercaseString(string);
                break;
            case 'D':
                lowercaseString(string);
                break;
            case 'E':
                printf("Current string: %s", string);
                printf("\n");
                break;
            case 'F':
                newString(string);
                break;
            case 'R':
                reversedString(string);
                break;
            case 'M':
                displayMenu();
                break;
            case 'X':
                --variable;
                break;
        }
        
    }while(variable);
}

void vowelCheck(char *string){
    int vowels = 0, consonants = 0;
    int i;
    char ch;
    for (i = 0; string[i]!= '\0'; i++) {
        ch = string [i];
        if (ch == 'a' || ch == 'e' || 
            ch == 'i' || ch == 'o' || 
            ch == 'u' || ch == 'A' || 
            ch == 'E' || ch == 'I' || 
            ch == 'O' || ch == 'U')
            vowels++;
        else if (ch == ' ')
            continue;
        else
            consonants++;
    }
    printf("Vowels in string: %d \n\n", vowels);
}

void consonantCheck(char *string){
    int vowels = 0, consonants = 0;
    int i;
    char ch;
    for (i = 0; string[i]!= '\0'; i++) {
        ch = string[i];
        if (ch == 'a' || ch == 'e'|| 
            ch == 'i' || ch == 'o'||
            ch == 'u' || ch == 'A'||
            ch == 'E' || ch == 'I'||
            ch == 'O' || ch == 'U')
            vowels++;
        else if (ch == ' ')
            continue;
        else
            consonants++;
    }
    printf("Consonants in string: %d \n\n", consonants-1);  
}

void uppercaseString(char *string){
    printf("%s", strupr(string));
    printf("\n");
}

void lowercaseString(char *string){
    printf("%s", strlwr(string));
    printf("\n");
}

void newString(char *string){
    printf("Enter a new string: ");
    fgets(string, 100, stdin);
    printf("\n");
}

void reversedString(char *string){
    printf("%s",strrev(string));
    printf("\n\n");
}

void displayMenu(){
    printf("\n--------------Menu-----------------\n");
    printf(" A: Number of vowels in string\n");
    printf(" B: Number of consonants in string\n");
    printf(" C: Convert string to uppercase\n");
    printf(" D: Convert string to lowercase\n");
    printf(" E: Display current string\n");
    printf(" F: Enter another string\n");
    printf(" R: Reverse string\n\n");
    printf(" M: Display menu\n");
    printf(" X: Exit program\n");
    printf("-----------------------------------\n\n");
}

