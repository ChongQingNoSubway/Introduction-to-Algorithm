#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdio>

using namespace std;

struct Student {
    int key; //this is hash table key value
    float GPA; // student GPA   
    string name; // student name
    string AL; //academic level
    struct Student *next; // When the hash table takes place the collision
};


struct Student* createRecord(vector<long> keys){
    struct Student* newRecord = new Student();

    getchar();

    cout<<"enter the name: " << endl;
    getline(cin, newRecord->name);
    cout<<"enter the academic level: "<<endl;
    getline(cin,newRecord->AL);
    cout<<"enter GPA:"<<endl;
    cin>>newRecord->GPA;
    cout<<"enter the key value:"<<endl;
    cin>>newRecord->key;
    newRecord->next = NULL;

    cout << "====================================="<< endl;    
    cout<<"this new reord assigned to"
    << " key =" << newRecord->key<<endl;
    cout << "====================================="<< endl;
    return newRecord;
}

void hashInsert(struct Student *T[1000], struct Student* x){
    int index = (x->key%1000); //hash index

    if(T[index] == NULL){
        T[index] = x;

    }else{
        struct Student *mid = T[index];
        while(mid->next != NULL){
            mid = mid->next;
        }
        mid->next = x;
    }
}

struct Student* hashSearch (struct Student* T[1000], long k) {
    int index = (k%1000);
    if(T[index] == NULL){
        return NULL;

    }else{
        struct Student *mid = T[index];
        while(mid != NULL){
            if(mid->key == k){
                return mid;
            }
            mid = mid->next;
        }
        return NULL;
    }
}

void DeleteHash(struct Student* T[1000], struct Student* x){
    int index = (x->key%1000);

    struct Student *current  = T[index];
    struct Student *previous = NULL;

    while(current != x){
        previous = current;
        current = current->next;
    }

    if(previous == NULL){
        T[index] = x->next;
        free(x);
    }
    else{
        previous->next = x->next;
        free(x);
    }
}

void showSerachRecord(struct Student* record){
    cout << "==================="<<endl;
    cout << "record Name: "

    << record->name << endl;

    cout << "Academic Level: "

    << record->AL << endl;

    cout << "GPA: "

    << record->GPA << endl;

    cout << "Key: " << record->key<< endl ;
    cout << "==================="<<endl;
}



int main()

{
    srand(time(NULL));
    struct Student* T[1000];
    for(int i=0; i<1000;i++)
    {

        T[i] = NULL;

    }
    int num_students = 0;
    vector<long> keys;

    int choice = -1;
    while(choice != 5)

    {

        struct Student* new_record;

        struct Student* temp;

        long del_key = -1;

        long search_key = -1;

        cout << "1. Insert a record(enter the name gpa academic level key to insert into hash table)" << endl;

        cout << "2. Delete the record(enter a key of the record to deleted)" << endl;

        cout << "3. Search the table(enter a key to search record)" << endl;

        cout << "4. exit" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice)

        {
            case 1:
            if(num_students <10000)
            {
                new_record = createRecord(keys);
                keys.push_back(new_record->key);
                hashInsert(T, new_record);
                num_students++;
            }
            else
            {
                cout << "The Hash Table is full"
                << endl;
            }
            break;

            case 2:
            cout << "Enter the key: "<< endl;
            cin >> del_key;
            temp = hashSearch(T, del_key);
            if(temp == NULL)
            {
                cout << "================"<< endl;                
                cout << "NOT FOUND"<< endl;
                cout << "================"<< endl;                
            }
            else
            {
                DeleteHash(T, temp);
                for(int i=0; i<num_students; i++)
                {
                    if(keys[i] == del_key)
                    {
                        keys[i] = keys[num_students-1];
                        break;
                    }  
                }

                keys.pop_back();
                num_students--;
                cout << "================"<< endl;
                cout << "delete success!!"<< endl;
                cout << "================"<< endl;                
            }
            break;

            case 3:
            cout << "Enter the key: "<<endl;
            cin >> search_key;
            temp = hashSearch(T, search_key);
            if(temp == NULL)
            {
                cout << "================"<< endl;                
                cout << "NOT FOUND"<< endl;
                cout << "================"<< endl;                
            }else{
                showSerachRecord(temp);
            }
            break;

            case 4:
            break;

            default:
            cout << "wrong choice"
            << endl;

        }

    }

    return 0;

}
