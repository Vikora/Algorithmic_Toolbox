#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int key) {
    int left = 0, right = (int)a.size() - 1, midpoint;
    
    while(left <= right) {
        midpoint = (right + left) / 2;
        if(a[midpoint] == key)
            return midpoint;
        if(a[midpoint] > key)
            right = midpoint - 1;
        else
            left = midpoint + 1;
    }
    return -1; 
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

void test_solution(int max_length, int max_value) {
    int lin_s, bin_s, i, n, m;
    while(true) {
        n = rand() % max_length + 2;
        m = rand() % max_length + 2;
        std::vector<int> a, k;

        for(i=0; i<n; ++i) {
            a.push_back(max_value - n + i);
        }

        for(i=0; i<m; ++i) {
            k.push_back(max_value - m + i);
        }

        for (i = 0; i < m; ++i) {
            std::cout << n << ' ' << m << '\n';
            lin_s = linear_search(a, k[i]); 
            bin_s = binary_search(a, k[i]);
            if(lin_s != bin_s) {
                printf("[%d]. Your answer: %d, right answer: %d\n",
                    i, bin_s, lin_s);
                printf("Find %d in\n", k[i]);
                for (int j = 0; j < n; ++j) {
                    std::cout << a[j] << ' ';
                }
                std::cout << std::endl;
                return;
            }
            else
                std::cout << "OK\n";
        }
    }
    return;
}

int main() {
    int n, m;
    // read a sorted sequence
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    // read a sequence of keys
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < b.size(); ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
    //test_solution(n, m);
    std::cout << std::endl;
    return 0;
}
