#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
    while (a != 0 and b != 0) {
        if(a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a > b ? a : b;
}

void test_solution(int a, int b) {
    int gcd_naive_answ, gcd_fast_answ;
    for (int i=1; i<a; ++i)
        for (int j=1; j<b; ++j) {
            std::cout << i << " " << j << std::endl;
            gcd_naive_answ = gcd_naive(a, b);
            gcd_fast_answ = gcd_fast(a, b);
            if(gcd_naive_answ == gcd_fast_answ)
                std::cout << "OK\n";
            else {
                std::cout << gcd_naive_answ << " != " << gcd_fast_answ << "\n";
                return;
            }
        }
    return;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << gcd_naive(a, b) << std::endl;
    std::cout << gcd_fast(a, b) << std::endl;
    //test_solution(a, b);
    return 0;
}
