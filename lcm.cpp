#include <iostream>

int gcd(int a, int b) {
    while(a != 0 and b != 0) {
        if(a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a > b ? a : b;
}

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;
    return (long long) a * b;
}

long long lcm_fast(int a, int b) {
    int gcdiv = gcd(a, b);
    return (long long) a * b / gcdiv;
}

void test_solution(int a, int b) {
    int lcm_naive_answ, lcm_fast_answ;
    for (int i=1; i<a; ++i)
        for (int j=1; j<b; ++j) {
            std::cout << i << " " << j << std::endl;
            lcm_naive_answ = lcm_naive(a, b);
            lcm_fast_answ = lcm_fast(a, b);
            if(lcm_naive_answ == lcm_fast_answ)
                std::cout << "OK\n";
            else {
                std::cout << lcm_naive_answ << " != " << lcm_fast_answ << "\n";
                return;
            }
        }
    return;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm_fast(a, b) << std::endl;
    //test_solution(a, b);
    return 0;
}
