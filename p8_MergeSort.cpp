#include <iostream>
#define ARR_LEN 5

using namespace std;

int* take_input(int* arr, int size){
    for(int i=0; i<size; i++){
        int inp;
        cout << "Digit " << i << ": ";
        cin >> inp;
        arr[i] = inp;
    }
    return arr;
}

int* b_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

void merge(int* leftArray, int* rightArray, int left_size, int right_size, int* arr) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = leftArray[i++];
    }

    while (j < right_size) {
        arr[k++] = rightArray[j++];
    }
}

int* merge_sort(int* arr, int size) {
    if (size <= 1) return arr;

    int mid = size / 2;

    int leftArray[mid];
    int rightArray[size - mid];

    for (int i = 0; i < mid; i++) {
        leftArray[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        rightArray[i - mid] = arr[i];
    }

    merge_sort(leftArray, mid);
    merge_sort(rightArray, size - mid);

    merge(leftArray, rightArray, mid, size - mid, arr);

    return arr;
}

void display(int* arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    cout << ARR_LEN << endl;
    int inp_arr[ARR_LEN];
    // display(take_input(inp_arr, ARR_LEN), ARR_LEN);
    // cout << endl << endl;
    display(merge_sort(take_input(inp_arr, ARR_LEN), ARR_LEN), ARR_LEN);
    // display(b_sort(take_input(inp_arr, ARR_LEN), ARR_LEN), ARR_LEN);

    return 0;
}