## Main
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
    //     return a*b / __gcd(a,b);
    // }
    // int todeci(string s) {
        //     return stoi(s, nullptr, 16);
        // }
// const int N = 2e5+5, lg = 23;
void solve () {
    
}
// BEFORE coding are you sure you understood the statement correctly?
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.
// void clear(){
//     memset(vis,0,sizeof(vis));
//     for(int i = 1;i <= n; i++){
//         adj[i].clear();
//     }
// }
void read(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--){
        solve();
        clear();
    }
}
```


## bfs
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
const int N = 1e5+5, lg = 23;
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
    //     return a*b / __gcd(a,b);
    // }
    // int todeci(string s) {
        //     return stoi(s, nullptr, 16);
        // }
int n,m,q;
map<int,int>is_special;
int vis[N], lvl[N];
vector<int>adj[N];
void bfs(){
    queue<int>q;
    for(int i = 1; i <= n; i++)
    {
        if(is_special[i]){
            vis[i] = 1;
            q.push(i);
            lvl[i] = 0;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int ch : adj[cur]){
            if(!vis[ch]){
                q.push(ch);
                vis[ch] = 1 , lvl[ch] = lvl[cur] + 1;
            }
        }
    }
}
void clear(){
    for(int i = 1;i <= n; i++){
        lvl[i] = 0, vis[i] = 0;
        is_special[i] = 0;
        adj[i].clear();
    }
}
void solve () {//min(shotest path between special node and a node)
    /*
    input
    9 8
    1 3
    1 2
    3 6
    6 9
    2 5
    2 4
    5 7
    5 8
    3 //num of special nodes
    1 3 8
    9 -> queries
    9
    6
    3
    1
    2
    4
    5
    7
    8
    output
    2
    1
    0
    0
    1
    2
    1
    2
    0       
    */
    cin >> n >> m;
    for(int a, b, i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int num_of_special_nodes; cin >> num_of_special_nodes;
    for(int i = 0, sp; i < num_of_special_nodes; i++){
        cin >> sp;
        is_special[sp] = 1;
    }
    bfs();
    int q; cin >> q;
    while(q--){
        int node; cin >> node;
        // if node is special so the distance = 0
        cout << lvl[node] << el;
    }
}
void read(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        // clear();
    }
}
```


## dijkstra pure template
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
const int N = 1e5+5;
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
    //     return a*b / __gcd(a,b);
    // }
    // int todeci(string s) {
        //     return stoi(s, nullptr, 16);
        // }
        
// dijkstra pure template
int n,m,q;
int vis[N];
struct node{
    int idx , cost;
};
struct comp{
    bool operator()(node&a , node&b){
        return a.cost > b.cost;
    }
};
vector<node>adj[N];
int dijkstra(int st, int en){
    priority_queue<node, vector<node>,comp>pq;
    pq.push({st,0});
    vis[st] = 1;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(top.idx == en) return top.cost;

        vis[top.idx] = 1;
        for(auto ch : adj[top.idx]){
            if(!vis[ch.idx]){//won't mark it as visited cuz probably there is a path with less cost
                pq.push({ch.idx , top.cost + ch.cost});
            }
        }
    }
    return -1;// there is no way between these two nodes 
}
void solve () {
    cin >> n >> m;
    for(int u , cost , v, i = 0; i < m; i++){
        cin >> u >> v >> cost;
        adj[u].pb({v,cost});
        // adj[v].pb({u,cost}); //uncomment this line if undirected graph
    }
    cout << dijkstra(1 , n) << el;

}
void clear(){
    for(int i = 1;i <= n; i++){
        vis[i] = 0;
        adj[i].clear();
    }
}
void read(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        clear();
    }
}
```


## dijkstra
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
const int N = 2e5+5, lg = 23;
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
//     return a*b / __gcd(a,b);
// }
// int todeci(string s) {
//     return stoi(s, nullptr, 16);
// }
// ==> to print the path
struct edge{
    ll to , cost;
};
struct node{
    ll idx , cost, parent;
};
struct comp{
    bool operator()(node&a , node&b){
        return a.cost > b.cost;
    }
};
int n,m,q;
int vis[N];
vector<ll>parent(N,-1);
vector<edge>adj[N];
ll dijkstra(ll st, ll en){
    priority_queue<node, vector<node>,comp>pq;
    pq.push({st,0, -1});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(vis[top.idx])continue;
        
        vis[top.idx] = 1;
        parent[top.idx] = top.parent;
        
        if(top.idx == en) return top.cost;
        for(auto ch : adj[top.idx]){
            if(!vis[ch.to]){
                pq.push({ch.to , top.cost + ch.cost, top.idx});
            }
        }
    }
    return -1;
}
void print(ll en){
    ll node = en;
    stack<ll>st;
    while(node != -1){
        st.push(node);
        node = parent[node];
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
}
void solve () {
    cin >> n >> m;
    for(int u , cost , v, i = 0; i < m; i++){
        cin >> u >> v >> cost;
        adj[u].pb({v,cost});
        adj[v].pb({u,cost});
    }
    ll d = dijkstra(1,n);
    if(d == -1){
        return void(cout << "-1\n");
    }
    print(n);
    cout << el;

}
void clear(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n; i++){
        adj[i].clear();
    }
}
void read(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        clear();
    }
}
```


