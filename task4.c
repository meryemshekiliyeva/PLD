#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#define _SIZE 1024
int main() {
    char buffer[_SIZE];
    ssize_t bytes_;
    int word_count = 0;
    int in_word = 0;
    while ((bytes_ = read(0, buffer, _SIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_; i++) {
            char c = buffer[i];
            if (!isspace(c)) {
                if (!in_word) {
                    word_count++;
                    in_word = 1;
                }
            } else {
                in_word = 0;
            }
        }
    }
        if (bytes_ == -1) {
        perror("Error reading input");
        return 1;
    }
    printf("Number of words: %d\n", word_count);
    return 0;
}
