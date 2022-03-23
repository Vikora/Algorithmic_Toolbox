#pragma once

#include <stdexcept>

int BinPower(int a, int64_t b, int c) {
    // a^b (mod c)
    int result = 1;

    int64_t big_a = a % c;
    while (b > 0) {
        if (b & 1) {
            result = (result * big_a) % c;
        }
        big_a = (big_a * big_a) % c;
        b >>= 1;
    }

    return result % c;
}