## dijkstra with queries
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int n, m, q;
// dijkstra with queries
vector<vector<pair<int, int>>> adj;
unordered_map<int, vector<ll>> memo;

vector<ll> dijkstra(int src) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

ll query(int u, int v) {
    if (!memo.count(u)) {
        memo[u] = dijkstra(u);
    }
    return memo[u][v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    adj.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        ll ans = query(u, v);
        if (ans == INF)
            cout << "No path\n";
        else
            cout << ans << '\n';
    }

    return 0;
}
```


## LCA PURE Template
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
const int N = 1e5+5, lg = 23;
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
    //     return a*b / __gcd(a,b);
    // }
    // int todeci(string s) {
        //     return stoi(s, nullptr, 16);
        // }
// ==> LCA PURE Template
int n, q, m, anc[N][lg] , lvl[N], mx[N][lg];
vector<pair<int,int>>adj[N];
void build(int node , int par,int val){
    lvl[node] = lvl[par] + 1;
    anc[node][0] = par;
    mx[node][0] = val;
    for(int i = 1;i < lg; i++){
        int p = anc[node][i-1];
        anc[node][i] = anc[p][i-1];//parent
        mx[node][i] = max(mx[p][i-1] , mx[node][i-1]);
    }
    for(auto [ch,cost] : adj[node]){
        if(ch != par){
            build(ch, node , cost);
        }
    }
}
int kthanc(int node , int k){
    for(int i = lg - 1; i >= 0;i--){
        if((k >> i) & 1){
            node = anc[node][i];
        }
    }
    return node;
}
int lca(int u , int v){
    if(lvl[u] < lvl[v]) swap(u , v);
    u = kthanc(u , lvl[u] - lvl[v]);
    if(u == v) return u;
    for(int i = lg - 1;i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}
int calc(int node , int dis){
    int ret = 0;
    for(int i = lg-1; i >= 0; i--){
        if((dis>>i)&1){
            ret = max(ret, mx[node][i]);
            node = anc[node][i];
        }
    }
    return ret;
}
int MX(int u , int v){// mx , min , gcd , LCM (Same as sparse table)
    int lc = lca(u,v);
    return max({calc(u, lvl[u] - lvl[lc]) ,calc(v, lvl[v] - lvl[lc])});
}
int dis(int u , int v){
    int lc = lca(u , v);
    return lvl[u] + lvl[v] - 2*lvl[lc];
}
void clear(){
    for(int i = 1; i <= n;i++){
        memset(mx[i],0,sizeof(mx[i]));
        adj[i].clear();
        lvl[i] = 0; 
    }
}
void solve () {
    while(cin >> n){
        if(n == 0)break;
        for(int i = 0; i < n-1; i++){
            int a , b , w; cin >> a >> b >> w;
            adj[a].pb({b,w});
            adj[b].pb({a,w});
        }
        build(1,1,0);
        cin >> q;
        while(q--){
            int n1 , n2; cin >> n1 >> n2;
            cout << MX(n1,n2) << el;
        }
        clear();
    }

}
void read(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}
```


## dp
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
//s.replace(pos , length , "string");
//string::npos
// unsigned up to 1e38 for positive integers only
// long double up to 1e30 // 1000000000
//cout << fixed << setprecision(4);

// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define int long long 
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
    //     return a*b / __gcd(a,b);
    // }
    // int todeci(string s) {
        //     return stoi(s, nullptr, 16);
        // }
