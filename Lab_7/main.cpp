#include <cstring>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <stdlib.h> 
using namespace std;
template <class DstType, class SrcType>
bool instanceof(const SrcType* src){
  return dynamic_cast<const DstType*>(src) != nullptr;
}
enum Department {English, Business, Finance, Journalism, Biology, Physics, Math, Engineering, Undeclared};

class Person{
private:
    int ID;
    string firstName;
    string lastName;
    Person* next;
    
public:
    Person();
    Person(int id_in, string first_name, string last_name);
    Person(Person &init);
    virtual ~Person();
    Person& operator=(Person const &pObj){
        this->ID = pObj.ID;
        setFirstName(pObj.firstName);
        setLastName(pObj.lastName);
        this->next = pObj.next;
        return *this;
    }
    
    int getID(){
        return ID;
    }
    string getFirstName(){
        return firstName;
    }
    string getLastName(){
        return lastName;
    }
    Person* getNext(){
        return next;
    }
    void setID(int id_in){
        ID = id_in;
    }
    void setFirstName(string first_name){
        this->firstName = first_name;
    }
    void setLastName(string last_name){
        this->lastName = last_name;
    }
    void setNext(Person* next_in){
        next = next_in;
    }
};

Person* head = NULL;

Person :: Person()
{
    this->ID = 9999;
    this->firstName = "null";
    this->lastName = "null";
    this->next = NULL;
}

Person :: Person(int id_in, string first_name, string last_name){
    this->ID = id_in;
    this->firstName = first_name;
    this->lastName = last_name;
    this->next = NULL;
}

Person :: Person(Person &init){
    this->ID = init.ID;
    this->firstName = "";
    this->lastName = "";
    setFirstName(init.firstName);
    setLastName(init.lastName);
    this->next = init.next;
}

Person :: ~Person(){}

class Student: public Person{
private:
    float GPA;
public:
    Student();
    Student(int id_in, string first_name, string last_name, float gpa_in);
    Student(Student &init);
    ~Student();
    float getGPA(){
        return GPA;
    }
    void setGPA(float gpa_in){
        GPA = gpa_in;
    }
};

Student :: Student(){
    this->setID(9999);
    this->setFirstName("null");
    this->setLastName("null");
    this->GPA = 0.0;
    this->setNext(NULL);
}

Student :: Student(int id_in, string first_name, string last_name, float gpa_in){
    setID(id_in);
    setFirstName(first_name);
    setLastName(last_name);
    this->GPA = gpa_in;
    this->setNext(NULL);
}

Student :: Student(Student &init){
    this->setID(init.getID());
    this->setGPA(init.GPA);
    this->setFirstName(init.getFirstName());
    this->setLastName(init.getLastName());
    this->setNext(init.getNext());
}

Student :: ~Student(){}

class Employee: public Person{
private:
    float salary;
    
public:
    Employee();
    Employee(int id_in, string first_name, string last_name, float salary_in);
    Employee(Employee &init);
    ~Employee();
    float getSalary(){
        return salary;
    }
    void setSalary(float salary_in){
        salary = salary_in;
    }
};

Employee :: Employee(){
    this->setID(9999);
    this->setFirstName("(null)");
    this->setLastName("(null)");
    this->salary = 0.0;
    this->setNext(NULL);
}

Employee :: Employee(int id_in, string first_name, string last_name, float salary_in){
    setID(id_in);
    setFirstName(first_name);
    setLastName(last_name);
    this->salary = salary_in;
    this->setNext(NULL);
}

Employee :: Employee(Employee &init){
    this->setID(init.getID());
    this->setSalary(init.salary);
    this->setFirstName(init.getFirstName());
    this->setLastName(init.getLastName());
    this->setNext(init.getNext());
}

Employee :: ~Employee(){}

