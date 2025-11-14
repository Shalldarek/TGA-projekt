#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_parser.h"

void print_error_and_exit(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    fprintf(stderr, "Usage: program --output <path> --width <width> --height <height>\n"); 
    exit(1);
}

ProgramArgs parse_args(int argc, char *argv[]) {
    ProgramArgs args = {0};

    args.output_set = false;
    args.width_set = false;
    args.height_set = false;

    for (int i = 1; i < argc; i++) {
        if (i + 1 >= argc) {
            print_error_and_exit("");
        }

        if (strcmp(argv[i], "--output") == 0) {
            if (args.output_set) print_error_and_exit("Argument needs a value");
            args.output_path = argv[++i];
            args.output_set = true;
            
        } else if (strcmp(argv[i], "--width") == 0) {
            if (args.width_set) print_error_and_exit("Parametr --width was already set");
            args.width = atoi(argv[++i]);
            
            if (args.width <= 0) {
                 print_error_and_exit("--width needs a positive integer");
            }
            args.width_set = true;
            
        } else if (strcmp(argv[i], "--height") == 0) {
            if (args.height_set) print_error_and_exit("Parametr --height was already set");
            args.height = atoi(argv[++i]);
            
            if (args.height <= 0) {
                 print_error_and_exit("--height needs a positive integer");
            }
            args.height_set = true;
            
        } else {
            print_error_and_exit("Unknown argument");
        }
    }

    if (!args.output_set || !args.width_set || !args.height_set) {
        print_error_and_exit("Missing required arguments");
    }

    return args;
}