const int N = 1005 , oo = 0x3f3f3f3f, mod = 1e9 + 7; 
int n , dp[N][N];
vector<vector<char>>grid(N , vector<char>(N));
int rec(int x, int y){
    if(x >= n || y >= n) return dp[x][y] = 0;
    
    if(~dp[x][y]) return dp[x][y];

    if(grid[x][y] == '*') return dp[x][y] = 0;
    
    if(x == n-1 && y == n-1) return dp[x][y] = 1;
    int ch1 = rec(x + 1 , y);
    int ch2 = rec(x , y + 1);
    
    return dp[x][y] = (ch1%mod + ch2%mod) % mod;
}
void solve () {
    cin >> n;
    memset(dp, -1 , sizeof (dp));
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    cout << rec(0 , 0)  << el;
}
// void clear(){
//     memset(vis,0,sizeof(vis));
//     for(int i = 1;i <= n; i++){
//         adj[i].clear();
//     }
// }
void read(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
signed main() {
    read();
    Panda;
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        // clear();
    }
}
```


## rec
```cpp
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define el '\n'
// s.replace(pos , length , "string");
// string::npos
//  unsigned up to 1e38 for positive integers only
//  long double up to 1e30 // 1000000000
// cout << fixed << setprecision(4);
 
// const int N = 1000;
// const double PI = 3.14159265359;
// char di[] = {'R' , 'L' , 'D' , 'U'};
// int dx[] = {0, 0 , 1 , -1};
// int dy[] = {1, -1 , 0 , 0};
#define ll long long
#define i64 int64_t
#define int long long
#define fir first
#define sec second
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define toupp(s) std::transform(s.begin(), s.end(), s.begin(), ::toupper);
// const int NN = 1e4 + 5;
// int lcm(int a , int b){
//     return a*b / __gcd(a,b);
// }
// int todeci(string s) {
//     return stoi(s, nullptr, 16);
// }
//count the number of integers between a and b where no two adjacent digits are the same.
const int N = 1e5, oo = 0x3f3f3f3f;
int dp[N][11][2][2];
string a, b;
 
int rec(int i, int last, bool eqA, bool eqB)
{
    if (i == (int)b.size())
        return 1;
 
    int &ret = dp[i][last][eqA][eqB];
 
    if (~ret)
        return ret;
 
    int upp = (eqB ? b[i] - '0' : 9);
    int low = (eqA ? a[i] - '0' : 0);
    ret = 0;
        
    for (int id = low; id <= upp; id++)
    {
        if(last == 10 && id == 0){
            ret += rec(i + 1, last, (id == low ? eqA : 0), (id == upp ? eqB : 0)); 
        }
        else if (id != last)
        {   
            ret += rec(i + 1, id, (id == low ? eqA : 0), (id == upp ? eqB : 0));
        }
    }
    return ret;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    a = string(b.length() - a.length(), '0') + a;
    cout << rec(0, 10 , 1 , 1) << el;
}
// void clear(){
//     memset(vis,0,sizeof(vis));
//     for(int i = 1;i <= n; i++){
//         adj[i].clear();
//     }
// }
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
        // clear();
    }
}
```


## to make the string palindrome with minimum possible number of deletions
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
// to make the string palindrome with minimum possible number of deletions
string s, t;
const int N = 3005;
int dp[N][N];
int rec(int l, int r)
{
    if (l >= r)
        return 0;
 
    int &ret = dp[l][r];
    if (~ret)
        return ret;
 
    if (s[l] == s[r])
        return ret = rec(l + 1, r - 1);
    return ret = min({rec(l + 1, r), rec(l, r - 1), rec(l + 1, r - 1)}) + 1;
}
void solve(int tt)
{
    memset(dp , -1 , sizeof (dp));
    cin >> s;
    int n = s.size();
    cout << "Case " << tt << ": " << rec(0, n - 1) << el;
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
        solve(tt);
}
```