class Professor: public Employee{
private:
    bool tenured;
    Department department;
    
public:
    Professor();
    Professor(int id_in, string first_name, string last_name, float salary_in, bool tenuredProf, Department departmentProf);
    Professor(Professor &init);
    ~Professor();
    bool getTenured(){
        return tenured;
    }
    Department getDepartment(){
        return department;
    }
    void setTenured(bool tenuredProf){
        tenured = tenuredProf;
    }
    void setDepartment(Department departmentProf)
    {
        department = departmentProf;
    }
};

Professor :: Professor(){
    this->setID(9999);
    this->setFirstName("(null)");
    this->setLastName("(null)");
    this->setSalary(0.0);
    this->tenured = false;
    this->department = Undeclared;
    this->setNext(NULL);
}

Professor :: Professor(int id_in, string first_name, string last_name, float salary_in, bool tenuredProf, Department departmentProf){
    setID(id_in);
    setFirstName(first_name);
    setLastName(last_name);
    setSalary(salary_in);
    this->tenured = tenuredProf;
    this->department = departmentProf;
    this->setNext(NULL);
}

Professor :: Professor(Professor &init){
    this->setID(init.getID());
    this->setSalary(init.getSalary());
    this->setFirstName(init.getFirstName());
    this->setLastName(init.getLastName());
    this->setTenured(init.tenured);
    this->setDepartment(init.department);
    this->setNext(init.getNext());
}

Professor :: ~Professor(){}

void readFileInformation(void);
void readLinkedList(void);
void saveLinkedList(void);
void insertNode(Person* person_in);
void deleteNode(Person* person_in);
void addToLinkedList();
void removeIdFromLinkedList(int id_in);
void updateIdInLinkedList(int id_in);
void menu(void);
void addAndDiplayMenu(void);
void updateStudentMenu(string first, string last);
void updateProfessorMenu(string first, string last);
void updateEmployeeMenu(string first, string last);

int main(){
    int option = 0;
    readFileInformation();
    do{
        int userID_in;
        menu();
        cout << endl << "Pick an option: ";
        cin >> option;
        
        switch(option)	{
            case 1 :{
                readLinkedList();
                break;
            }
            case 2 :{
                addToLinkedList();
                break;
            }
            case 3 : {
                printf("\nEnter ID for person you wish to delete: "); 
                cin >> userID_in; 
                removeIdFromLinkedList(userID_in);
                break;
            }
            case 4 : {
                printf("\nEnter ID for person you wish to update: "); 
                cin >> userID_in; 
                updateIdInLinkedList(userID_in); 
                break; 
            }
            case 5 :{
                break;
            }
        }
        
    }while(option != 5);
    saveLinkedList();
}

void readFileInformation(){
    ifstream readInformationFromFile;
    int allCollegePeople = 0;
    readInformationFromFile.open("Directory.txt");
    if(!readInformationFromFile.is_open()){
        cerr << "Unable to open Directory.txt";
        cout << endl;
    }
    else{
        string temp = "";
        readInformationFromFile >> temp;
        readInformationFromFile >> temp;
        readInformationFromFile >> temp;
        readInformationFromFile >> allCollegePeople;
        cout << "\nNumber of People: " << allCollegePeople << "\n";
        for(int i = 0; i < allCollegePeople; i++){
            readInformationFromFile >> temp;
            if(temp == "Student"){
                int read_id = 0;
                string read_first = "";
                string read_last= "";
                float read_gpa = 0.0;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_id;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_first;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_last;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_gpa;
                
                Person* newStudent = new Student(read_id, read_first, read_last, read_gpa);
                insertNode(newStudent);
            }
            else if(temp == "Professor"){
                int read_id = 0;
                string read_first = "";
                string read_last= "";
                float read_salary = 0.0;
                bool read_ten = false;
                Department read_dep = Undeclared;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_id;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_first;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_last;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_salary;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_ten;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                if(temp == "English"){
                    read_dep = English;
                }
                else if(temp == "Business"){
                    read_dep = Business;
                }
                else if(temp == "Finance"){
                    read_dep = Finance;
                }
                else if(temp == "Journalism"){
                    read_dep = Journalism;
                }
                else if(temp == "Biology"){
                    read_dep = Biology;
                }
                else if(temp == "Physics"){
                    read_dep = Physics;
                }
                else if(temp == "Math"){
                    read_dep = Math;
                }
                else if(temp == "Engineering"){
                    read_dep = Engineering;
                }
                else{
                    read_dep = Undeclared;
                }
                
                Person* newProfesor = new Professor(read_id, read_first, read_last, read_salary, read_ten, read_dep);
                insertNode(newProfesor);
            }
            else if(temp == "Employee"){
                int read_id = 0;
                string read_first = "";
                string read_last= "";
                float read_salary = 0.0;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_id;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_first;
                readInformationFromFile >> temp;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_last;
                readInformationFromFile >> temp;
                readInformationFromFile >> read_salary;
                
                Person* newEmployee = new Employee(read_id, read_first, read_last, read_salary);
                insertNode(newEmployee);
            }
            else{
            }
        }
        readInformationFromFile.close();
        cout << "Directory.txt successfully scanned" << endl;
    }
}

