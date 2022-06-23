#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 100

int gcd(int a, int b);

int makkarti(int n);

void reversePrint(char string[N], int index);

int countLetter(char string[N], char letters[N], int res, int index);

void print(char string[N], int index);

void enterKoef(float *koef, int n);

void poshitat(float a, float b, float *koef, int n, float step);

int main() {

    //int a, b, c, d;
    //scanf("%d%d%d%d", &a, &b, &c, &d);
    //printf("gcd(a, b) = %d\ngcd(a, c) = %d\ngcd(a, d) = %d\n", gcd(a, b), gcd(a, c), gcd(a, d));
    //int n;
    //scanf("%d", &n);
    //printf("%d", makkarti(n));
    //char string[N] = "Aspd";
    //char letters[N] = "Asansp";
    //print(string, 0);
    //reversePrint(string,0);
    //printf("%d", countLetter(string, letters, 0, 0));
    /*
    float a, b;
    puts("Enter a, b");
    scanf("%f%f", &a, &b);
    puts("Enter power of function");
    int n;
    scanf("%d", &n);
    n++;
    float *koef = calloc(n, sizeof(float));
    puts("Enter koeficent");
    enterKoef(koef, n);
    float step;
    puts("Enter step");
    scanf("%f", &step);
    poshitat(a, b, koef, n, step);*/
    return 0;
}

void poshitat(float a, float b, float *koef, int n, float step) {
    float res = 0;
    for (int i = 0; i < n && a - b < step; ++i) {
        res += koef[i] * pow(a, n - i - 1);
    }

    if (a - b < step) {
        printf("in %f you function is %f\n", a, res);
        poshitat(a + step, b, koef, n, step);
    }
}

void enterKoef(float *koef, int n) {
    for (int i = 0; i < n; ++i) {
        float temp;
        scanf("%f", &temp);
        koef[i] = temp;
    }
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