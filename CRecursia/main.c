#include <stdio.h>
#include <string.h>

#define N 100

int gcd(int a, int b);

int makkarti(int n);

void reversePrint(char string[N], int index);

int countLetter(char string[N], char letters[N], int res, int index);

void print(char string[N], int index);

int main() {
    char string[N] = "Asp";
    char letters[N] = "Asp";
    int a, b, c, d;
    //scanf("%d%d%d%d", &a, &b, &c, &d);
    //printf("gcd(a, b) = %d\ngcd(a, c) = %d\ngcd(a, d) = %d\n", gcd(a, b), gcd(a, c), gcd(a, d));
    //printf("%d", makkarti(91));
    //print(string, 0);
    //reversePrint(string,0);
    printf("%d", countLetter(string, letters, 0, 0));
    return 0;
}

int countLetter(char string[N], char letters[N], int res, int index) {
    for (int i = 0; i < strlen(letters) && index < strlen(string); ++i) {
        if (letters[i] == string[index])res++;
    }
    return index < strlen(string) ? countLetter(string, letters, res, index + 1) : res;
}

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int makkarti(int n) {
    return n > 100 ? n - 10 : makkarti(makkarti(n + 11));
}

void reversePrint(char string[N], int index) {
    if (index < strlen(string)) reversePrint(string, index + 1);
    printf("%c", string[index - 1]);
}

void print(char string[N], int index) {
    printf("%c", string[index]);
    if (index < strlen(string)) print(string, index + 1);
}