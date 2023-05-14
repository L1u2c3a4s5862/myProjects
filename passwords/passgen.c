#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include <unistd.h>

// Default values for password generation
#define DEFAULT_LENGTH 12
#define DEFAULT_COUNT 5
#define DEFAULT_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+{}[]|\\:;\"'<>,.?/ "

// Function to generate a random password of a given length and character set
char* generate_password(int length, const char* chars) {
    char* password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(chars);
        password[i] = chars[index];
    }
    password[length] = '\0';
    return password;
}

int main(int argc, char* argv[]) {
    int length = DEFAULT_LENGTH;
    int count = DEFAULT_COUNT;
    const char* chars = DEFAULT_CHARS;
    int opt;

    // Command line options parsing
    while ((opt = getopt(argc, argv, "hl:n:c:")) != -1) {
        switch (opt) {
            case 'h':
                printf(" ██▓███   ▄▄▄        ██████   ██████   ▄████ ▓█████  ███▄    █ \n"
                       "▓██░  ██▒▒████▄    ▒██    ▒ ▒██    ▒  ██▒ ▀█▒▓█   ▀  ██ ▀█   █ \n"
                       "▓██░ ██▓▒▒██  ▀█▄  ░ ▓██▄   ░ ▓██▄   ▒██░▄▄▄░▒███   ▓██  ▀█ ██▒\n"
                       "▒██▄█▓▒ ▒░██▄▄▄▄██   ▒   ██▒  ▒   ██▒░▓█  ██▓▒▓█  ▄ ▓██▒  ▐▌██▒\n"
                       "▒██▒ ░  ░ ▓█   ▓██▒▒██████▒▒▒██████▒▒░▒▓███▀▒░▒████▒▒██░   ▓██░\n"
                       "▒▓▒░ ░  ░ ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░ ░▒   ▒ ░░ ▒░ ░░ ▒░   ▒ ▒ \n"
                       "\033[1;35m                     -=Author: Lucas Liu=-                     \033[1;0m\n\n");
                printf("Usage: %s [-h] [-l LENGTH] [-n NUMBER] [-c CHARS]\n", argv[0]);
                printf("\nOptions:\n");
                printf("  -h               Show this help message and exit\n");
                printf("  -l LENGTH        Length of each password (default: \033[1;34m%d\033[1;0m)\n", DEFAULT_LENGTH);
                printf("  -n NUMBER        Number of passwords to generate (default: \033[1;34m%d\033[1;0m)\n", DEFAULT_COUNT);
                printf("  -c CHARS         Characters to use for password generation\n");
                printf("                   (default: \033[1;34m\"%s\"\033[1;0m)\n", DEFAULT_CHARS);
                return 0;
            case 'l':
                length = atoi(optarg);
                break;
            case 'n':
                count = atoi(optarg);
                break;
            case 'c':
                chars = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-h] [-l LENGTH] [-n NUMBER] [-c CHARS]\n", argv[0]);
                return 1;
        }
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate the passwords
    for (int i = 0; i < count; i++) {
        char* password = generate_password(length, chars);
        printf("%s\n", password);
        usleep(50000);
        free(password);
    }

    return 0;
}
