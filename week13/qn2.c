#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000

struct Student {
    int rollNo;
    char name[100];
    int semester;
    char branch[50];
    char programme[50];
    float cgpa;
};

struct Student studentRecords[MAX_STUDENTS];
int numStudents = 0; //no of students in array 


void insertStudent(struct Student newStudent) {
    // printf("\n%d\n",numStudents);
    if (numStudents < MAX_STUDENTS) {
        studentRecords[numStudents++] = newStudent;
        // printf("\n%d\n",numStudents);
    } else {
        printf("Maximum number of students reached.\n");
    }
}

int searchByRollNo(int rollNo) {
    for (int i = 0; i < numStudents; ++i) {
        if (studentRecords[i].rollNo == rollNo) {
            return i;  
        }
    }
    return -1;  
}

int searchByName(char *name) {
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(studentRecords[i].name, name) == 0) {
            return i;  
        }
    }
    return -1; 
}

void listByBranch(char *branch) {
    printf("Students in branch %s:\n", branch);
    // printf("\n%d\n",numStudents);
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(studentRecords[i].branch, branch) == 0) {
            printf("Roll No: %d, Name: %s, Semester: %d, Programme: %s, CGPA: %.2f\n",
                   studentRecords[i].rollNo, studentRecords[i].name,
                   studentRecords[i].semester, studentRecords[i].programme,
                   studentRecords[i].cgpa);
        }
    }
}
void heapify(struct Student arr[], int n, int i, int isMaxLevel) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n &&
        ((isMaxLevel && arr[leftChild].cgpa > arr[largest].cgpa) ||(!isMaxLevel && arr[leftChild].cgpa < arr[largest].cgpa))) {
        largest = leftChild;
    }

    if (rightChild < n &&
        ((isMaxLevel && arr[rightChild].cgpa > arr[largest].cgpa) ||(!isMaxLevel && arr[rightChild].cgpa < arr[largest].cgpa))) {
        largest = rightChild;
    }

    if (largest != i) {
       
        struct Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest, isMaxLevel);
    }
}

void buildMinMaxHeap(struct Student arr[], int n, int isMaxLevel) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, isMaxLevel);
    }
}


void getTopKPercentile(int k) {
    // Build a min-max heap based on CGPA in descending order--max heap
    // printf("\n%d\n",numStudents);
    buildMinMaxHeap(studentRecords, numStudents, 1);
    // printf("\n%d\n",numStudents);
    int numTop = (k * numStudents) / 100;
    // printf("%d\n",numTop);
    printf("Top %d percentile scorers:\n", k);
    for (int i = 0; i <=numTop; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}

void getBottomKPercentile(int k) {
    // Build a min-max heap based on CGPA in ascending order--min heap
    buildMinMaxHeap(studentRecords, numStudents, 0);
    int numBottom = (k * numStudents) / 100;
    // printf("%d\n",numBottom);
    printf("Bottom %d percentile scorers:\n", k);
    for (int i = 0; i <= numBottom; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}
void detailsByRollNo(int rollNo) {
    int index = searchByRollNo(rollNo);
    if (index != -1) {
        printf("Name: %s, Branch: %s, Programme: %s, CGPA: %.2f\n",
               studentRecords[index].name, studentRecords[index].branch,
               studentRecords[index].programme, studentRecords[index].cgpa);
    } else {
        printf("Student not found with Roll No: %d\n", rollNo);
    }
}
void rankprogramme(int k) {
    // Build a min-max heap based on CGPA in descending order--max heap
    buildMinMaxHeap(studentRecords, numStudents, 1);
    int numTop = (k * numStudents) / 100;
    printf("rank wise programme list\n");
    for (int i = 0; i < numTop; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}
// Function to save student data to a file
void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(studentRecords, sizeof(struct Student), numStudents, file);
    fclose(file);

}

// Function to read student data from a file
void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // File doesn't exist, start with an empty set
        return;
    }
    fread(studentRecords, sizeof(struct Student), MAX_STUDENTS, file);
    fclose(file);

    // Update the number of students based on the read data
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (studentRecords[i].rollNo == 0) {
            break;
        }
        numStudents++;
    }
}
int main() {
    const char *filename = "student_records.txt";

    // Read student data from the file (if exists)
    readFromFile(filename);
    // Example: Inserting a student record
    int numStudents1;
    printf("no of students data you want save to file: ");
    scanf("%d",&numStudents1);
    for (int i = 0; i < numStudents1; ++i) {
        struct Student newStudent;
        printf("Enter details for student %d:\n", i + 1);
        printf("roll no: ");
        scanf("%d",&newStudent.rollNo);
        printf("Name: ");
        scanf("%s", newStudent.name);
        printf("semester: ");
        scanf("%d",&newStudent.semester);
        printf("branch: ");
        scanf("%s", newStudent.branch);
        printf("programme: ");
        scanf("%s", newStudent.programme);
        printf("GPA: ");
        scanf("%f",&newStudent.cgpa);
        insertStudent(newStudent);
    }
    // struct Student newStudent;
    // newStudent.rollNo = 422116;
    // strcpy(newStudent.name, "Tharun");
    // newStudent.semester = 3;
    // strcpy(newStudent.branch, "CSE");
    // strcpy(newStudent.programme, "B.Tech");
    // newStudent.cgpa = 9.2;
    // insertStudent(newStudent);

    int rollToSearch = 422116;
    int searchResult = searchByRollNo(rollToSearch);
    if (searchResult != -1) {
        printf("Student found with Roll No %d.\n", rollToSearch);
    } else {
        printf("Student not found with Roll No %d.\n", rollToSearch);
    }
    
    char *nameToSearch = "Tharun";
    searchResult = searchByName(nameToSearch);
    if (searchResult != -1) {
        printf("Student found with name %s.\n", nameToSearch);
    } else {
        printf("Student not found with name %s.\n", nameToSearch);
    }

    char *branchToList = "CSE";
    listByBranch(branchToList);
    char *branchToList1 = "CSEe";
    listByBranch(branchToList1);

    int k = 60;  // Top 10 percentile scorers
    getTopKPercentile(k);
    // printf("\nhi\n");
    getBottomKPercentile(k);

    int rollToRetrieve = 422116;
    detailsByRollNo(rollToRetrieve);
    rankprogramme(k);

    // rankListProgrammeWise();

    // Save the student data to the file
    saveToFile(filename);

    return 0;
}