void readLinkedList(){
    Person* node = head;
    printf("\n-------------Saved Information-------------");
    while(node != NULL){
        if(instanceof<Student>(node)){
            Student* tempStudent = (Student*) node;
            cout << "\n\nStudent";
            cout << "\nID: " << tempStudent->getID();
            cout << "\nFirst Name: " << tempStudent->getFirstName();
            cout << "\nLast Name: " << tempStudent->getLastName();
            cout << "\nGPA: " << tempStudent->getGPA();
        }
        else if(instanceof<Professor>(node)){
            Professor* tempProfessor = (Professor*) node;
            cout << "\n\nProfessor";
            cout << "\nID: " << tempProfessor->getID();
            cout << "\nFirst Name: " << tempProfessor->getFirstName();
            cout << "\nLast Name: " << tempProfessor->getLastName();
            cout << "\nSalary: " << tempProfessor->getSalary();
            if(tempProfessor->getTenured()){
                cout << "\nTenured: Yes";
            }
            else{
                cout << "\nTenured: No";
            }
            tempProfessor->getTenured();
            if(tempProfessor->getDepartment() == English){
                cout << "\nDepartment: English";
            }
            else if(tempProfessor->getDepartment() == Business){
                cout << "\nDepartment: Business";
            }
            else if(tempProfessor->getDepartment() == Finance){
                cout << "\nDepartment: Finance";
            }
            else if(tempProfessor->getDepartment() == Journalism){
                cout << "\nDepartment: Journalism";
            }
            else if(tempProfessor->getDepartment() == Biology){
                cout << "\nDepartment: Biology";
            }
            else if(tempProfessor->getDepartment() == Physics){
                cout << "\nDepartment: Physics";
            }
            else if(tempProfessor->getDepartment() == Math){
                cout << "\nDepartment: Math";
            }
            else if(tempProfessor->getDepartment() == Engineering){
                cout << "\nDepartment: Engineering";
            }
            else{
                cout << "\nDepartment: Undeclared";
            }
        }
        else if(instanceof<Employee>(node)){
            Employee* tempEmployee = (Employee*) node;
            cout << "\nEmployee";
            cout << "\nID: " << tempEmployee->getID();
            cout << "\nFirst Name: " << tempEmployee->getFirstName();
            cout << "\nLast Name: " << tempEmployee->getLastName();
            cout << "\nSalary: " << tempEmployee->getSalary();
        }
        node = node->getNext(); 
    }
    printf("\n\n===========================================\n");
}

