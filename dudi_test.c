#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000

void interpret(char *code) {
    char memory[MEMORY_SIZE] = {0};
    char *ptr = memory;

    while (*code) {
        switch (*code) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        ++code;
                        if (*code == '[') {
                            ++loop;
                        } else if (*code == ']') {
                            --loop;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int loop = 1;
                    while (loop > 0) {
                        --code;
                        if (*code == '[') {
                            --loop;
                        } else if (*code == ']') {
                            ++loop;
                        }
                    }
                }
                break;
            default:               
                break;
        }
        ++code;
    }
}

int main() {
    char code[] = "-[--->+<]>-------.[--->++++<]>+.------.++.--[--->+<]>-.---[->++++<]>.-----.[--->+<]>-----.---[->++++<]>.------------.-------.+++++++++++++.---.-[++>---<]>+.--[->++++<]>+.----------.++++++.";
    interpret(code);

    return 0;
}
