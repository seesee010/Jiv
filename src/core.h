/*
 * Copyright (C) 2025 seesee010
 * 
 * This program is licensed under GPL-2.0
 * See LICENSE file for details
 */

#pragma once

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) mkdir(path)
#else // linux etc
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif

#include <stdlib.h>