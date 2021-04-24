#include <iostream>
#include <queue>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[root])
        root = l;
    if (r < n && arr[r] > arr[root])
        root = r;
    if (root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}
  
void buildHeap(int arr[], int n){
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

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

/*
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode *> s;
        while(true) {
            if(root != nullptr) {
                s.push(root);
                root = root->left;
            }else{
                if(s.empty()) break;
                root = s.top();
                v.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return v;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode * node;
        while(!s.empty()) {
            v.push_back(s.top()->val);
            node = s.top();
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return v;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        TreeNode * node;
        while(!s1.empty()) {
            node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()) {
            node = s2.top();
            s2.pop();
            v.push_back(node->val);
        }
        return v;
    }   
    */
   