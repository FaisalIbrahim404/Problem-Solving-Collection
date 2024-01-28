#include <bits/stdc++.h>
using namespace std;

// Typedefs for Convenience
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;

// Constants
const double EPS = 1e-9;

// Fast I/O
void fastIO()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

// ShortCut
#define el endl

// Debugging Tools
void debugOut() { cerr << endl; }
template <typename Head, typename... Tail>
void debugOut(Head H, Tail... T)
{
  cerr << " " << H;
  debugOut(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:"; debugOut(__VA_ARGS__)

// Function Prototypes
void problemA();

int main()
{
  fastIO();

  // Uncomment if file I/O is required
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    problemA();
  }
  return 0;
}

// Implementations of Problem Functions
void problemA()
{
  // Logic for Problem A
}
