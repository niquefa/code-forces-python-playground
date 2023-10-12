#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve();

int find_first_substring(const string& str, const string& substr) {
    size_t found = str.find(substr);
    return found != string::npos ? static_cast<int>(found) : -1; 
}
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n, m;
  string x, s;
  cin >> n >> m >> x >> s;
  int ans = 0;
  while(true) {
    int index = find_first_substring(x,s);
    //debug(ans, index, x, y);
    if(index != -1) break;
    x = x+x;
    ans++;
    if( ans > 5 && x.size() > 5*s.size() ) {
      ans = -1;
      break;
    }
  }


  cout << ans << endl;
}