void saveLinkedList() {
    ofstream openRecords;
    openRecords.open("Directory.txt");
    Person* node = head;
    int personCount = 0; 
    while(node != NULL){
        personCount++; 
        node = node->getNext(); 
    }
    if (!openRecords.is_open()){
        cout << "Unable to write file\n";
    }
    else{
        openRecords << "Number of people at college: " << personCount;
        node = head;
        while(node != NULL){
            if(instanceof<Student>(node)){
                Student* tempStudent = (Student*) node;
                openRecords << "\nStudent" <<endl;
                openRecords << "ID: " << tempStudent->getID() <<endl;
                openRecords << "First Name: " << tempStudent->getFirstName() << endl;
                openRecords << "Last Name: " << tempStudent->getLastName() << endl;
                openRecords << "GPA: " << tempStudent->getGPA();
            }
            else if(instanceof<Professor>(node))
            {
                Professor* tempProfessor = (Professor*) node;
                openRecords << "\nProfessor" << endl;
                openRecords << "ID: " << tempProfessor->getID() <<endl;
                openRecords << "First Name: " << tempProfessor->getFirstName() <<endl;
                openRecords << "Last Name: " << tempProfessor->getLastName() <<endl;
                openRecords << "Salary: " << tempProfessor->getSalary() << endl;
                openRecords << "Tenured: " << tempProfessor->getTenured() << endl;
                if(tempProfessor->getDepartment() == English){
                    openRecords << "\nDepartment: English";
                }
                else if(tempProfessor->getDepartment() == Business){
                    openRecords << "\nDepartment: Business";
                }
                else if(tempProfessor->getDepartment() == Finance){
                    openRecords << "\nDepartment: Finance";
                }
                else if(tempProfessor->getDepartment() == Journalism){
                    openRecords << "\nDepartment: Journalism";
                }
                else if(tempProfessor->getDepartment() == Biology){
                    openRecords << "\nDepartment: Biology";
                }
                else if(tempProfessor->getDepartment() == Physics){
                    openRecords << "\nDepartment: Physics";
                }
                else if(tempProfessor->getDepartment() == Math){
                    openRecords << "\nDepartment: Math";
                }
                else if(tempProfessor->getDepartment() == Engineering){
                    openRecords << "\nDepartment: Engineering";
                }
                else{
                    openRecords << "\nDepartment: Undeclared";
                }
            }
            else if(instanceof<Employee>(node)){
                Employee* tempEmployee = (Employee*) node;
                openRecords << "\nEmployee" <<endl;
                openRecords << "ID: " << tempEmployee->getID() <<endl;
                openRecords << "First Name: " << tempEmployee->getFirstName() <<endl;
                openRecords << "Last Name: " << tempEmployee->getLastName() <<endl;
                openRecords << "Salary: " << tempEmployee->getSalary() <<endl;
            }
            node = node->getNext();
        }
        openRecords.close(); 
    }
}

void insertNode(Person* person_in){
    if(head == NULL){
        head = person_in;
        return;
    }
    else if(head->getNext() == NULL){
        if(head->getID() >= person_in->getID()){
            head->setNext(person_in);
            return;
        }
        else{
            Person* temp = head;
            head = person_in;
            head->setNext(temp);
            return;
        }
    }
    Person* node = head;
    while(node->getNext() != NULL){
        Person* nextNode = node->getNext();
        if((node->getID() > person_in->getID()) && (person_in->getID() >= nextNode->getID())){
            person_in->setNext(node->getNext());
            node->setNext(person_in);
            return;
        }
        else if(node->getID() <= person_in->getID()){
            person_in->setNext(node);
            head = person_in;
            return;
        }
        node = node->getNext();
    }
    node->setNext(person_in);
    person_in->setNext(NULL);
    return;
}

void deleteNode(Person* person_in){
    Person* currentPerson = head;
    Person* prevPerson = NULL;
    
    if(head == person_in){
        head = head->getNext();
        delete person_in;
        return;
    }
    while(currentPerson != NULL && currentPerson != person_in) {
        prevPerson = currentPerson;
        currentPerson = currentPerson->getNext(); 
    }
    if(currentPerson != NULL){
        prevPerson->setNext(currentPerson->getNext());
    }
    delete person_in;
}

