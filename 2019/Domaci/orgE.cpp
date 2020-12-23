// Solution Author: Jakub Svoboda
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>

#define ll long long

using namespace std;
int left_view[1111000], right_view[1111000], x[1111000], h[1111000];

int distance(int i, int j) {
  return abs(x[i] - x[j]) -
         abs(h[i] - h[j]);
}

int comp_views(int i, int j) {
  if (i == -1)
    return j;
  if (j == -1)
    return i;
  return min(i, j);
}

void solve() {
  int n;
  scanf("%i", &n);
  vector<int> l_stack, r_stack;

  for (int a = 0; a < n; a++) {
    scanf("%i%i", &x[a], &h[a]);
  }

  for (int a = 0; a < n; a++) {
    while (l_stack.size() > 0 && h[l_stack.back()] < h[a])
      l_stack.pop_back();

    if (l_stack.size() == 0)
      left_view[a] = -1;
    else {
      int i = l_stack.back();
      left_view[a] = distance(i, a);
    }
    l_stack.push_back(a);
  }
  for (int a = n - 1; a >= 0; a--) {
    while (r_stack.size() > 0 && h[r_stack.back()] < h[a])
      r_stack.pop_back();

    if (r_stack.size() == 0)
      right_view[a] = -1;
    else {
      int i = r_stack.back();
      right_view[a] = distance(a, i);
    }
    r_stack.push_back(a);
  }

  for (int a = 0; a < n; a++) {
    printf("%i", comp_views(left_view[a], right_view[a]));
    if (a == n - 1)
      printf("\n");
    else
      printf(" ");
  }
}

int main() {
  int t;
  scanf("%i", &t);
  for (int a = 0; a < t; a++)
    solve();
  return 0;
}

