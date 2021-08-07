#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// Create a class of student record node

class StudentRecord{

    public:
        string name;
        float average;
        StudentRecord *next;

    public:
        StudentRecord(string name, float average){
            this-> name = name;
            this->average = average;
            next = NULL;
        }
};  


// create a class of student
class student {
    private:
        StudentRecord *head, *tail;
    public:
        student(){
            head = NULL;
            tail = NULL;
        }

        void addStudent(string name, float average);

        void displayRecord();

        int CountOfRecord();
};


// define the add function to add the new student record
void student::addStudent(string name, float average){

    StudentRecord *current = new StudentRecord(name,average);

    if(head == 0){
        head = tail = current;
    }else{
        tail->next = current;
        tail = current;
    }
}

// define the display student record function
void student::displayRecord(){
    StudentRecord *current = head;

    if (current == NULL) {
        cout << "Student Count : 0"<<endl;
        return;
    }
    //    cout<<"===================================="<<endl;
    //   display box can easy see the result
    cout<<"===================================="<<endl;
    while(current != NULL) {
        cout << current->name << " ";
        printf("%1f\n", current->average);
        current = current->next;
    }
    cout<<"===================================="<<endl;
}


//define the count number of student record
int student::CountOfRecord() {
    int cout = 0;

    StudentRecord *current = head;

    while(current != NULL) {
        cout++;
        current = current->next;
    }

    return cout;
}


int main() {
    
    int option;
    student linklist_student;
    string name;
    float average;


    do {
        cout<<"1. Add Student record"<<endl;
        cout<<"2. Display student records"<<endl;
        cout<<"3. Count number of records"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"plase enter your option:"<<endl;
        cin>>option;

        switch (option) {
            case 1: 
                // add new student record
                cout<<"Enter the Name please:"<<endl;
                // fix input name with spaces
                cin.ignore();
                getline(cin,name);
                cout<<"Enter the average please:"<<endl;
                cin>>average;
                linklist_student.addStudent(name,average);
                break;

            case 2:
                // display student record
                linklist_student.displayRecord();
                break;
            
            case 3:
                //    cout<<"===================================="<<endl;
                //    display box
                cout<<"===================================="<<endl;
                cout<<"the number of student records : ";
                printf("%d\n",linklist_student.CountOfRecord());
                cout<<"===================================="<<endl;
                break;
        }
    }
    while(option!=4);
}