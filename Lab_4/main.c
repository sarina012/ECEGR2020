#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int ID;
    char studentFirstName[30];
    char studentLastName[30];
    float GPA;
    struct student *next;
} Student;

int numberOfStudents;

Student *headNode = NULL;

void ImportStudentData(void);                                                             
void SaveStudentData(void);                                                               
void Menu(void);                                                                       
Student* NewStudent(int ID, char studentFirstName[30], char studentLastName[30], float GPA);             
void AddANewStudentInList(Student* studentNode);                                                      
void EliminateTheStudentInList(int ID);                                                               
void UpdateStudentInList(int ID);                                                                    
void ReorderStudentsByGPA(Student* insertedStudent);                                                 
void PrintStudents(void);                                                                   
void DeleteAndClearList(void);                                                              

int main(void){
    ImportStudentData();
    Menu();
    DeleteAndClearList();
    return 0;
}

void ImportStudentData(void){
    FILE *studentDataPointer = fopen("text.txt", "r");
    if(studentDataPointer == NULL){
        printf("No file here :( \n");
        return;
    }
    fscanf(studentDataPointer, "%d", &numberOfStudents);
    
    for(int i = 0; i < numberOfStudents; ++i){   
        int ID;
        char studentFirstName[30];
        char studentLastName[30];
        float GPA;

        fscanf(studentDataPointer, "%d", &ID);
        fscanf(studentDataPointer, "%s", studentFirstName);
        fscanf(studentDataPointer, "%s", studentLastName);
        fscanf(studentDataPointer, "%f", &GPA);

        Student *studentFileData = NewStudent(ID, studentFirstName, studentLastName, GPA);

        if(studentFileData != NULL){
            AddANewStudentInList(studentFileData);
        }
    }
}

void SaveStudentData(){
    FILE *anotherPointer = fopen("text.txt", "w");

    fprintf(anotherPointer, "%d\n", numberOfStudents);

    for( Student *currentStudent = headNode; currentStudent != NULL; currentStudent = currentStudent->next){
        fprintf(anotherPointer, "%d\n", currentStudent->ID);
        fprintf(anotherPointer, "%s\n", currentStudent->studentFirstName);
        fprintf(anotherPointer, "%s\n", currentStudent->studentLastName);
        fprintf(anotherPointer, "%f\n", currentStudent->GPA);
    }

    fclose(anotherPointer);
}

void Menu(){
    int option = 0;
    while(option != 5){
        printf(" ----------Menu---------- \n");
        printf(" 1) List all Students\n");
        printf(" 2) Add Student\n");              
        printf(" 3) Remove Student (by ID)\n");   
        printf(" 4) Update Student (by ID)\n");   
        printf(" 5) Save and Quit\n\n\n");

        scanf("%d", &option);

        int ID;
        char studentFirstName[30];
        char studentLastName[30];
        float GPA;

        switch (option){
        case 1:
            PrintStudents();
            break;
        case 2:
            printf("Enter the ID of new student: ");
            scanf("%d", &ID);
            printf("Enter the first name of the new student: ");
            scanf("%s", studentFirstName);
            printf("Enter the last name of the new student: ");
            scanf("%s", studentLastName);
            printf("Enter the GPA of the new student: ");
            scanf("%f", &GPA);
            printf("\n\n");
            Student *insertStudent = NewStudent(ID, studentFirstName, studentLastName, GPA);
            ReorderStudentsByGPA(insertStudent);
            break;
        case 3:
            printf("To remove a student, enter their ID: ");
            scanf("%d", &ID);
            EliminateTheStudentInList(ID);
            break;
        case 4:
            printf("To update a student, enter their ID: ");
            scanf("%d", &ID);
            UpdateStudentInList(ID);
            break;
        case 5:
            SaveStudentData();
            DeleteAndClearList();
            break;
        default:
            break;
        }
    }
}

Student* NewStudent(int ID, char studentFirstName[30], char studentLastName[30], float GPA){
    Student* student = (Student*) malloc(sizeof(Student));
    if(student != NULL){
        student->ID = ID;
        strcpy(student->studentFirstName, studentFirstName);
        strcpy(student->studentLastName, studentLastName);
        student->GPA = GPA;
        student->next = NULL;
    }
    return student;
}

void AddANewStudentInList(Student* studentNode){
    Student* currentStudent = headNode;
    if(headNode == NULL){
        headNode = studentNode;
        return;
    }
    while(currentStudent->next != NULL){
        currentStudent = currentStudent->next;
    }
    currentStudent->next = studentNode;
}

