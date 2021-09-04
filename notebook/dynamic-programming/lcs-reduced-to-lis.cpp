/*
   Motivation: given two permutations A and B of numbers from 1 to N, find their LCS efficiently.

   Explanation:
         0 1 2 3 4 5 6 7 8
      A: 1 7 5 4 8 3 9 2 6
      B: 1 4 3 5 6 2 8 9 7
      C: 0 3 5 2 8 7 4 6 1, ou seja, C[i] = index of B[i] in A

      lcs(A, B) is equals to lis(C), pois todos os caracteres de cada sequência são distintos.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

/* input */
vector<int> a = {1,7,5,4,8,3,9,2,6};
vector<int> b = {1,4,3,5,6,2,8,9,7};

/* O(N * log(N)) */
int lis(vector<int> a) {
   int N = a.size();

   vector<int> size(N);
   vector<int> last(N+1, INF);
   last[0] = -INF;

   int biggest_s = 0;

   for (int j = 0; j < N; j++) {
      int s = lower_bound(last.begin(), last.end(), a[j]) - last.begin();
      if (a[j] < last[s]) last[s] = a[j];

      size[j] = s;
      biggest_s = max(biggest_s, s);
   }

   return biggest_s;
}

/* O(N * log(N)) */
int lcs(vector<int> a, vector<int> b) {
   vector<int> rev_a(b.size()+1, -1), c(b.size());
   for (int i = 0; i < a.size(); i++) rev_a[a[i]] = i;
   for (int i = 0; i < c.size(); i++) c[i] = rev_a[b[i]];
   return lis(c);
}

int main() {
   cout << lcs(a, b) << endl;
	return 0;
}
