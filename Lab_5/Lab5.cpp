#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
enum Department{Biology, Chemistry, Physics, Engineering, Math, Business, Accounting, Finance, English, Communications, Journalism, Undeclared};

// -----------------------------------------------------------------------------------------------------------------------------------------------
class Student{
    private:
        int ID = NULL;
        char* firstName = NULL;
        char* lastName = NULL;
        float GPA = NULL;
    
    public:
        Student();
        Student(int identity, char *first_name, char *last_name, float studentGrade);
        Student(Student &init);
        ~Student();
        Student& operator=(Student const &studentObj){
            this->ID = studentObj.ID;
            setfirstName(studentObj.firstName);
            setlastName(studentObj.lastName);
            this->GPA = studentObj.GPA;
            cout << "Student Operator \n";
            return *this;
    }
    
    int getID(){
        return ID;
    } 
    float getGPA(){
        return GPA;
    }
    char* getfirstName(){
        return firstName;
    }
    char* getlastName(){
        return lastName;
    }
    void setID(int identity){
        ID = identity;
    }
    void setGPA(float studentGrade){
        GPA = studentGrade;
    }
    void setfirstName(char *first_name){
        free(firstName);
        firstName = (char*)malloc(sizeof(strlen(first_name)+1));
        strcpy(firstName,first_name);
    }
    void setlastName(char *last_name){
        free(lastName);
        lastName = (char*)malloc(sizeof(strlen(last_name)+1));
        strcpy(lastName,last_name);
    }
};

//Default Student Constructor
Student :: Student(){
    this->ID = 0000;
    this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this -> firstName, (char*)"<unknown>");
    this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this-> lastName, (char*) "<unknown>");
    this->GPA = 0.0;
    cout << "Default Student Constructor \n";
}

//Student Constructor
Student :: Student(int identity, char* first_name, char* last_name, float studentGrade){
    this->ID = identity;
    this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
    strcpy(this->firstName, first_name);
    this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
    strcpy(this->lastName, last_name);
    this->GPA = studentGrade;
    cout << "Student Constructor: " << firstName << lastName <<"\n";
}

//Student Copy Constructor
Student :: Student(Student &init){
    ID = init.ID;
    GPA = init.GPA;
    if(init.firstName != NULL){
        setfirstName(init.firstName);
    }
    if(init.lastName != NULL){
        setlastName(init.lastName);
    }
    cout << "Student Copy Constructor \n";
}

//Student Deconstructor
Student :: ~Student(){
    cout << "Student Deconstructor: " << firstName << lastName << endl;
    if(firstName){
        free(firstName);
    }
    if(lastName){
        free(lastName);
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------
class Professor{
    private:
        int ID;
        char* firstName;
        char* lastName;
        float salary;
        bool tenured;
        Department department;
    
    public:
        Professor();
        Professor(int identity, char *first_name, char *last_name, float income, bool tenuredProfessor, Department professorDepartment);
        Professor(Professor &init);
        ~Professor();
        
        Professor& operator=(Professor const &professorObj){
        this->ID = professorObj.ID;
        setfirstName(professorObj.firstName);
        setlastName(professorObj.lastName);
        this->salary = professorObj.salary;
        this->tenured = professorObj.tenured;
        this->department = professorObj.department;
        cout << "Professor Operator \n";
        return *this;
    }
    
    int getID(){
        return ID;
    } 
    float getsalary(){
        return salary;
    }
    char* getfirstName(){
        return firstName;
    }
    char* getlastName(){
        return lastName;
    }
    bool getTenured(){
        return tenured;
    }
    Department getDepartment(){
        return department;
    }
    void setID(int identity){
        ID = identity;
    }
    void setSalary(float income){
        salary = income;
    }
    void setfirstName(char *first_name){
        free(firstName);
        firstName = (char*)malloc(sizeof(strlen(first_name)+1));
        strcpy(firstName,first_name);
    }
    void setlastName(char *last_name){
        free(lastName);
        lastName = (char*)malloc(sizeof(strlen(last_name)+1));
        strcpy(lastName,last_name);
    }
    void setTenured(bool tenuredProfessor){
        tenured = tenuredProfessor;
    }
    void setDepartment(Department professorDepartment){
        department = professorDepartment;
    }
};

//Default Professor Constructor
Professor :: Professor(){
    this->ID = 0000;
    this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this -> firstName, (char*)"<unknown>");
    this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this-> lastName, (char*) "<unknown>");
    this->salary = 0.0;
    tenured = false;
    department = Undeclared;
    cout << "Default Professor Constructor \n";
}

//Professor Constructor
Professor :: Professor(int identity, char* first_name, char* last_name, float income, bool tenuredProfessor, Department professorDepartment){
    this->ID = identity;
    this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
    strcpy(this->firstName, first_name);
    this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
    strcpy(this->lastName, last_name);
    this->salary = income;
    this->tenured = tenuredProfessor;
    this->department = professorDepartment;
    cout << "Professor Constructor: " << firstName << lastName <<"\n";
}

