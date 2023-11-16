#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file
struct File {
    char name[50]; // File name (assuming a maximum of 50 characters)
    int size;      // File size
};

// Define a structure to represent a simple file system
struct FileSystemSimulator {
    int capacity;                 // Total capacity of the file system
    int free_space;              // Remaining free space in the file system
    struct File files[100];      // Array to store files (assuming a maximum of 100 files)
    int num_files;               // Number of files in the file system
};

// Function to add a file to the file system
void add_file(struct FileSystemSimulator* fs, struct File file) {
    if (file.size > fs->free_space) {
        printf("Not enough free space to add the file\n");
        return;
    }
    fs->files[fs->num_files] = file;
    fs->num_files++;
    fs->free_space -= file.size;
}

// Function to remove a file from the file system
void remove_file(struct FileSystemSimulator* fs) {
    if (fs->num_files == 0) {
        printf("No files to remove\n");
        return;
    }
    struct File removed_file = fs->files[0];
    for (int i = 0; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    fs->free_space += removed_file.size;
}

// Function to print the files in the file system
void print_files(struct FileSystemSimulator* fs) {
    if (fs->num_files == 0) {
        printf("No files in the file system\n");
    } else {
        printf("Files in the file system:\n");
        for (int i = 0; i < fs->num_files; i++) {
            printf("%s %d\n", fs->files[i].name, fs->files[i].size);
        }
    }
}

int main() {
    int capacity;
    printf("Enter the capacity of the file system: ");
    scanf("%d", &capacity);
    struct FileSystemSimulator file_system;
    file_system.capacity = capacity;
    file_system.free_space = capacity;
    file_system.num_files = 0;

    while (1) {
        printf("\nFile System Simulator Menu:\n");
        printf("1. Add a file\n");
        printf("2. Remove a file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            struct File new_file;
            printf("Enter the name of the file: ");
            scanf("%s", new_file.name);
            printf("Enter the size of the file: ");
            scanf("%d", &new_file.size);
            add_file(&file_system, new_file);
        } else if (choice == 2) {
            remove_file(&file_system);
        } else if (choice == 3) {
            print_files(&file_system);
        } else if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}