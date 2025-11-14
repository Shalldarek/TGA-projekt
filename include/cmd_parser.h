#include <stdbool.h>

#ifndef CMD_PARSER_H
#define CMD_PARSER_H

typedef struct {
    char* output_path;
    int width;
    int height;
    bool output_set; 
    bool width_set;
    bool height_set;
} ProgramArgs;

ProgramArgs parse_args(int argc, char *argv[]);
#endif 