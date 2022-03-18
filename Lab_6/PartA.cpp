#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//==================================================================================
class Student{
    private:
        int ID;
        char *firstName;
        char *lastName;
        float GPA;
        Student *next;
    public:
        Student(void);
        Student(const Student &student);
        Student(int ID, char* firstName, char* lastName, float GPA);
        ~Student(void);

        int getID(){
            return ID;
        }
        float getGPA(){
            return GPA;
        }
        char* getFirstName(){
            return this->firstName;
        }
        char* getLastName(){
            return this->lastName;
        }
        Student* getNext(void){
            return this->next;
        }
        void setID(int ID){
            this->ID = ID;
        }
        void setGPA(float GPA){
            this->GPA = GPA;
        }
        void setFirstName( char* firstName){
            if(this->firstName == nullptr){
                this->firstName = (char*)malloc(strlen(firstName) + 1);
                strcpy(this->firstName, firstName);
            }
            else{
                free(this->firstName);
                this->firstName = (char*)malloc(strlen(firstName) + 1);
                strcpy(this->firstName, firstName);
            }
        }
        void setLastName( char* lastName){
            if(this->lastName == nullptr){
                this->lastName = (char*)malloc(strlen(lastName) + 1);
                strcpy(this->lastName, lastName);
            }
            else{
                free(this->lastName);
                this->lastName = (char*)malloc(strlen(lastName) + 1);
                strcpy(this->lastName, lastName);
            }
        }
        void setNext(Student* next_student){
            next = next_student;
        }
};

Student::Student(){
    ID = 0000;
    firstName = nullptr;
    lastName = nullptr;
    GPA = 0.0f;
    next = nullptr;
}

Student::Student(int ID,  char* firstName,  char* lastName, float GPA){
    this->ID = ID;
    this->firstName = (char*)malloc(strlen(firstName) + 1);
    this->lastName = (char*)malloc(strlen(lastName) + 1);
    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
    this->GPA = GPA;
    next = nullptr;
}

Student::Student(const Student &student){
    ID = student.ID;
    setFirstName(student.firstName);
    setLastName(student.lastName);
    GPA = student.GPA;
    next = student.next;
}

Student::~Student(){
    free(firstName);
    free(lastName);
}

//==================================================================================

Student* headNode = nullptr;
int numberOfStudents;

void ImportStudentData(void);                                                           
void SaveStudentData(void);                                                               
void Menu(void);                                                                   
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
    ifstream studentFile("text.txt", ios::in);
    if(!studentFile.is_open()){
        cerr << "Cannot open file" << endl;
        return;
    }
    studentFile.seekg(0);
    studentFile >> numberOfStudents;

    
    for(int i = 0; i < numberOfStudents; ++i){   
        string placeholder;
        int ID;
        char* firstName;
        char* lastName;
        float GPA;

        studentFile >> ID;
        studentFile >> placeholder;
        firstName = (char*)malloc(strlen((placeholder.c_str())+1));
        strcpy(firstName, placeholder.c_str());
        studentFile >> placeholder;
        lastName = (char*)malloc(strlen((placeholder.c_str())+1));
        strcpy(lastName, placeholder.c_str());
        studentFile >> GPA;

        Student* fileStudent = new Student(ID, firstName, lastName, GPA);

        if(fileStudent != nullptr){
            AddANewStudentInList(fileStudent);
        }
    }
    studentFile.close();
}

void SaveStudentData(){
    ofstream userFile("text.txt");
    userFile.seekp(0);
    userFile << numberOfStudents << endl;
    for( Student *currentStudent = headNode; currentStudent != nullptr; currentStudent = currentStudent->getNext()){
        userFile << currentStudent->getID() << endl;
        userFile.write(currentStudent->getFirstName(), strlen(currentStudent->getFirstName()));
        userFile << endl;
        userFile.write(currentStudent->getLastName(), strlen(currentStudent->getLastName()));
        userFile << endl;
        userFile << currentStudent->getGPA() << endl;
    }
    userFile.close();
}

