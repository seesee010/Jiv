/*
 * Copyright (C) 2025 seesee010
 * 
 * This program is licensed under GPL-2.0
 * See LICENSE file for details
 */

//mkdir

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) mkdir(path)
#else // linux etc
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdio.h>
#include <stdlib.h>

#define maxPathLen 256

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

    char *path = malloc(maxPathLen);

    if (path == NULL) {
        goto err_free;
    }

    // path = ...
    snprintf(path, maxPathLen, "%s/%s.java", pathToFile, fileName);

    *file = fopen(path, operation);

    if (*file == NULL) {
        free(path);
        goto err_free;
    }

    // cleanup
    free(path);
    return 0;

    err_free:
        return 1;
}

int main(int argc, char **argv) {
    
    int returnValue = 0;
    char *dir_parent;

    if (argc < 2) {
        dir_parent = "Test";
    } else {
        dir_parent = argv[1];
    }

    MKDIR(dir_parent);

    char *dir_src = calloc(maxPathLen, sizeof(char));

    if (dir_src == NULL) {
        return -1;
    }

    // dir_src = dir_parent + src dir
    snprintf(dir_src, maxPathLen, "%s/src", dir_parent);

    FILE *file = NULL;

    if (createFile(&file, dir_src, "Main", "w") != 0) {
        printf("Error while creating filepath!\n");
        returnValue = 1;
        goto err_free;
    }

    // open Main.java
    if (writeHelloWorld(file) != 0) {
        printf("Error while writing into File!\n");
        returnValue = 1;
        goto err_file;
    }

    // cleanup
    err_file:
        if (file != NULL) {
            fclose(file);
        }
    
    err_free:
        free(dir_src);
        return returnValue;
}
