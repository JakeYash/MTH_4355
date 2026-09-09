#include <stdio.h>
#include <stdlib.h>
#include <string.h> //needed for strstr
#include <unistd.h> //getopt and getoptlong
#include <getopt.h> //extern variables and others

int main(int argc, char *argv[]){
    int c;
    int digit_optind = 0;

    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"add",     required_argument, 0,  0 },
            {"append",  no_argument,       0,  0 },
            {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 },
            {"create",  required_argument, 0, 'c'},
            {"file",    required_argument, 0,  0 },
            {0,         0,                 0,  0 }
        };

        c = getopt_long(argc, argv, "abc:d:012",
                        long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 0:
            printf("option %s", long_options[option_index].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;

        case '0':
        case '1':
        case '2':
            if (digit_optind != 0 && digit_optind != this_option_optind)
                printf("digits occur in two different argv-elements.\n");
            digit_optind = this_option_optind;
            printf("option %c\n", c);
            break;

        case 'a':
            printf("option a\n");
            break;

        case 'b':
            printf("option b\n");
            break;

        case 'c':
            printf("option c with value '%s'\n", optarg);
            break;

        case 'd':
            printf("option d with value '%s'\n", optarg);
            break;

        case '?':
            break;

        default:
            printf("?? getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    exit(EXIT_SUCCESS);
    return 0;
}

//Goal 1: Introduce getline to read from a file/stream
    // Check out man page and read!
    // FILE *stream;
    // char *line = NULL;
    // size_t size = 0;
    // ssize_t nread;

    // stream = fopen(argv[1], "r");
    // if (stream == NULL) {
    //     perror("fopen");
    //     exit(EXIT_FAILURE);
    // }

    // while ((nread = getline(&line, &size, stream)) != -1) {
    //     printf("Retrieved line of length %zd:\n", nread);
    //     fwrite(line, nread, 1, stdout);
    // }

    // free(line);
    // fclose(stream);


//Goal 2: Introduce strstr to search for a substring.
    // Check out man page and read! 

    // char *haystack = "Hello World";
    // char *needle = "ZZZZ";
    // char *r;

    // r = strstr(haystack, needle);
    // if (r == NULL){
    //     printf("Substring not found:(");
    // } else{
    //     printf("haystack: %s\n", haystack);
    //     printf("needle: %s\n", needle);
    //     printf("return: %s\n", r);
    // }


    // return 0;

// Goal 3 (Most likely tuesday): Introduce getopt and getoptlong 
    // Check out man page and read! 
    // int flags, opt;
    // int nsecs, tfnd;

    // nsecs = 0; // argument for -t
    // tfnd = 0;  // flag for finding t
    // flags = 0; // flag for finding n
    // while ((opt = getopt(argc, argv, "nt:")) != -1) {
    //     switch (opt) {
    //     case 'n':
    //         flags = 1;
    //         break;
    //     case 't':
    //         nsecs = atoi(optarg);
    //         tfnd = 1;
    //         break;
    //     default: /* '?' */
    //         fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
    //                 argv[0]);
    //         exit(EXIT_FAILURE);
    //     }
    // }

    // printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
    //         flags, tfnd, nsecs, optind);

    // if (optind >= argc) {
    //     fprintf(stderr, "Expected argument after options\n");
    //     exit(EXIT_FAILURE);
    // }

    // printf("name argument = %s\n", argv[optind]);

    // /* Other code omitted */

    // exit(EXIT_SUCCESS);



    // int c;
    // int digit_optind = 0;

    // while (1) {
    //     int this_option_optind = optind ? optind : 1;
    //     int option_index = 0;
    //     static struct option long_options[] = {
    //         {"add",     required_argument, 0,  0 },
    //         {"append",  no_argument,       0,  0 },
    //         {"delete",  required_argument, 0,  0 },
    //         {"verbose", no_argument,       0,  0 },
    //         {"create",  required_argument, 0, 'c'},
    //         {"file",    required_argument, 0,  0 },
    //         {0,         0,                 0,  0 }
    //     };

    //     c = getopt_long(argc, argv, "abc:d:012",
    //                     long_options, &option_index);
    //     if (c == -1)
    //         break;

    //     switch (c) {
    //     case 0:
    //         printf("option %s", long_options[option_index].name);
    //         if (optarg)
    //             printf(" with arg %s", optarg);
    //         printf("\n");
    //         break;

    //     case '0':
    //     case '1':
    //     case '2':
    //         if (digit_optind != 0 && digit_optind != this_option_optind)
    //             printf("digits occur in two different argv-elements.\n");
    //         digit_optind = this_option_optind;
    //         printf("option %c\n", c);
    //         break;

    //     case 'a':
    //         printf("option a\n");
    //         break;

    //     case 'b':
    //         printf("option b\n");
    //         break;

    //     case 'c':
    //         printf("option c with value '%s'\n", optarg);
    //         break;

    //     case 'd':
    //         printf("option d with value '%s'\n", optarg);
    //         break;

    //     case '?':
    //         break;

    //     default:
    //         printf("?? getopt returned character code 0%o ??\n", c);
    //     }
    // }

    // if (optind < argc) {
    //     printf("non-option ARGV-elements: ");
    //     while (optind < argc)
    //         printf("%s ", argv[optind++]);
    //     printf("\n");
    // }

    // exit(EXIT_SUCCESS);