void Menu(){
    int option = 0;
    while(option != 5){
        printf(" ----------Menu---------- \n");
        printf(" 1) List all Students\n");
        printf(" 2) Add Student\n");              
        printf(" 3) Remove Student w/ ID\n");   
        printf(" 4) Update Student w/ ID\n");   
        printf(" 5) Save and Quit\n\n\n");
        scanf("%d", &option);
        int ID;
        char firstName[30];
        char lastName[30];
        float GPA;

        switch (option){
            case 1:{
                PrintStudents();
                break;
            }
            case 2:{
                printf("Enter ID of new student: ");
                scanf("%d", &ID);
                printf("Enter the first name of new student: ");
                scanf("%s", firstName);
                printf("Enter the last name of new student: ");
                scanf("%s", lastName);
                printf("Enter the GPA of new student: ");
                scanf("%f", &GPA);
                printf("\n\n");
                Student *insertStudent = new Student(ID, firstName, lastName, GPA);
                ReorderStudentsByGPA(insertStudent);
                break;
            }
            case 3:{
                printf("To remove a student, enter their ID: ");
                scanf("%d", &ID);
                EliminateTheStudentInList(ID);
                break;
            }
            case 4:{
                printf("To update a student, enter their ID: ");
                scanf("%d", &ID);
                UpdateStudentInList((ID));
                break;
            }
            case 5:{
                SaveStudentData();
                DeleteAndClearList();
                break;
            }
            default:{
                break;
            }
        }
    }
    
}

void AddANewStudentInList(Student* studentNode){
    Student* currentStudent = headNode;
    if(headNode == nullptr){
        headNode = studentNode;
        return;
    }
    while(currentStudent->getNext() != nullptr){
        currentStudent = currentStudent->getNext();
    }
    currentStudent->setNext(studentNode);
}

void EliminateTheStudentInList(int ID){
    Student *oldStudent = headNode;
    Student *currentStudent = nullptr;
    if(oldStudent == nullptr){
        cerr << "Empty List\n\n";
        return;
    }
    currentStudent = oldStudent->getNext();

    if(currentStudent == nullptr && oldStudent->getID() == ID)
    {
        delete oldStudent;
        cout << "Just Checking\n" << endl;
        numberOfStudents--;
        return;
    }

    while(currentStudent != NULL){
        if(oldStudent->getID() == ID){
            headNode = oldStudent->getNext();
            delete oldStudent;
            numberOfStudents--;
            break;
        }
        else if(currentStudent->getID() == ID){
            oldStudent->setNext(currentStudent->getNext());
            delete currentStudent;
            numberOfStudents--;
            break;
        }
        if(currentStudent->getID() == ID && currentStudent->getNext() == NULL){
            oldStudent->setNext(nullptr);
            delete currentStudent;
            numberOfStudents--;
            break;
        }
        oldStudent = currentStudent;
        currentStudent = currentStudent->getNext();
    }
}

