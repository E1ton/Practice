#include <iostream>
#include <queue>
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

void QuickSort(int array[], int left, int right) {
    if(left < right) {
        int pivot = array[right];
        int pi = left;
        for(int i = left; i<right; i++) {
            if(array[i] <= pivot) {
                swap(&array[i], &array[pi++]);
            }
        }
        swap(&array[pi], &array[right]);
        QuickSort(array, left, pi-1);
        QuickSort(array, pi+1, right);
    }
}

void HeapSort(int array[],int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        pq.push(array[i]);
    }
    for(int i=0; i<n; i++) {
        array[i] = pq.top();
        pq.pop();
    }
}

void merge(int array[], int left, int right, int mid) {
    int a1l = mid - left + 1;
    int a2l = right - mid;
    int a1[a1l], a2[a2l];
    for(int i=0; i<a1l; i++) {
        a1[i] = array[left+i];
    }
    for(int i=0; i<a2l; i++) {
        a2[i] = array[mid + i + 1];
    }
    int i=0,j=0,k=left;
    while(i<a1l && j<a2l) {
        a1[i] <= a2[j] ? array[k++] = a1[i++] : array[k++] = a2[j++];
    }
    while(i<a1l) {
        array[k++] = a1[i++];
    }
    while(j<a2l) {
        array[k++] = a2[j++];
    }
}

void MergeSort(int array[], int left, int right) {
    if(left < right) {
        int mid = (right + left) >> 1;
        MergeSort(array, left, mid);
        MergeSort(array, mid+1, right);
        merge(array, left, right, mid);
    }
}

int main() {
    int test[] = {3,4,6,77,2,5,3,1};
    MergeSort(test,0,7);
    for(int i=0; i<8; i++) {
        cout << test[i] << ' ';
    }
}