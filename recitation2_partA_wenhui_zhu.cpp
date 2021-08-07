#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
#define MIN 100

using namespace std;



//swap two element position in array
void swapArray(double A[], int i , int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
// print array
void PrintArray(double array[], int length){
    for(int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// INSERTION SORT
void insertionSort(double A[], int length){
    for(int i =1 ; i < length ; i++){
        int j = i - 1;
        double key = A[i];

        while (j >= 0 && key < A[j])
        {
            A[j+1] = A[j];
            j--;
        }
        
        A[j+1] = key;
    }
}



//MERGE SORT 
void merge(double A[], int  low, int  mid, int high){
    int left = mid - low + 1;
    int right = high - mid;

    // Create left and right subarray
    double L[left],R[right];

    for(int i = 0; i < left; i++){
        L[i] = A[low + i];
    }
    for(int j = 0; j < right; j++){
        R[j] = A[mid + 1 + j];
    }       
    int left_index, right_index, A_index;
    left_index = 0;
    right_index = 0;
    A_index = low;

    while(left_index < left && right_index < right){
        if(L[left_index] <= R[right_index]){
            A[A_index++] = L[left_index];
            left_index++;
        }else{
            A[A_index++] = R[right_index];
            right_index++;
        }
    }

    while(left_index < left){
        A[A_index] = L[left_index];
        left_index++;
        A_index++;
    }

    while (right_index < right){
        A[A_index] = R[right_index];
        right_index++;
        A_index++;
    }
    
}

void merge_sort(double A[], int low, int high){
    if(low >= high){
        return;
    }
    int mid =low+(high-low)/2;
    merge_sort(A,low,mid);
    merge_sort(A,mid+1,high);
    // merge
    merge(A, low, mid, high);
}



// Quick Sort
int partition(double A[], int p, int r){
    int x = A[r];
    int i = p -1;

    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            swapArray(A,j,i);
        }
    }

    swapArray(A,r,i+1);
    return i + 1;
}

void quickSort(double A[], int p, int r){
    if(p < r){
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}





//Select Sort
void selectionSort(double A[], int length){
    for(int i = 0; i < length - 1; i++){
        int min = i;
        for(int j = i + 1; j < length; j++){
            if( A[j] < A[min]){
                min = j;
            }
        }
        swapArray(A,min,i);
    }
}


//Generate the measure array 
double* getMeasureArray(int size){
    srand(time(NULL));
    double* A = (double*)malloc(size * sizeof(double));
    for(int i = 0; i < size; i++) {
        int temp = (rand()%(MAX-MIN+1)-MIN);
        A[i] = temp;
    }
    return A;
}


int main(){
    double* Test;
    
    int size;
    clock_t begin, end;
    float time_execution;
    int sizes[] = {1000,10000,25000, 50000, 100000, 150000, 200000};

    for(int i = 0; i < 7; i++){
        size = sizes[i];

        // insertion sort
        cout<<"==================================="<<endl;
        Test = getMeasureArray(size);
        begin = clock();
        insertionSort(Test,size);
        end = clock();
        time_execution = ((float)(end - begin) / 1000000.0F)*1000;
        cout<< "running time of size is " << size << " of insertionSort: " <<time_execution << endl;

        // merge sort
        cout<<"==================================="<<endl;
        Test = getMeasureArray(size);
        begin = clock();
        merge_sort(Test,0,size-1);
        end = clock();
        time_execution = ((float)(end - begin) / 1000000.0F)*1000;
        cout<< "running time of size is " << size << " of mergesort: " <<time_execution << endl;        

        // quick sort
        cout<<"==================================="<<endl;
        Test = getMeasureArray(size);
        begin = clock();
        quickSort(Test,0,size-1);
        end = clock();
        time_execution = ((float)(end - begin) / 1000000.0F)*1000;
        cout<< "running time of size is " << size << " of quicksort: " <<time_execution << endl;

        // selection sort
        cout<<"=================================="<<endl;
        Test = getMeasureArray(size);
        begin = clock();
        selectionSort(Test,size);
        end = clock();
        time_execution = ((float)(end - begin) / 1000000.0F)*1000;
        cout<< "running time of size is " << size << " of selectionsort: " <<time_execution << endl;                
    }


    // // Test methods
    // double A[] = {9,8,7,6,5,4,3,2,1};
    // int length = sizeof(A)/sizeof(double);
    // selectionSort(A,length);
    // insertionSort(A,length);
    // merge_sort(A,0,length-1);
    // quickSort(A,0,length-1);
    // PrintArray(A,length);
    return 0;
}