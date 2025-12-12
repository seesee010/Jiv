/*
 * Copyright (C) 2025 seesee010
 * 
 * This program is licensed under GPL-2.0
 * See LICENSE file for details
 */


#include "core.h"
#include "write.h"

int writeGitIgnore(FILE *file) {
    if (file == NULL) {
        return -1;
    }

    // IntelliJ
    fprintf(file, "# IntelliJ IDEA #\n");
    fprintf(file, "out/\n");
    fprintf(file, "!**/src/main/**/out/\n");
    fprintf(file, "!**/src/test/**/out/\n");

    fprintf(file, "\n");

    // VSC
    fprintf(file, "# VSC #\n");
    fprintf(file, ".vscode/\n");

    fflush(file);

    return 0;
}

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

    fflush(file);
    return 0;
}