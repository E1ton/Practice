#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;    
}
//if n not provided we can use 'sizeof(array)/sizeof(array[0])' to calculate size
void bubbleSort(int array[], int n) {
    bool sorted = true;
    do {
        sorted = true;
        for(int i=0; i<n-1; i++) {
            if(array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
                sorted = false;
            }
        }
    } while(sorted == false);
}

void selectionSort(int array[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(array[j] < array[i]) swap(&array[i], &array[j]);
        }
    }
}

void insertionSort(int array[], int n) {
    for(int i=0; i<n; i++) {
        int j = i - 1;
        int curr = array[i];
        while(j >= 0 && array[j] > curr) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = curr;
    }
}

void shellSort(int array[], int n) {
    for(int gap = n/2; gap>0; gap /= 2) {
        for(int i=0; i<n; i+=1) {
            int j = i-gap;
            int curr = array[i];
            while(j >= 0 && array[j] > curr) {
                array[j+gap] = array[j];
                j -= gap; 
            }
            array[j+gap] = curr;
        }
    }
}

int main() {
    int test[] = {3,4,6,77,2,5,3,1};
    shellSort(test, 8);
    for(int i=0; i<8; i++) {
        cout << test[i] << ' ';
    }
}