void EliminateTheStudentInList(int ID){
    Student *oldStudent = headNode;
    Student *currentStudent = NULL;
    if(oldStudent == NULL){
        printf("Empty\n\n");
        return;
    }
    currentStudent = oldStudent->next;
    if(currentStudent == NULL && oldStudent->ID == ID){
        free(oldStudent);
        printf("Just Checking \n");
        numberOfStudents--;
        return;
    }
    while(currentStudent != NULL){
        if(oldStudent->ID == ID){
            headNode = oldStudent->next;
            free(oldStudent);
            numberOfStudents--;
            break;
        }
        else if(currentStudent->ID == ID){
            oldStudent->next = currentStudent->next;
            free(currentStudent);
            numberOfStudents--;
            break;
        }
        if(currentStudent->ID == ID && currentStudent->next == NULL){
            oldStudent->next = NULL;
            free(currentStudent);
            numberOfStudents--;
            break;
        }
        oldStudent = currentStudent;
        currentStudent = currentStudent->next;
    }
}

void UpdateStudentInList(int ID){
    Student *currentStudent = headNode;
    Student *nextStudent = NULL;
    if(currentStudent == NULL){
        printf("Empty List");
        return;
    }
    nextStudent = currentStudent->next;
    while(nextStudent != NULL){
        if(currentStudent->ID == ID){
            printf("Enter new studnet ID: ");
            scanf("%d", &(currentStudent->ID));
            printf("Enter new student first name: ");
            scanf("%s", currentStudent->studentFirstName);
            printf("Enter new student last name: ");
            scanf("%s", currentStudent->studentLastName);
            printf("Enter new student GPA: ");
            scanf("%f", &(currentStudent->GPA));
            
            headNode = nextStudent;
            currentStudent->next = NULL;
            ReorderStudentsByGPA(currentStudent);
            break;
        }
        else if(nextStudent->ID == ID && nextStudent->next != NULL){
            printf("Enter new student ID: ");
            scanf("%d", &(nextStudent->ID));
            printf("Enter new student first name: ");
            scanf("%s", nextStudent->studentFirstName);
            printf("Enter new student last name: ");
            scanf("%s", nextStudent->studentLastName);
            printf("Enter new student GPA: ");
            scanf("%f", &(nextStudent->GPA));

            currentStudent->next = nextStudent->next;
            nextStudent->next = NULL;
            ReorderStudentsByGPA(nextStudent);
            break;
        }
        if(nextStudent->ID == ID && nextStudent->next == NULL){
            printf("Enter new ID: ");
            scanf("%d", &(nextStudent->ID));
            printf("Enter new first name: ");
            scanf("%s", nextStudent->studentFirstName);
            printf("Enter new last name: ");
            scanf("%s", nextStudent->studentLastName);
            printf("Enter new GPA: ");
            scanf("%f", &(nextStudent->GPA));

            currentStudent->next = NULL;
            ReorderStudentsByGPA(nextStudent);
            break;
        }
        currentStudent = nextStudent;
        nextStudent = nextStudent->next;
    }
    numberOfStudents--;
}

void ReorderStudentsByGPA(Student* insertedStudent){
    Student *currentStudent = headNode;
    Student *nextStudent = NULL;
    if(currentStudent == NULL){
        printf("Empty List\n\n");
        return;
    }
    nextStudent = currentStudent->next;

    while(nextStudent != NULL){
        if(currentStudent->GPA < insertedStudent->GPA){
            insertedStudent->next = currentStudent;
            headNode = insertedStudent;
            numberOfStudents++;
            break;
        }
        else if(currentStudent->GPA > insertedStudent->GPA && nextStudent->GPA < insertedStudent->GPA){
            currentStudent->next = insertedStudent;
            insertedStudent->next = nextStudent;
            numberOfStudents++;
            break;
        }
        if(nextStudent->GPA > insertedStudent->GPA){
            nextStudent->next = insertedStudent;
            numberOfStudents++;
            break;
        }
        currentStudent = nextStudent;
        nextStudent = nextStudent->next;
    }
}

void PrintStudents(void){
    Student *currentStudent = headNode;
    if(numberOfStudents == 0){
        printf("Empty List\n");
        return;
    }
    for (int pos = 0; currentStudent != NULL; ++pos){
        printf("ID of student %d is: %d\n", pos + 1, currentStudent->ID);
        printf("First name of student %d is: %s\n", pos + 1, currentStudent->studentFirstName);
        printf("Last name of student %d is: %s\n", pos + 1, currentStudent->studentLastName);
        printf("GPA of student %d is: %f\n\n\n", pos + 1, currentStudent->GPA);

        if(currentStudent->next != NULL){
            currentStudent = currentStudent->next;
            continue;
        }
        break;
    }
}

void DeleteAndClearList(void){
    Student *prev = headNode;
    while(headNode){
        headNode = headNode->next;
        free(prev);
        prev = headNode;
    }
}

/*A full sort of students is avoided because of the condition set in case 2 of the menu option.
After each new student is added, their gpa will be put into the ReorderStudentsByGPA and the
students will then be reorganized with respect to who has the highest GPA. This step eliminates the 
need to constantly reorganize the students by their GPAs. 
*/