//Professor Copy Constructor
Professor :: Professor(Professor &init){
    ID = init.ID;
    salary = init.salary;
    if(init.firstName){
        setfirstName(init.firstName);
    }
    if(init.lastName){
        setlastName(init.lastName);
    }
    tenured = init.tenured;
    department = init.department;
    cout << "Professor Copy Constructor \n";
}

//Professor Deconstructor
Professor :: ~Professor(){
    cout << "Professor Deconstructor: " << firstName << lastName << endl;
    if(firstName){
        free(firstName);
    }
    if(lastName){
        free(lastName);
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------
class Employee{
    private:
        int ID;
        char* firstName;
        char* lastName;
        float salary;
    
    public:
        Employee();
        Employee(int identity, char *first_name, char *last_name, float income);
        Employee(Employee &init);
        ~Employee();
        Employee& operator=(Employee const &employeeObj){
            this->ID = employeeObj.ID;
            setfirstName(employeeObj.firstName);
            setlastName(employeeObj.lastName);
            this->salary = employeeObj.salary;
            cout << "Employee Operator \n";
            return *this;
    }
    
    int getID(){
        return ID;
    } 
    float getsalary(){
        return salary;
    }
    char* getfirstName(){
        return firstName;
    }
    char* getlastName(){
        return lastName;
    }
    void setID(int identity){
        ID = identity;
    }
    void setGPA(float income){
        salary = income;
    }
    void setfirstName(char *first_name){
        free(firstName);
        firstName = (char*)malloc(sizeof(strlen(first_name)+1));
        strcpy(firstName,first_name);
    }
    void setlastName(char *last_name){
        free(lastName);
        lastName = (char*)malloc(sizeof(strlen(last_name)+1));
        strcpy(lastName,last_name);
    }
};

//Default Employee Constructor 
Employee :: Employee(){
    this->ID = 0000;
    this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this -> firstName, (char*)"<unknown>");
    this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
    strcpy(this-> lastName, (char*) "<unknown>");
    this->salary = 0.0;
    cout << "Default Employee Constructor \n";
}

//Employee Constructor
Employee :: Employee(int identity, char* first_name, char* last_name, float income){
    this->ID = identity;
    this->firstName = (char*) malloc(sizeof(strlen(first_name)+1));
    strcpy(this->firstName, first_name);
    this->lastName = (char*) malloc(sizeof(strlen(last_name)+1));
    strcpy(this->lastName, last_name);
    this->salary = income;
    cout << "Employee Constructor: " << firstName << lastName <<"\n";
}

//Employee Copy Constructor
Employee :: Employee(Employee &init){
    ID = init.ID;
    salary = init.salary;
    if(init.firstName){
        setfirstName(init.firstName);
    }
    if(init.lastName){
        setlastName(init.lastName);
    }
    cout << "Employee Copy Constructor \n";
}

//Employee Deconstructor
Employee :: ~Employee(){
    cout << "Employee Deconstructor: " << firstName << lastName << endl;
    if(firstName){
        free(firstName);
    }
    if(lastName){
        free(lastName);
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------
int main(){
/*  I know that the methods are working properly since all of the properties are able to be inputed 
 *  by the user in main and the resulting output is what is expected to happen. Additionally, a 
 *  memory leak can be prevented by using deconstructors. In this program, I have added print statements
 *  after the contructors/destructors which notifies the user that the program is efficiently working. */
    
    Student student1(1234, (char*) "Apple ", (char*) "A", 1.2);
    cout << student1.getID()        <<endl;
    cout << student1.getfirstName() <<endl;
    cout << student1.getlastName()  <<endl;
    cout << student1.getGPA()       <<endl;
    cout << endl;
    
    Student student2 = student1;
    cout << endl;
    cout << student2.getID()        <<endl;
    cout << student2.getfirstName() <<endl; 
    cout << student2.getlastName()  <<endl; 
    cout <<student2.getGPA()        <<endl;
    if(student2.getID() == student1.getID()){
        cout << "---------------------------------" << endl;
        cout << "Identical ID" << endl;
        cout << "---------------------------------" << endl;
    }
    student2.setID(9876);
    student2.setfirstName((char*) "Banana ");
    student2.setlastName((char*) "B");
    student2.setGPA(3.9);
    cout << endl;
    cout << student2.getID()        <<endl; 
    cout << student2.getfirstName() <<endl;
    cout << student2.getlastName()  <<endl;
    cout << student2.getGPA()       <<endl;
    cout<< "---------------------------------" << endl;
    Professor professor1(2304, (char*) "Oranges ", (char*) "O", 234000, (bool) true, Engineering);
    cout << professor1.getID()         <<endl;
    cout << professor1.getfirstName()  <<endl;
    cout << professor1.getlastName()   <<endl; 
    cout << professor1.getsalary()     <<endl;
    cout << professor1.getTenured()    <<endl;
    cout << professor1.getDepartment() <<endl;
    cout<< "---------------------------------" << endl;
    Employee employee1(2304, (char*) "Watermelon ", (char*) "W", 345000);
    cout << employee1.getID()        <<endl;
    cout << employee1.getfirstName() <<endl;
    cout << employee1.getlastName()  <<endl;
    cout << employee1.getsalary()    <<endl;
    cout<< "---------------------------------" << endl;
}