#include <iostream>
#include <vector>

using std::vector;
using std::swap;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (left >= right)
    return 0;

  size_t ave = (right + left) / 2, i = left, j = ave+1, k = left;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  // fill vector b such that all the elements from left to ave 
  // is smaller than from ave+1 to right and count inversions
  while(i <= ave && j <= right) {
    if(a[i] <= a[j]) {
      // no inversions
      b[k++] = a[i++];
    }
    else {
      // inversions
      b[k++] = a[j++];
      number_of_inversions += ave - i + 1;
    }
  }
  // copy the remaining elements to b
  while(i <= ave)
    b[k++] = a[i++];
  while(j <= right)
    b[k++] = a[j++];

  // copy back merged elements to original array
  for(k = left; k <= right; ++k)
    a[k] = b[k];
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
