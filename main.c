#include <stdio.h>

void showMenu() {
    printf("\n=== File Format Conversion System ===\n");
    printf("1. Convert File Format\n");
    printf("2. View Logs\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}
int main() {
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // call convert function
                break;
            case 2:
                // call viewLogs function
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
void createFile(char *filename);
void deleteFile(char *filename);
void readFile(char *filename);
void writeFile(char *filename);
void modifyFile(char *filename);
void searchInFile(char *filename, char *word);
void listFilesInDirectory();
for (int i = 0; i <= 100; i += 10) {
    printf("\rConverting... %d%%", i);
    fflush(stdout);
    sleep(1); // Unix - for Windows use Sleep()
}
printf("\nConversion Complete!\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep()

#define MAX 256

void showMenu();
void convertFile();
void viewLogs();
void writeLog(const char *message);

// File operations
void createFile(const char *filename);
void deleteFile(const char *filename);
void readFile(const char *filename);
void writeFile(const char *filename);
void modifyFile(const char *filename);
void searchInFile(const char *filename, const char *word);

int main() {
    int choice;
    char filename[MAX], word[MAX];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                convertFile();
                break;
            case 2:
                viewLogs();
                break;
            case 3:
                printf("Exiting...\n");
                writeLog("Program exited.");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

void showMenu() {
    printf("\n==== File Format Conversion System ====\n");
    printf("1. Convert File Format (TXT to CSV)\n");
    printf("2. View Logs\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void convertFile() {
    char inputFile[MAX], outputFile[MAX];
    char buffer[MAX];
    FILE *in, *out;

    printf("Enter input TXT file: ");
    fgets(inputFile, MAX, stdin);
    inputFile[strcspn(inputFile, "\n")] = 0;

    printf("Enter output CSV file: ");
    fgets(outputFile, MAX, stdin);
    outputFile[strcspn(outputFile, "\n")] = 0;

    in = fopen(inputFile, "r");
    out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File error. Check paths.\n");
        writeLog("File error during conversion.");
        return;
    }

    printf("Converting...\n");
    int progress = 0;

    while (fgets(buffer, MAX, in)) {
        // Simple conversion: replace spaces with commas
        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] == ' ') buffer[i] = ',';
        }
        fprintf(out, "%s", buffer);
        progress += 10;
        printf("\rProgress: %d%%", progress > 100 ? 100 : progress);
        fflush(stdout);
        sleep(1);
    }

    fclose(in);
    fclose(out);
    printf("\nConversion complete!\n");

    writeLog("File converted successfully.");
}

void viewLogs() {
    FILE *log = fopen("logs.txt", "r");
    char line[MAX];
    if (!log) {
        printf("No logs found.\n");
        return;
    }
    printf("\n==== Logs ====\n");
    while (fgets(line, sizeof(line), log)) {
        printf("%s", line);
    }
    fclose(log);
}

void writeLog(const char *message) {
    FILE *log = fopen("logs.txt", "a");
    if (log) {
        fprintf(log, "%s\n", message);
        fclose(log);
    }
}
case 4:
printf("Enter filename to create: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
createFile(filename);
break;
case 5:
printf("Enter filename to delete: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
deleteFile(filename);
break;
case 6:
printf("Enter filename to read: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
readFile(filename);
break;
case 7:
printf("Enter filename to write to: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
writeFile(filename);
break;
case 8:
printf("Enter filename to append to: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
modifyFile(filename);
break;
case 9:
printf("Enter filename to search in: ");
fgets(filename, MAX, stdin);
filename[strcspn(filename, "\n")] = 0;
printf("Enter word to search: ");
fgets(word, MAX, stdin);
word[strcspn(word, "\n")] = 0;
searchInFile(filename, word);
break;

void showMenu() {
    printf("\n==== File Format Conversion System ====\n");
    printf("1. Convert File Format (TXT to CSV)\n");
    printf("2. View Logs\n");
    printf("3. Exit\n");
    printf("4. Create File\n");
    printf("5. Delete File\n");
    printf("6. Read File\n");
    printf("7. Write to File\n");
    printf("8. Modify (Append to) File\n");
    printf("9. Search in File\n");
    printf("Enter your choice: ");
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        printf("File '%s' created.\n", filename);
        writeLog("File created.");
        fclose(file);
    } else {
        printf("Failed to create file.\n");
    }
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted.\n", filename);
        writeLog("File deleted.");
    } else {
        printf("Could not delete file.\n");
    }
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX];
    if (!file) {
        printf("Cannot open file.\n");
        return;
    }
    printf("\n-- Content of %s --\n", filename);
    while (fgets(line, MAX, file)) {
        printf("%s", line);
    }
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    char content[MAX];
    if (!file) {
        printf("Cannot open file.\n");
        return;
    }
    printf("Enter content (end with '#'): ");
    while (fgets(content, MAX, stdin)) {
        if (content[0] == '#') break;
        fputs(content, file);
    }
    fclose(file);
    printf("Content written.\n");
    writeLog("Data written to file.");
}

void modifyFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    char content[MAX];
    if (!file) {
        printf("Cannot open file.\n");
        return;
    }
    printf("Enter content to append (end with '#'): ");
    while (fgets(content, MAX, stdin)) {
        if (content[0] == '#') break;
        fputs(content, file);
    }
    fclose(file);
    printf("Content appended.\n");
    writeLog("Data appended to file.");
}

void searchInFile(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    char line[MAX];
    int found = 0, lineNumber = 1;

    if (!file) {
        printf("Cannot open file.\n");
        return;
    }

    while (fgets(line, MAX, file)) {
        if (strstr(line, word)) {
            printf("Line %d: %s", lineNumber, line);
            found = 1;
        }
        lineNumber++;
    }

    fclose(file);
    if (!found) {
        printf("'%s' not found in the file.\n", word);
    } else {
        writeLog("Search term found in file.");
    }
}