void addToLinkedList(){
    int user_input = 0;
    do{
        int identity;
        string first_nameput, last_nameput;
        float gpa_input, salary_input;
        bool tenuredProfput;
        Department departmentProfput;
        string temp;
        Person* identityCheck = head;
        
        addAndDiplayMenu();
        cout << "\nWho would you like to add? ";
        cin >> user_input;
        
        switch(user_input){
            case 1 :{
                printf("\nEnter the ID of the student: "); 
                cin >> identity; 
                while(identityCheck != NULL){
                    if(identity == identityCheck->getID()){
                        printf("\n ID is currently used by an existing person."); 
                        identityCheck = head; 
                        printf("\nStudent ID: "); 
                        cin >> identity;
                    }
                    identityCheck = identityCheck->getNext(); 
                }
                printf("\nFirst name of the student: "); 
                cin >> first_nameput;
                printf("\nLast name of the student: "); 
                cin >> last_nameput;
                
                printf("\nGPA of the student: "); 
                cin >> gpa_input;
               
                Person* aPointer = new Student(identity, first_nameput, last_nameput, gpa_input);
                insertNode(aPointer);
                break;
            }
            case 2 :{
                printf("\nID of the professor: ");
                cin >> identity; 
                while(identityCheck != NULL){
                    if(identity == identityCheck->getID()){
                        printf("\nID is currently used by an existing person: ");
                        identityCheck = head; 
                        printf("\nProfessor ID: ");
                        cin >> identity; 
                    }
                    identityCheck = identityCheck->getNext(); 
                }
                
                printf("\nFirst name of the professor: "); 
                cin >> first_nameput;
                
                printf("\nLast name of the professor: ");
                cin >> last_nameput;
                
                printf("\nSalary of the professor: ");
                cin >> salary_input;
                
                cout << "\nIs the professor tenured? [yes/no]  ";
                cin >> temp;
                string yes = "yes";
                string no = "no";
                if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
                    tenuredProfput = true;
                else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
                    tenuredProfput = false;
                else{
                    bool check = true;
                    while(check){
                        cout << "\n Indicate either [yes] or [no]: ";
                        cin >> temp;
                        if(strcasecmp(yes.c_str(), temp.c_str()) == 0){
                            tenuredProfput = true;
                            check = false;
                        }
                            
                        else if(strcasecmp(no.c_str(), temp.c_str()) == 0){
                            tenuredProfput = false;
                            check = false;
                        }
                    }
                }
                
                cout << "\nProfessor's Department: ";
                cin >> temp;
                
                if(temp == "English"){departmentProfput = English;}
                else if(temp == "Business"){departmentProfput = Business;}
                else if(temp == "Philsophy"){departmentProfput = Finance;}
                else if(temp == "Journalism"){departmentProfput = Journalism;}
                else if(temp == "Biology"){departmentProfput = Biology;}
                else if(temp == "Physics"){departmentProfput = Physics;}
                else if(temp == "Math"){departmentProfput = Math;}
                else if(temp == "Engineering"){departmentProfput = Engineering;}
                else{departmentProfput = Undeclared;}
                
                Person* aPointer = new Professor(identity, first_nameput, last_nameput, salary_input, tenuredProfput, departmentProfput);
                insertNode(aPointer);
                break;
            }
            case 3 :{
                printf("\nEnter employee id number: "); 
                cin >> identity;
                while(identityCheck != NULL){
                    if(identity == identityCheck->getID()) {
                        printf("\n ID is currently used by an existing person."); 
                        identityCheck = head; 
                        printf("\nEmployee ID Number: ");
                        cin >> identity;
                    }
                    identityCheck = identityCheck->getNext(); 
                }
                
                printf("\nEmployee first name: ");
                cin >> first_nameput;
                
                printf("\nEmployee last name: "); 
                cin >> last_nameput;
                
                printf("\nEmployee salary: "); 
                cin >> salary_input;
                
                Person* aPointer = new Employee(identity, first_nameput, last_nameput, salary_input);
                insertNode(aPointer);
                break;
            }
            
            case 4 :
                break; 
                
            default : 
                break;
        }
    }while(user_input != 4);
}

void removeIdFromLinkedList(int id_in){
    Person* node = head;
    while(node != NULL){
        if(id_in == node->getID()){
            string first = node->getFirstName();
            string last =  node->getLastName();
            deleteNode(node); 
            cout << "\n" << first << " " << last << " was successfully deleted."; 
            return; 
        }
        node = node->getNext();
    }
    cout << "\nThere is no person associated with the given ID.";
}

