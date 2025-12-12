/*
 * Copyright (C) 2025 seesee010
 * 
 * This program is licensed under GPL-2.0
 * See LICENSE file for details
 */


 #ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) mkdir(path)
#else // linux etc
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdlib.h>

#include "create.h"

int createFile(FILE **file, char *pathToFile, char *fileName, char *operation, char *language) {
    if (pathToFile != NULL) {
        MKDIR(pathToFile);
    }

    if (language == NULL) {
        language = ".java";
    }

    char *path = malloc(maxPathLen);

    if (path == NULL) {
        goto err_free;
    }

    // path = ...
    snprintf(path, maxPathLen, "%s/%s%s", pathToFile, fileName, language);

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