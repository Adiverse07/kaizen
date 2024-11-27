#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int credits;
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].credits;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].credits >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void display(Student arr[], int size){
    for(int i=size-1; i>=0; i--){
        cout << arr[i].credits << " ";
    }
}

void displayTop3Students(Student arr[], int size) {
    cout << "\nTop 3 students based on credits:\n";
    for (int i = 0; i < 3 && i < size; i++) {
        cout << i + 1 << ". " << arr[i].name << " - " << arr[i].credits << " credits" << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << (i + 1) << ": ";
        cin >> students[i].name;
        cout << "Enter credits received by " << students[i].name << " in the last 2 years: ";
        cin >> students[i].credits;
    }

    cout << "Sorted Array: ";
    display(students, n);
    cout << endl;
    quickSort(students, 0, n - 1);
    displayTop3Students(students, n);

    return 0;
}
