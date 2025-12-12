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

#include <stdlib.h>

#include "write.h"
#include "create.h"

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
    FILE *file2 = NULL;

// create //
    if (createFile(&file, dir_src, "Main", "w", ".java") != 0) {
        printf("Error while creating filepath!\n");
        returnValue = 1;
        goto cleanup;
    }

    if (createFile(&file2, dir_parent, ".gitignore", "w", "") != 0) {
        printf("Error while creating filepath!\n");
        returnValue = 1;
        goto cleanup;
    }

// write //
    // open Main.java
    if (writeHelloWorld(file) != 0) {
        printf("Error while writing into File! (Main.java)\n");
        returnValue = 1;
        goto cleanup;
    }

    if (writeGitIgnore(file2) != 0) {
        printf("Error while writing into File! (GitIgnore)\n");
        returnValue = 1;
        goto cleanup;
    }

    cleanup:
        if (file != NULL) {
            fclose(file);
        }
        if (file2 != NULL) {
            fclose(file2);
        }
    
        free(dir_src);
        return returnValue;
}