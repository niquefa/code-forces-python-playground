#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  vector<long long> s(n);
  s[0] = a[0];
  for( int i = 1; i < n; ++ i) {
    s[i] = s[i - 1] + a[i];
    if( s[i] < ((i+1)*(i))/2) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
