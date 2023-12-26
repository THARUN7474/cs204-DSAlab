#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000

// Structure to represent a student
struct Student {
    int rollNo;
    char name[100];
    int semester;
    char branch[50];
    char programme[50];
    float cgpa;
};

// Array to store student records
struct Student studentRecords[MAX_STUDENTS];
int numStudents = 0;  // Number of students currently in the array

// Function to insert a student record
void insertStudent(struct Student newStudent) {
    if (numStudents < MAX_STUDENTS) {
        studentRecords[numStudents++] = newStudent;
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to search for a student by roll no
int searchByRollNo(int rollNo) {
    for (int i = 0; i < numStudents; ++i) {
        if (studentRecords[i].rollNo == rollNo) {
            return i;  // Return the index of the found student
        }
    }
    return -1;  // Return -1 if not found
}

// Function to search for a student by name
int searchByName(const char *name) {
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(studentRecords[i].name, name) == 0) {
            return i;  // Return the index of the found student
        }
    }
    return -1;  // Return -1 if not found
}

// Function to list students belonging to a specific branch
void listByBranch(const char *branch) {
    printf("Students in branch %s:\n", branch);
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(studentRecords[i].branch, branch) == 0) {
            printf("Roll No: %d, Name: %s, Semester: %d, Programme: %s, CGPA: %.2f\n",
                   studentRecords[i].rollNo, studentRecords[i].name,
                   studentRecords[i].semester, studentRecords[i].programme,
                   studentRecords[i].cgpa);
        }
    }
}

// Function to retrieve the top k percentile scorers
void getTopKPercentile(int k) {
    // Sort students by CGPA (descending order)
    qsort(studentRecords, numStudents, sizeof(struct Student),
          [](const void *a, const void *b) {
              return ((const struct Student *)b)->cgpa -
                     ((const struct Student *)a)->cgpa;
          });

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
    // Sort students by CGPA (ascending order)
    qsort(studentRecords, numStudents, sizeof(struct Student),
          [](const void *a, const void *b) {
              return ((const struct Student *)a)->cgpa -
                     ((const struct Student *)b)->cgpa;
          });

    int numBottom = (k * numStudents) / 100;
    printf("Bottom %d percentile scorers:\n", k);
    for (int i = 0; i < numBottom; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].cgpa);
    }
}

// Function to retrieve details by roll no in constant time
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

// Function to print rank list programme wise
void rankListProgrammeWise() {
    // Sort students by CGPA (descending order)
    qsort(studentRecords, numStudents, sizeof(struct Student),
          [](const void *a, const void *b) {
              return ((const struct Student *)b)->cgpa -
                     ((const struct Student *)a)->cgpa;
          });

    // Display rank list programme wise
    printf("Rank List Programme Wise:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("Rank %d: Roll No: %d, Name: %s, Programme: %s, CGPA: %.2f\n", i + 1,
               studentRecords[i].rollNo, studentRecords[i].name,
               studentRecords[i].programme, studentRecords[i].cgpa);
    }
}

// Function to save student data to a file
void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(studentRecords, sizeof(struct Student), numStudents, file);
    fclose(file);
}

// Function to read student data from a file
void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
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
    const char *filename = "student_records.dat";

    // Read student data from the file (if exists)
    readFromFile(filename);

    // Example: Inserting a student record
    struct Student newStudent;
    newStudent.rollNo = 101;
    strcpy(newStudent.name, "John Doe");
    newStudent.semester = 5;
    strcpy(newStudent.branch, "Computer Science");
    strcpy(newStudent.programme, "B.Tech");
    newStudent.cgpa = 8.5;
    insertStudent(newStudent);

    // Example: Searching for a student by roll no
    int rollToSearch = 101;
    int searchResult = searchByRollNo(rollToSearch);
    if (searchResult != -1) {
        printf("Student found with Roll No %d.\n", rollToSearch);
    } else {
        printf("Student not found with Roll No %d.\n", rollToSearch);
    }

    // Example: Searching for a student by name
    const char *nameToSearch = "John Doe";
    searchResult = searchByName(nameToSearch);
    if (searchResult != -1) {
        printf("Student found with name %s.\n", nameToSearch);
    } else {
        printf("Student not found with name %s.\n", nameToSearch);
    }

    // Example: Listing students belonging to a specific branch
    const char *branchToList = "Computer Science";
    listByBranch(branchToList);

    // Example: Retrieving top k percentile scorers
    int k = 10;  // Top 10 percentile scorers
    getTopKPercentile(k);

    // Example: Retrieving details by roll no in constant time
    int rollToRetrieve = 101;
    detailsByRollNo(rollToRetrieve);

    // Example: Printing rank list programme wise
    rankListProgrammeWise();

    // Save the student data to the file
    saveToFile(filename);

    return 0;
}
