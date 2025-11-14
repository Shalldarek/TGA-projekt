#include <stdio.h>
#include <stdlib.h>
#include "cmd_parser.h"

int main(int argc, char *argv[]) {
    ProgramArgs args = parse_args(argc, argv); // Parsing command line arguments for further usage

    printf("Output Path: %s\n", args.output_path);
    printf("Width: %d\n", args.width);
    printf("Height: %d\n", args.height);

    return 0;
}