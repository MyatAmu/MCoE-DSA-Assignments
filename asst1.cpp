#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
};

void display(Student arr[], int n) {
    cout << "Roll\tName\tSGPA" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].roll << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
    }
}

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll > arr[j + 1].roll) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > key.name) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(Student arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left].sgpa;
        int low = left + 1;
        int high = right;
        while (true) {
            while (low <= high && arr[high].sgpa <= pivot) {
                high--;
            }
            while (low <= high && arr[low].sgpa >= pivot) {
                low++;
            }
            if (low <= high) {
                swap(arr[low], arr[high]);
            } else {
                break;
            }
        }
        swap(arr[left], arr[high]);
        quickSort(arr, left, high - 1);
        quickSort(arr, high + 1, right);
    }
}

void linearSearch(Student arr[], int n, float target) {
    bool found = false;
    cout << "Students with SGPA " << target << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].sgpa == target) {
            cout << "Roll: " << arr[i].roll << ", Name: " << arr[i].name << ", SGPA: " << arr[i].sgpa << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with SGPA " << target << endl;
    }
}

int binarySearch(Student arr[], int n, string target) {
    int left = 0;
    int right = n - 1;
    int foundCount = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].name == target) {
            cout << "Roll: " << arr[mid].roll << ", Name: " << arr[mid].name << ", SGPA: " << arr[mid].sgpa << endl;
            foundCount++;

            int leftIndex = mid - 1;
            while (leftIndex >= 0 && arr[leftIndex].name == target) {
                cout << "Roll: " << arr[leftIndex].roll << ", Name: " << arr[leftIndex].name << ", SGPA: " << arr[leftIndex].sgpa << endl;
                leftIndex--;
                foundCount++;
            }

            int rightIndex = mid + 1;
            while (rightIndex < n && arr[rightIndex].name == target) {
                cout << "Roll: " << arr[rightIndex].roll << ", Name: " << arr[rightIndex].name << ", SGPA: " << arr[rightIndex].sgpa << endl;
                rightIndex++;
                foundCount++;
            }
            
            return foundCount;
        } else if (arr[mid].name < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    const int maxSize = 15;
    Student data[maxSize];
    int option;
    int n;
    cout << "Enter the number of students (up to " << maxSize << "): ";
    cin >> n;

    if (n > maxSize) {
        cout << "Number of students exceeds the maximum limit." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout << "Roll No.: ";
        cin >> data[i].roll;
        cout << "Name: ";
        cin.ignore();
        getline(cin, data[i].name);
        cout << "SGPA: ";
        cin >> data[i].sgpa;
    }
    do{
        cout << "Enter the Operation to perform." << endl;
        cout << "Select option number.Enter 0 to EXIT"<<endl;
        cout << "1.Sort by Roll No." << endl;
        cout << "2.Sort Alphabetically" << endl;
        cout << "3.Top Ten Toppers" << endl;
        cout << "4.Search SGPA" << endl;
        cout << "5.Search Name" << endl;

        cin >> option;
        switch (option){
            case 0:
                break;

            case 1:
                bubbleSort(data, n);
                cout << "******************************" << endl;
                cout << "Sorted by Roll (Ascending):" << endl;
                display(data, n);
                cout << "******************************" << endl;
                break;

            case 2:
                insertionSort(data, n);
                cout << "******************************" << endl;
                cout << "Sorted Alphabetically:" << endl;
                display(data, n);
                cout << "******************************" << endl;
                break;

            case 3:
                quickSort(data, 0, n - 1);
                cout << "******************************" << endl;
                cout << "Top Ten Toppers:" << endl;
                display(data, min(n, 10));
                cout << "******************************" << endl;
                break;

            case 4:
                float targetSGPA;
                cout << "******************************" << endl;
                cout << "Enter the SGPA to search for: ";
                cin >> targetSGPA;
                linearSearch(data, n, targetSGPA);
                cout << "******************************" << endl;
                break;

            case 5:
                string targetName;
                cin.ignore();
                cout << "******************************" << endl;
                cout << "Enter the name to search for: ";
                getline(cin, targetName);
                int foundCount = binarySearch(data, n, targetName);

                if (foundCount == 0) {
                    cout << "No students found with the name " << targetName << endl;
                } 
                else {
                    cout << "Total " << foundCount << " student(s) found with the name " << targetName << endl;
                }
                cout << "******************************" << endl;
                break;
        }
    }while(option != 0);
    return 0;
}
