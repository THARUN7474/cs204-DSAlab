#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Function to save student data to a file
void saveToFile(struct Student *students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "wb");  // Open the file in binary write mode

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the array of students to the file
    fwrite(students, sizeof(struct Student), numStudents, file);

    fclose(file);
}

// Function to read student data from a file
void readFromFile(struct Student *students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open the file in binary read mode

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the array of students from the file
    fread(students, sizeof(struct Student), numStudents, file);

    fclose(file);
}

int main() {
    const char *filename = "students.dat";
    const int numStudents = 3;

    struct Student students[numStudents];

    // Check if there is existing data in the file
    FILE *checkFile = fopen(filename, "rb");
    if (checkFile != NULL) {
        // If the file exists, read data from the file
        readFromFile(students, numStudents, filename);
        fclose(checkFile);
    } else {
        // If the file doesn't exist, prompt the user to enter data
        for (int i = 0; i < numStudents; ++i) {
            printf("Enter details for student %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Age: ");
            scanf("%d", &students[i].age);
            printf("GPA: ");
            scanf("%f", &students[i].gpa);
        }

        // Save the entered data to the file
        saveToFile(students, numStudents, filename);
    }

    // Display the stored data
    printf("\nStudent details:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

// Structure to represent a student
struct Student {
    int rollNo;
    char name[50];
    int semester;
    char branch[20];
    char programme[20];
    float cgpa;
};

// Array to store student records
struct Student studentRecords[MAX_STUDENTS];
int numStudents = 0;  // Number of students currently in the array

// Function to maintain min-max heap property
void heapify(struct Student arr[], int n, int i, int isMaxLevel) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n &&
        ((isMaxLevel && arr[leftChild].cgpa > arr[largest].cgpa) ||
         (!isMaxLevel && arr[leftChild].cgpa < arr[largest].cgpa))) {
        largest = leftChild;
    }

    if (rightChild < n &&
        ((isMaxLevel && arr[rightChild].cgpa > arr[largest].cgpa) ||
         (!isMaxLevel && arr[rightChild].cgpa < arr[largest].cgpa))) {
        largest = rightChild;
    }

    if (largest != i) {
        // Swap elements
        struct Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, isMaxLevel);
    }
}

// Function to build a min-max heap
void buildMinMaxHeap(struct Student arr[], int n, int isMaxLevel) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, isMaxLevel);
    }
}

// Function to retrieve the top k percentile scorers
void getTopKPercentile(int k) {
    // Build a min-max heap based on CGPA in descending order
    buildMinMaxHeap(studentRecords, numStudents, 1);

    int numTop = (k * numStudents) / 100;
    printf("Top %d percentile scorers:\n", k);
    for (int i = 0; i < numTop; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}

// Function to retrieve the bottom k percentile scorers
void getBottomKPercentile(int k) {
    // Build a min-max heap based on CGPA in ascending order
    buildMinMaxHeap(studentRecords, numStudents, 0);

    int numBottom = (k * numStudents) / 100;
    printf("Bottom %d percentile scorers:\n", k);
    for (int i = 0; i < numBottom; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}

int main() {
    // Assuming studentRecords is populated with student data

    // Example: Retrieving top k percentile scorers
    int k = 10;  // Top 10 percentile scorers
    getTopKPercentile(k);

    // Example: Retrieving bottom k percentile scorers
    k = 10;  // Bottom 10 percentile scorers
    getBottomKPercentile(k);

    return 0;
}