void updateIdInLinkedList(int id_in){
    Person* node = head;
    int user_input = 0;
    while(node != NULL){
        if(id_in == node->getID()){
            if(instanceof<Student>(node)){
                do{
                    updateStudentMenu(node->getFirstName(), node->getLastName()); 
                    cin >> user_input; 

                    int new_identity, old_identity = 0;
                    string new_firstName = "";
                    string old_firstName = "";
                    string new_lastName = "";
                    string old_lastName = "";
                    string temp = "";
                    float new_gpa, old_gpa = 0.0;
                    Person* identityCheck = head;
                    Student* tempStudent = (Student*) node;
                    
                    switch(user_input){
                        case 1 : 
                            cout << "\nEnter a new ID: "; 
                            cin >> new_identity; 
                            while(identityCheck != NULL){
                                if(new_identity == identityCheck->getID()){
                                    printf("\nEntered ID is being used");
                                    identityCheck = head; 
                                    printf("\nEnter the ID of student: ");
                                    scanf("%d", &new_identity); 
                                }
                                identityCheck = identityCheck->getNext(); 
                            }
                            old_identity = tempStudent->getID(); 
                            tempStudent->setID(new_identity); 
                            node = tempStudent;
                            printf("\n%d was sucessfully updated to %d", old_identity, new_identity); 
                            break; 
                        case 2 : 
                            printf("\nEnter new first name: "); 
                            cin >> new_firstName;
                            old_firstName = tempStudent->getFirstName(); 
                            tempStudent->setFirstName(new_firstName);
                            cout << "\n" << old_firstName << " was sucessfully updated to " << new_firstName;
                            node = tempStudent;
                            break; 
                        case 3 : 
                            printf("\nEnter new last name: ");
                            cin >> new_lastName;
                            old_lastName = tempStudent->getLastName(); 
                            tempStudent->setLastName(new_lastName); 
                            cout << "\n" << old_lastName<< " was sucessfully updated to " << new_lastName; 
                            node = tempStudent;
                            break; 
                        case 4 : 
                            printf("\nEnter new GPA: "); 
                            scanf("%f", &new_gpa); 
                            old_gpa = tempStudent->getGPA();
                            tempStudent->setGPA(new_gpa); 
                            node = tempStudent;
                            printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); 
                            break; 
                        
                        case 5 :
                            break; 
                        
                        default : 
                            printf("\nInvalid input\n");
                    }
                }while(user_input != 5);
                return;
            }
            else if(instanceof<Professor>(node)){
                do {
                    updateProfessorMenu(node->getFirstName(), node->getLastName()); 
                    cin >> user_input;

                    int new_identity, old_identity = 0;
                    string new_firstName = "";
                    string old_firstName = "";
                    string new_lastName = "";
                    string old_lastName = "";
                    string temp, temp2 = "";
                    float new_salary, old_salary = 0.0;
                    bool new_ten, old_ten = false;
                    Department new_dep;
                    Person* identityCheck = head;
                    Professor* tempProfessor = (Professor*) node;
                    
                    switch(user_input){
                        case 1 : {
                            cout << "\nEnter new ID number: ";
                            cin >> new_identity; 
                            while(identityCheck != NULL){
                                if(new_identity == identityCheck->getID()) {
                                    printf("\nEntered ID number is currently being used."); 
                                    identityCheck = head; 
                                    printf("\nEnter the ID number: ");
                                    scanf("%d", &new_identity); 
                                }
                                identityCheck = identityCheck->getNext(); 
                            }
                            old_identity = tempProfessor->getID(); 
                            tempProfessor->setID(new_identity); // Change the ID.
                            node = tempProfessor;
                            printf("\n%d was sucessfully updated to %d", old_identity, new_identity); 
                            break; 
                        }

                        case 2 : {
                            printf("\nEnter new first name: ");
                            cin >> new_firstName;
                            old_firstName = tempProfessor->getFirstName(); 
                            tempProfessor->setFirstName(new_firstName); 
                            cout << "\n" << old_firstName << " was sucessfully updated to " << new_firstName;
                            node = tempProfessor;
                            break; 
                        }

                        case 3 :{
                            printf("\nEnter new last name: ");
                            cin >> new_lastName;
                            old_lastName = tempProfessor->getLastName(); 
                            tempProfessor->setLastName(new_lastName);
                            cout << "\n" << old_lastName<< " was sucessfully updated to " << new_lastName; 
                            node = tempProfessor;
                            break; 
                        }
                        case 4 :{
                            printf("\nEnter new Salary: "); 
                            scanf("%f", &new_salary);
                            old_salary = tempProfessor->getSalary();
                            tempProfessor->setSalary(new_salary);
                            node = tempProfessor;
                            printf("\n%f was sucessfully updated to %f", old_salary, new_salary); 
                            break; 
                        }
                        
                        case 5 : {
                            cout << "\nAre they tenured? (yes/no) ";
                            cin >> temp;
                            string yes = "yes";
                            string no = "no";
                            if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
                                new_ten = true;
                            else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
                                new_ten = false;
                            else{
                                bool check = true;
                                while(check){
                                    cout << "\nPlease indicate with a [yes] or a [no]: ";
                                    cin >> temp;
                                    if(strcasecmp(yes.c_str(), temp.c_str()) == 0){
                                        new_ten = true;
                                        check = false;
                                    }
                                        
                                    else if(strcasecmp(no.c_str(), temp.c_str()) == 0){
                                        new_ten = false;
                                        check = false;
                                    }
                                }
                            }
                            old_ten = tempProfessor->getTenured();
                            tempProfessor->setTenured(new_ten);
                            node = tempProfessor;
                            if(new_ten == old_ten)
                                cout << "\nNo changes were made (value entered was the same as the current value)";
                            else
                                cout << "\nTenured was updated";
                            break;
                        }
                        
                        case 6 :{
                            cout << "\nProfessor's department: ";
                            cin >> temp;
                            
                            if     (temp == "English"){new_dep = English;}
                            else if(temp == "Business"){new_dep = Business;}
                            else if(temp == "Philsophy"){new_dep = Finance;}
                            else if(temp == "Journalism"){new_dep = Journalism;}
                            else if(temp == "Biology"){new_dep = Biology;}
                            else if(temp == "Physics"){new_dep = Physics;}
                            else if(temp == "Math"){new_dep = Math;}
                            else if(temp == "Engineering"){new_dep = Engineering;}
                            else{new_dep = Undeclared;}
                            
                            if(tempProfessor->getDepartment() == English){
                                temp2 = "English";
                            }
                            else if(tempProfessor->getDepartment() == Business){
                                temp2 = "Business";
                            }
                            else if(tempProfessor->getDepartment() == Finance){
                                temp2 = "Finance";
                            }
                            else if(tempProfessor->getDepartment() == Journalism){
                                temp2 = "Journalism";
                            }
                            else if(tempProfessor->getDepartment() == Biology){
                                temp2 = "Biology";
                            }
                            else if(tempProfessor->getDepartment() == Physics){
                                temp2 = "Physics";
                            }
                            else if(tempProfessor->getDepartment() == Math){
                                temp2 = "Math";
                            }
                            else if(tempProfessor->getDepartment() == Engineering){
                                temp2 = "Engineering";
                            }
                            else{
                                temp2 = "Undeclared";
                            }
                            tempProfessor->setDepartment(new_dep);
                            node = tempProfessor;
                            cout << "\n" << temp2 << " was successfully updated to " << temp;
                            break;
                        }
                        
                        case 7 :{
                            break;
                        }
                        
                        default : 
                            printf("\nInvalid input\n");
                    }
                }while(user_input != 7);
                return;
            }
            else if(instanceof<Employee>(node)){
                do{
                    updateEmployeeMenu(node->getFirstName(), node->getLastName()); 
                    cin >> user_input; 
                    int new_identity, old_identity = 0;
                    string new_firstName = "";
                    string old_firstName = "";
                    string new_lastName = "";
                    string old_lastName = "";
                    string temp = "";
                    float new_salary, old_salary = 0.0;
                    Person* identityCheck = head;
                    Employee* tempStudent = (Employee*) node;
                    
                    switch(user_input){
                        case 1 :
                            cout << "\nEnter the new ID: "; 
                            cin >> new_identity; 
                            while(identityCheck != NULL){
                                if(new_identity == identityCheck->getID()){
                                    printf("\nEntered ID is being currently used."); 
                                    identityCheck = head; 
                                    printf("\nEnter the ID: ");
                                    scanf("%d", &new_identity); 
                                }
                                identityCheck = identityCheck->getNext();
                            }
                            old_identity = tempStudent->getID(); 
                            tempStudent->setID(new_identity);
                            node = tempStudent;
                            printf("\n%d was sucessfully updated to %d", old_identity, new_identity); 
                            break; 
                        case 2 : 
                            printf("\nEnter new first name: ");
                            cin >> new_firstName;
                            old_firstName = tempStudent->getFirstName(); 
                            tempStudent->setFirstName(new_firstName);
                            cout << "\n" << old_firstName << " was sucessfully updated to " << new_firstName;
                            node = tempStudent;
                            break; 
                        case 3 :
                            printf("\nEnter new last name: "); 
                            cin >> new_lastName;
                            old_lastName = tempStudent->getLastName(); 
                            tempStudent->setLastName(new_lastName); 
                            cout << "\n" << old_lastName<< " was sucessfully updated to " << new_lastName; 
                            node = tempStudent;
                            break; 
                        case 4 : 
                            printf("\nEnter new Salary: ");
                            scanf("%f", &new_salary); 
                            
                            old_salary = tempStudent->getSalary();
                            tempStudent->setSalary(new_salary); 
                            node = tempStudent;
                            printf("\n%f was sucessfully updated to %f", old_salary, new_salary);
                            break;
                        case 5 :
                            break; 
                        default :
                            printf("\nInvalid input\n");
                    }
                }while(user_input != 5);
                return;
            }
        }
        node = node->getNext();
    }
    cout << "\nThere is no person associated with the given ID.";
}