void UpdateStudentInList(int ID){
    Student *currentStudent = headNode;
    Student *nextStudent = nullptr;
    if(currentStudent == nullptr){
        cerr << "Empty List" << endl;
        return;
    }
    nextStudent = currentStudent->getNext();

    while(nextStudent != nullptr){
        if(currentStudent->getID() == ID){
            string placeholder;
            
            cout << "Enter new student ID: ";
            int placeholderID;
            cin >> placeholderID;
            currentStudent->setID(placeholderID);
            
            cout << "Enter new student first name: ";
            cin >> placeholder;
            char *firstName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(firstName, placeholder.c_str());
            currentStudent->setFirstName(firstName);
            
            cout << "Enter new student last name: ";
            cin >> placeholder;
            char *lastName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(lastName, placeholder.c_str());
            currentStudent->setLastName(lastName);
            
            cout << "Enter new student GPA: ";
            float placeholderGPA;
            cin >> placeholderGPA;
            currentStudent->setGPA(placeholderGPA);

            headNode = nextStudent;
            currentStudent->setNext(nullptr);
            ReorderStudentsByGPA(currentStudent);
            break;
        }
        else if(nextStudent->getID() == ID && nextStudent->getNext() != nullptr){
            string placeholder;
            cout << "Enter new student ID: ";
            int placeholderID;
            cin >> placeholderID;
            nextStudent->setID(placeholderID);
            
            cout << "Enter new student first name: ";
            cin >> placeholder;
            char *firstName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(firstName, placeholder.c_str());
            nextStudent->setFirstName(firstName);
            
            cout << "Enter new student last name: ";
            cin >> placeholder;
            char *lastName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(lastName, placeholder.c_str());
            nextStudent->setLastName(lastName);
            
            cout << "Enter new student GPA: ";
            float placeholderGPA;
            cin >> placeholderGPA;
            nextStudent->setGPA(placeholderGPA);

            currentStudent->setNext(nextStudent->getNext());
            nextStudent->setNext(nullptr);
            ReorderStudentsByGPA(nextStudent);
            break;
        }
        if(nextStudent->getID() == ID && nextStudent->getNext() == NULL){
            string placeholder;
            cout << "Enter new student ID: ";
            int placeholderID;
            cin >> placeholderID;
            nextStudent->setID(placeholderID);
            
            cout << "Enter new student first name: ";
            cin >> placeholder;
            char *firstName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(firstName, placeholder.c_str());
            nextStudent->setFirstName(firstName);
            
            cout << "Enter new student last name: ";
            cin >> placeholder;
            char *lastName = (char*)malloc(strlen((placeholder.c_str())+1));
            strcpy(lastName, placeholder.c_str());
            nextStudent->setLastName(lastName);
            
            cout << "Enter new student GPA: ";
            float placeholderGPA;
            cin >> placeholderGPA;
            nextStudent->setGPA(placeholderGPA);

            currentStudent->setNext(nullptr);
            ReorderStudentsByGPA(nextStudent);
            break;
        }
        currentStudent = nextStudent;
        nextStudent = nextStudent->getNext();
    }
    numberOfStudents--;
}

void ReorderStudentsByGPA(Student* insertedStudent){
    Student *currentStudent = headNode;
    Student *nextStudent = NULL;
    if(currentStudent == NULL){
        cerr << "Empty List\n\n";
        return;
    }
    nextStudent = currentStudent->getNext();

    while(nextStudent != nullptr){
        if(currentStudent->getGPA() < insertedStudent->getGPA()){
            insertedStudent->setNext(currentStudent);
            headNode = insertedStudent;
            numberOfStudents++;
            break;
        }
        else if(currentStudent->getGPA() > insertedStudent->getGPA() && nextStudent->getGPA() < insertedStudent->getGPA()){
            currentStudent->setNext(insertedStudent);
            insertedStudent->setNext(nextStudent);
            numberOfStudents++;
            break;
        }
        if(nextStudent->getGPA() > insertedStudent->getGPA()){
            nextStudent->setNext(insertedStudent);
            numberOfStudents++;
            break;
        }
        currentStudent = nextStudent;
        nextStudent = nextStudent->getNext();
    }
}

void PrintStudents(void){
    Student *currentStudent = headNode;
    if(numberOfStudents == 0){
        cerr << "Empty List\n";
        return;
    }
    for (int position = 0; currentStudent != nullptr; ++position){
        string firstName = currentStudent->getFirstName();
        string lastName = currentStudent->getLastName();
        cout << "ID of student " << position + 1 <<  " is: " << currentStudent->getID() << '\n';
        cout << "First name of student " << position + 1 <<  " is: " << firstName << '\n';
        cout << "Last name of student " << position + 1 <<  " is: " << lastName << '\n';
        cout << "GPA of student " << position + 1 <<  " is: " << currentStudent->getGPA() << '\n';
        cout << endl;
        if(currentStudent->getNext() != nullptr){
            currentStudent = currentStudent->getNext();
            continue;
        }
        break;
    }
}

void DeleteAndClearList(void){
    Student *prev = headNode;
    while(headNode){
        headNode = headNode->getNext();
        delete prev;
        prev = headNode;
    }
}