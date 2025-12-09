/*
 * Copyright (C) 2024 Sebastian
 * 
 * This program is licensed under GPL-2.0
 * See LICENSE file for details
 */

#include <stdio.h>

//mkdir

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdlib.h>

int writeHelloWorld(FILE *file) {
    if (file == NULL) {
        return -1;
    }

    fprintf(file, "/*\n");
    fprintf(file, "\t\n");
    fprintf(file, "*/\n");
    fprintf(file, "public class Main {\n");
    fprintf(file, "\tpublic static void main(String[] args) {\n");
    fprintf(file, "\t\t\n");

    fprintf(file, "\t}\n");
    fprintf(file, "}\n");

    return 0;
}

int createFile(FILE **file, char *pathToFile, char *fileName, char *operation) {
    if (pathToFile != NULL) {
        MKDIR(pathToFile);
    }

    char *path = malloc(256);
    // path = ...
    snprintf(path, 256, "%s/%s.java", pathToFile, fileName);

    if (path == NULL) {
        return -1;
    }

    *file = fopen(path, operation);

    if (*file == NULL) {
        return -1;
    }

    // exit

    free(path);
    return 0;
}

int main(int argc, char **argv) {
    
    char *dir_parent;

    if (argc < 2) {
        dir_parent = "Test";
    } else {
        dir_parent = argv[1];
    }

    printf("%d", argc);
    printf("%d", *(argv));

    MKDIR(dir_parent);

    char *dir_src = calloc(256, sizeof(char));

    // dir_src = dir_parent + src dir
    snprintf(dir_src, 256, "%s%s", dir_parent, "/src");

    FILE *file = NULL;

    if (createFile(&file, dir_src, "Main", "w") != 0) {
        printf("Error while creating filepath!");
        return 1;
    }

    // open Main.java
    if (writeHelloWorld(file) != 0) {
        printf("Error while writing into File!");
        return 1;
    }

    fclose(file);
    return 0;
}