void menu(){
    printf("\n----------Menu----------");
    printf("\n [1] List");
    printf("\n [2] Add");
    printf("\n [3] Remove");
    printf("\n [4] Update");
    printf("\n [5] Quit");
    printf("\n ------------------------\n");
}

void addAndDiplayMenu() {
    printf("\n----------Select an Option----------");
    printf("\n [1] Student");
    printf("\n [2] Professor");
    printf("\n [3] Employee");
    printf("\n [4] Save and Quit");
    printf("\n------------------------------------\n");
}

void updateStudentMenu(string first, string last){
    printf("\n-------------Update Menu-------------");
    cout <<"\n Select a category to update for: " << first << " " << last;
    printf("\n [1] ID");
    printf("\n [2] First Name");
    printf("\n [3] Last Name");
    printf("\n [4] GPA");
    printf("\n [5] Save and Quit");
    printf("\n-------------------------------------\n");
}

void updateProfessorMenu(string first, string last){
    printf("\n-------------Update Menu-------------");
    cout << "\n Select a category to update for: " << first << " " << last;
    printf("\n [1] ID");
    printf("\n [2] First Name");
    printf("\n [3] Last Name");
    printf("\n [4] Salary");
    printf("\n [5] Tenured");
    printf("\n [6] Department");
    printf("\n [7] Save and Quit");
    printf("\n-------------------------------------\n");
    printf("\n\n");
}

void updateEmployeeMenu(string first, string last) {
    printf("\n-------------Update Menu-------------");
    cout << "\n Select a category to update for: " << first << " " << last;
    printf("\n [1] ID");
    printf("\n [2] First Name");
    printf("\n [3] Last Name");
    printf("\n [4] Salary");
    printf("\n [5] Save and Quit");
    printf("\n-------------------------------------\n");
    printf("\n\n");
}