## to build an ans
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
//to build an ans
string s, t;
const int N = 3005;
int dp[N][N], n;
int rec(int l = 0, int r = n - 1)
{
    if (l >= r)
        return 0;
 
    int &ret = dp[l][r];
    if (~ret)
        return ret;
 
    if (s[l] == s[r])
        return ret = rec(l + 1, r - 1);
    return ret = min(rec(l + 1, r), rec(l, r - 1)) + 1;
}
string ans;
void build(int l = 0, int r = n - 1)
{
    if (l > r)
        return;
    if (l == r)
    {
        ans += s[l];
        return;
    }
    if (s[l] == s[r])
    {
        ans += s[l];
        build(l + 1, r - 1);
        ans += s[r];
        return;
    }
    int ch1 = dp[l + 1][r], ch2 = dp[l][r - 1];
    int mn = min(ch1, ch2);
    if (mn == ch1)
    {
        ans += s[l];
        build(l + 1, r);
        ans += s[l];
    }
    else
    {
        ans += s[r];
        build(l, r - 1);
        ans += s[r];
    }
}
void solve()
{
    while (cin >> s)
    {
        for (int i = 0; i < (int)s.size(); i++)
            for (int j = 0; j < (int)s.size(); j++)
                dp[i][j] = -1;
        n = s.size();
        int cnt = rec();
        build();
        cout << cnt << " " << ans << el;
        ans = "";
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## SegTree with lazy propagation
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define int int64_t
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
// SegTree with lazy propagation 
struct Node
{

    int ign = 0;
    int val, lazy = 0;
    bool islazy = 0;
    Node()// neutral -> val doesn't affect
    {
        val = ign;
    }

    Node(int x)
    {
        val = x;
    }
    void update(int input, int lx, int rx)
    {
        val += input * (rx - lx);
        lazy += input;
        islazy = 1;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node();
        ans.val = lf.val + ri.val;
        return ans;
    }
    void propagate(int ni, int lx, int rx)
    {
        if (rx - lx == 1 || !segData[ni].islazy) // leaf
        {
            return;
        }
        int mid = (rx + lx) / 2;
        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;

        segData[lnode].update(segData[ni].lazy, lx, mid);
        segData[rnode].update(segData[ni].lazy, mid, rx);

        segData[ni].lazy = 0;
        segData[ni].islazy = 0;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int> &arr)
    {
        init(arr, 0, 0, tree_size);
    }
    void update(int l, int r, int val, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l)
        {
            return;
        }
        if (rx <= r && lx >= l)
        {
            segData[ni].update(val, lx, rx);
            return;
        }
        int mid = (rx + lx) / 2;
        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;
        update(l, r, val, lnode, lx, mid);
        update(l, r, val, rnode, mid, rx);
        segData[ni] = merge(segData[lnode], segData[rnode]);
    }
    void update(int l, int r, int val)
    {

        update(l, r, val, 0, 0, tree_size);
    }

    Node query(int &l, int &r, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l)
        {
            return Node();
        }
        if (rx <= r && lx >= l)
        {
            return segData[ni];
        }
        int mid = (rx + lx) / 2;

        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;

        Node lf = query(l, r, lnode, lx, mid);
        Node ri = query(l, r, rnode, mid, rx);

        return merge(lf, ri);
    }

    Node query(int l, int r)
    {
        return query(l, r, 0, 0, tree_size);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q; 

    segTree st = segTree(n);
    int op, l, r;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == 1)
        {
            int val;
            cin >> val;
            st.update(l, r, val);
        }
        else
        {
            cout << st.query(l, r).val << el;
        }
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## SegTree template
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define int int64_t
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
//SegTree template
struct Node
{
    int sum;
    Node() // neutral -> val doesn't affect
    {
        sum = 0;
    }
    Node(int x)
    {
        sum = x;
    }
    void change(int x)
    {
        sum = x;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node();
        ans.sum = lf.sum + ri.sum;
        return ans;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int>&arr)
    {
        init(arr, 0 , 0 , tree_size);
    }
    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]); // to update the tree
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int &l, int &r, int ni, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if (lx >= r || rx <= l)
        {
            return Node();
        }

        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, tree_size).sum;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segTree st = segTree(n);
    st.init(arr);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            st.set(idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.get(l, r) << el;
        }
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## get the max subarray
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define int int64_t
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
// to get the max subarray
struct Node
{
    int mx;
    int sum;
    int pref;
    int suff;
    Node() // neutral -> val doesn't affect
    {
        sum = 0;
        mx = pref = suff = -2e15;
    }
    Node(int x) // leaf
    {
        pref = suff = mx = sum = x;
    }
    void change(int x)
    {
        pref = suff = mx = sum = x;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node(tree_size);
        ans.mx = max({lf.mx, ri.mx, lf.suff + ri.pref});
        ans.pref = max({lf.pref, lf.sum + ri.pref});
        ans.suff = max({ri.suff, ri.sum + lf.suff});
        ans.sum = lf.sum + ri.sum;
        return ans;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int> &arr)
    {
        init(arr, 0, 0, tree_size);
    }
    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]); // to update the tree
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if (lx >= r || rx <= l)
        {
            return Node();
        }

        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, tree_size).mx;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segTree st = segTree(n);
    st.init(arr);

    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        st.set(idx, val);
        cout << st.get(0, n) << el;
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## get the minimum number in [l,r] range and print the frequency of it 
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define int int64_t
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
// to get the minimum number in [l,r] range and print the frequency of it 
struct Node
{
    int sum;
    int cnt;
    Node() // neutral -> val doesn't affect
    {
        cnt = 0;
        sum = 1e15;
    }
    Node(int x)
    {
        sum = x;
        cnt = 1;
    }
    void change(int x)
    {
        sum = x;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node ri)
    {
        Node ans = Node();
        ans.sum = min(lf.sum, ri.sum);
        if (ans.sum == lf.sum)
            ans.cnt += lf.cnt;
        if (ans.sum == ri.sum)
            ans.cnt += ri.cnt;
        return ans;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);
 
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int> &arr)
    {
        init(arr, 0, 0, tree_size);
    }
    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]); // to update the tree
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, tree_size);
    }
 
    Node get(int l, int r, int ni, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if (lx >= r || rx <= l)
        {
            return Node();
        }
 
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }
 
    Node get(int l, int r)
    {
        return get(l, r, 0, 0, tree_size);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segTree st = segTree(n);
    st.init(arr);
 
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            st.set(idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            Node GetRange = st.get(l, r);
            cout << GetRange.sum << " " << GetRange.cnt << el;
        }
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## to update and to get the sum from L to R
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define int int64_t
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
// to update and to get the sum from L to R
struct Node
{
    int sum;
    Node() // neutral -> val doesn't affect
    {
        sum = 0;
    }
    Node(int x)
    {
        sum = x;
    }
    void change(int x)
    {
        sum = x;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node();
        ans.sum = lf.sum + ri.sum;
        return ans;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);
 
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int>&arr)
    {
        init(arr, 0 , 0 , tree_size);
    }
    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]); // to update the tree
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, tree_size);
    }
 
    Node get(int &l, int &r, int ni, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if (lx >= r || rx <= l)
        {
            return Node();
        }
 
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }
 
    int get(int l, int r)
    {
        return get(l, r, 0, 0, tree_size).sum;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segTree st = segTree(n);
    st.init(arr);
 
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            st.set(idx-1, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.get(l, r) << el;
        }
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```


## 1-increase the range [L,R] , 2-Print the number at Idx 
```cpp
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define int long long
#define Panda ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 0;
// 1-increase the range [L,R] , 2-Print the number at Idx 
struct Node
{
 
    int ign = 0;
    int val, lazy = 0;
    bool islazy = 0;
    Node() // neutral -> val doesn't affect
    {
        val = ign;
    }
 
    Node(int x)
    {
        val = x;
    }
    void update(int input, int lx, int rx)
    {
        val += input * (rx - lx);
        lazy += input;
        islazy = 1;
    }
};
struct segTree
{
    int tree_size;
    vector<Node> segData;
    segTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
        {
            tree_size *= 2; // first element pw2 >= n
        }
        segData.assign(2 * tree_size, Node());
    }
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node();
        ans.val = lf.val + ri.val;
        return ans;
    }
    void propagate(int ni, int lx, int rx)
    {
        if (rx - lx == 1 || !segData[ni].islazy) // leaf
        {
            return;
        }
        int mid = (rx + lx) / 2;
        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;
 
        segData[lnode].update(segData[ni].lazy, lx, mid);
        segData[rnode].update(segData[ni].lazy, mid, rx);
 
        segData[ni].lazy = 0;
        segData[ni].islazy = 0;
    }
    void init(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                segData[ni] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);
 
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void init(vector<int> &arr)
    {
        init(arr, 0, 0, tree_size);
    }
    void update(int l, int r, int val, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l)
        {
            return;
        }
        if (rx <= r && lx >= l)
        {
            segData[ni].update(val, lx, rx);
            return;
        }
        int mid = (rx + lx) / 2;
        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;
        update(l, r, val, lnode, lx, mid);
        update(l, r, val, rnode, mid, rx);
        segData[ni] = merge(segData[lnode], segData[rnode]);
    }
    void update(int l, int r, int val)
    {
 
        update(l, r, val, 0, 0, tree_size);
    }
 
    Node query(int &l, int &r, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l)
        {
            return Node();
        }
        if (rx <= r && lx >= l)
        {
            return segData[ni];
        }
        int mid = (rx + lx) / 2;
 
        int lnode = 2 * ni + 1;
        int rnode = 2 * ni + 2;
 
        Node lf = query(l, r, lnode, lx, mid);
        Node ri = query(l, r, rnode, mid, rx);
 
        return merge(lf, ri);
    }
 
    Node query(int l, int r)
    {
        return query(l, r, 0, 0, tree_size);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    segTree st = segTree(n);
    st.init(v);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            if (l > r)
                swap(l, r);
            st.update(l-1, r, val);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << st.query(idx - 1, idx).val << el;
        }
    }
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    read();
    Panda;
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}
```
