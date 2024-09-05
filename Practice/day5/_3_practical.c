#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Function prototypes
void my_cp(const char *source, const char *destination);
void my_grep(const char *pattern, const char *filename);
void my_ls();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "cp") == 0) {
        if (argc != 4) {
            printf("Usage: %s cp <source> <destination>\n", argv[0]);
            return 1;
        }
        my_cp(argv[2], argv[3]);
    } else if (strcmp(argv[1], "grep") == 0) {
        if (argc != 4) {
            printf("Usage: %s grep <pattern> <filename>\n", argv[0]);
            return 1;
        }
        my_grep(argv[2], argv[3]);
    } else if (strcmp(argv[1], "ls") == 0) {
        my_ls();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}

void my_cp(const char *source, const char *destination) {
    if (CopyFile(source, destination, FALSE)) {
        printf("File copied successfully.\n");
    } else {
        perror("Error copying file");
    }
}

void my_grep(const char *pattern, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[512];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        lineNumber++;
        if (strstr(line, pattern) != NULL) {
            printf("%s:%d: %s", filename, lineNumber, line);
        }
    }

    fclose(file);
}

void my_ls() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        perror("Error listing files");
        return;
    }

    do {
        printf("%s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}
