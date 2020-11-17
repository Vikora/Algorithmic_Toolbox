#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct bound {
    int lb, rb;
};

bound partition3(vector<int> &a, int l, int r) {
    bound b;
    int x = a[r];
    int j = l, p = r, i = l;
    while(i < p) {
     if (a[i] < x) {
            swap(a[i], a[j]);
            ++j; // increase edge of partition '<x'
            ++i; // next element
        }
        else if (a[i] > x)
            ++i;
        else { // a[i] == x
            --p; // increase edge of partition '=x'
            swap(a[i], a[p]);
        }    
    }
    b.lb = j - 1;
    b.rb = r - (p - j) + 1;
    // move partition '=x' between partitions '<x' and '>x'
    i = r;
    while(j < p && i >= p) {
        swap(a[j], a[i]);
        ++j; --i;
    }
    return b;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    // move pivot to the end
    swap(a[r], a[k]);
    bound b = partition3(a, l, r);
 
    randomized_quick_sort(a, l, b.lb);
    randomized_quick_sort(a, b.rb , r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
