#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void printHelp() {
    cout << "Password Generator Help:\n"
         << "Usage: passwordgen [options]\n"
         << "Options:\n"
         << "  -l <length>  Specify password length\n"
         << "  -n <number>  Specify number of passwords to generate\n"
         << "  -c <chars>   Specify characters to include in passwords\n"
         << "  -h           Display this help message\n";
}

void generatePasswords(int length, int number, const char* chars) {
    const int MAX_PASSWORDS = 1000;
    char passwords[MAX_PASSWORDS][length+1];
    srand(time(nullptr)); // seed random number generator

    // generate passwords
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < length; j++) {
            passwords[i][j] = chars[rand() % strlen(chars)];
        }
        passwords[i][length] = '\0';
    }

    // print passwords
    for (int i = 0; i < number; i++) {
        cout << passwords[i] << endl;
    }
}

int main(int argc, char* argv[]) {
    int length = 8;
    int number = 1;
    const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\!@#$%^&*()-_=+{}[]|\\:;\\\"'<>,.?/ ";

    // parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            length = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-n") == 0) {
            number = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-c") == 0) {
            chars = argv[++i];
        } else if (strcmp(argv[i], "-h") == 0) {
            printHelp();
            return 0;
        } else {
            cerr << "Error: Invalid argument '" << argv[i] << "'" << endl;
            return 1;
        }
    } if (length <= 0) {
        cerr << "Error: Password length must be greater than 0" << endl;
        return 1;
    } if (number <= 0 || number > 1000) {
        cerr << "Error: Number of passwords must be between 1 and 1000" << endl;
        return 1;
    } if (strlen(chars) == 0) {
        cerr << "Error: Character set cannot be empty" << endl;
        return 1;
    }

    generatePasswords(length, number, chars);
    return 0;
}
