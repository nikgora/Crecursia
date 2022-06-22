#include <stdio.h>

int gcd(int a, int b);

int makkarti(int n);

int main() {
    printf("%d", makkarti(91));
    return 0;
}

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int makkarti(int n) {
    return n > 100 ? n - 10 : makkarti(makkarti(n + 11));
}
