```cpp
#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// FAST IO & SHORTCUTS
// ============================================================================
#define IAMFAST                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

#define ld long double
#define ll long long
#define ull unsigned long long

// Loop shortcut: fl(int, i, n) expands to: for(int i = 0; i < n; i++)
#define fl(type, index, size) for (type index = 0; index < size; index++)

#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()

#define MOD 1000000007 // A large prime (commonly used in hashing and mod arithmetic)

#define space ' '
#define en '\n'
#define el endl

// Shortcut for handling multiple test cases
#define Test  \
    int t;    \
    cin >> t; \
    for (int i = 0; i < t; i++)

// ============================================================================
// CONSTANTS FOR MULTI-HASHING
// ============================================================================

/** These primes are:
 * - Large enough to avoid collisions.
 * - Close to 1e9+7 to avoid overflow when multiplied.
 * - Different enough to minimize chances of multiple collisions.
 */
const int MOD1 = 1000000007; // classic
const int MOD2 = 1000000009; // close and prime
const int MOD3 = 1000000021; // another nearby large prime

// Optional: base values can also be changed for different hash functions
const int BASE1 = 31;
const int BASE2 = 37;
const int BASE3 = 41;

// ============================================================================
// MODULAR ARITHMETIC
// ============================================================================

/** Fast modular exponentiation.
 * Computes (x^y) % MOD efficiently in O(log y) time.
 * Used in modular inverse, hashing, and number theory problems.
 */
ll powmod(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    if (x == 0)
        return 0; // Edge case: 0^y = 0
    while (y)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

/** Modular Inverse using Fermat's Little Theorem
 * inv(x) = x^(MOD-2) % MOD (only valid if MOD is prime)
 */
ll inv(int x)
{
    return powmod(x, MOD - 2);
}

// ============================================================================
// HASHING (Rolling Hash with Push/Pop from both sides)
// ============================================================================
const int BASE = 31;   // Base used for polynomial rolling hash (commonly 31 or 53)
const int N = 1e5 + 5; // Max length of string expected
int pw[N + 1];         // Precomputed powers of BASE
int inv_base;          // Modular inverse of BASE

/** Initializes precomputed powers of BASE up to N.
 *  Required for O(1) hash updates in push_back/pop_back.
 */
void init_pow()
{
    pw[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        pw[i] = (1LL * pw[i - 1] * BASE) % MOD;
    }
    inv_base = powmod(BASE, MOD - 2); // Optimization: precompute inverse
}

/**
 * Hashing struct for maintaining a rolling hash of a string.
 * Supports O(1) insertion/removal at both front and back.
 */
struct Hashing
{
    int h, len;
    deque<char> h_deque;

    Hashing()
    {
        this->len = 0;
        this->h = 0;
    }

    // ========================================================================
    // push_front(char)
    // Adds a character to the front of the hash string.
    // Example: "15" + '3' -> becomes "153"
    //
    // Formula: hash = hash * BASE + dig
    // Time: O(1)
    // ========================================================================
    void push_front(char ch)
    {
        h_deque.push_front(ch);
        int dig = ch - 'a' + 1;
        h = ((h * BASE) % MOD + dig % MOD) % MOD;
        len++;
    }

    // ========================================================================
    // pop_front()
    // Removes character from the front.
    // Old: h = (h - dig) / BASE  ==> Optimized using inv_base
    //
    // Time: O(1) after precomputing inv_base
    // ========================================================================
    void pop_front()
    {
        if (len == 0)
            return;
        char ch = h_deque.front();
        int dig = ch - 'a' + 1;

        // Optimization: Avoid division by using modular inverse
        h = (h - dig + MOD) % MOD;
        h = (1LL * h * inv_base) % MOD;

        h_deque.pop_front();
        len--;
    }

    // ========================================================================
    // push_back(char)
    // Adds character to the back of the string.
    // Old: h += dig * powmod(BASE, len)
    // Optimization: Use precomputed pw[len]
    //
    // Time: O(1)
    // ========================================================================
    void push_back(char ch)
    {
        h_deque.push_back(ch);
        int dig = ch - 'a' + 1;
        h = (h + (1LL * dig * pw[len]) % MOD) % MOD;
        len++;
    }

    // ========================================================================
    // pop_back()
    // Removes character from the back.
    // Old: h -= dig * powmod(BASE, len - 1)
    // Optimization: Use precomputed pw[len - 1]
    //
    // Time: O(1)
    // ========================================================================
    void pop_back()
    {
        if (len == 0)
            return;
        char ch = h_deque.back();
        int dig = ch - 'a' + 1;

        h = (h - (1LL * dig * pw[len - 1]) % MOD + MOD) % MOD;
        h_deque.pop_back();
        len--;
    }

    // Get current hash value
    int get()
    {
        return h;
    }
};

// ============================================================================
// DISJOINT SET UNION (DSU / UNION-FIND)
// ============================================================================

/**
 * Efficient data structure to manage disjoint sets.
 * Supports:
 * - `get_root(x)`: returns the representative of the set containing `x`
 * - `merge(x, y)`: merges the sets containing `x` and `y`
 *
 * Optimizations:
 * - Path Compression (in get_root)
 * - Union by Size (in merge)
 *
 * Usage:
 * DSU dsu(n); // initialize DSU with n elements (1-based)
 * dsu.merge(u, v); // union sets containing u and v
 * dsu.get_root(u); // find set representative of u
 */
struct DSU
{
    vector<int> parent;
    vector<int> size;
    int n;

    // Constructor: initializes n disjoint sets (1-based indexing)
    DSU(int n) : n(n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    // Find with path compression
    int get_root(int u)
    {
        if (parent[u] != u)
            parent[u] = get_root(parent[u]);
        return parent[u];
    }

    // Union by size
    bool merge(int u, int v)
    {
        int root_u = get_root(u);
        int root_v = get_root(v);
        if (root_u == root_v)
            return false; // already in the same set

        // Ensure root_v has the larger size
        if (size[root_u] > size[root_v])
            swap(root_u, root_v);

        parent[root_u] = root_v;
        size[root_v] += size[root_u];
        return true;
    }
};

// ============================================================================
// GEOMETRY (2D Computational Geometry Utilities)
// ============================================================================

/**
 * Common structs and functions for 2D geometry problems.
 * Covers:
 * - Point and Vector operations
 * - Orientation (ccw/cw), dot/cross product
 * - Rotation, scaling, translation
 * - Linear transformations based on known mappings
 * - Length comparisons using squared distance
 *
 * All points assume type T (can be int or long double).
 * Use long double (ld) for floating-point precision.
 */

// Precision for floating-point comparisons
const long double EBS = 1e-6;

// ===== TYPE DEFINITIONS =====
typedef ld T;

// If needed in generic code, this can become a template parameter instead.

// ----------------------------------------------------------------------------
// Point2D (struct-based, readable and intuitive, good for CP debugging)
// ----------------------------------------------------------------------------
struct Point2D
{
    T x, y;

    Point2D(T x, T y) : x(x), y(y) {}
    Point2D() : x(0), y(0) {}

    // Arithmetic operations
    Point2D operator+(Point2D pt) const { return {x + pt.x, y + pt.y}; }
    Point2D operator-(Point2D pt) const { return {x - pt.x, y - pt.y}; }
    Point2D operator*(T d) const { return {x * d, y * d}; } // scalar multiplication
    Point2D operator/(T d) const { return {x / d, y / d}; }

    // Comparisons
    bool operator==(Point2D pt) const { return (x == pt.x && y == pt.y); }
    bool operator!=(Point2D pt) const { return !(*this == pt); }

    // Length
    T sq() const { return x * x + y * y; } // squared magnitude
    T abs() const { return sqrtl(sq()); }

    // Stream I/O
    friend ostream &operator<<(ostream &os, const Point2D &pt)
    {
        return os << '(' << pt.x << ", " << pt.y << ')';
    }

    friend istream &operator>>(istream &is, Point2D &pt)
    {
        return is >> pt.x >> pt.y;
    }
};

// ----------------------------------------------------------------------------
// Utility Sign Function for Floating-Point Comparisons
// Returns -1 if x < -EBS, 1 if x > EBS, 0 otherwise
// ----------------------------------------------------------------------------
template <typename T>
int sgn(T x)
{
    return (x > EBS) - (x < -EBS);
}

// ----------------------------------------------------------------------------
// Complex-based Point (short, powerful, great for fast prototyping)
// T real() => x  |  T imag() => y
// ----------------------------------------------------------------------------
typedef complex<T> Point2d;

#define x real()
#define y imag()

// ----------------------------------------------------------------------------
// Geometric Transformations
// ----------------------------------------------------------------------------

// Translate point `p` by vector `v`
Point2d translate(Point2d v, Point2d p) { return p + v; }

// Scale point `p` about center `c` by factor
Point2d scale(Point2d c, T factor, Point2d p) { return (p - c) * factor + c; }

// Rotate point `p` about center `c` by angle (in radians)
Point2d rotate(Point2d c, Point2d p, T angle) { return (p - c) * polar(T(1), angle) + c; }

// Perpendicular vector (90 degrees CCW)
Point2d prep(Point2d p) { return {-p.y, p.x}; }

// ----------------------------------------------------------------------------
// Length
// ----------------------------------------------------------------------------
T sq(Point2d &p) { return (p.x * p.x + p.y * p.y); } // squared magnitude
T abs(Point2d &p) { return sqrtl(sq(p)); }           // magnitude (slower)

// ----------------------------------------------------------------------------
// Composite Transformations
// ----------------------------------------------------------------------------

// Applies rotation and scaling AFTER translation
Point2d transform_after_translate(Point2d &p, Point2d &c, T &factor, T &angle, Point2d &v)
{
    return (p - c) * polar(factor, angle) + c + v;
}

// Applies translation BEFORE rotation and scaling
Point2d transform_before_translate(Point2d &p, Point2d &c, T &factor, T &angle, Point2d &v)
{
    return (p + v - c) * polar(factor, angle) + c;
}

// ----------------------------------------------------------------------------
// Dot and Cross Products
// ----------------------------------------------------------------------------

// Dot Product: measures projection (p1 ⋅ p2), V1
// T dot(Point2d &p1, Point2d &p2) { return p1.x * p2.x + p1.y * p2.y; }

// Cross Product: area of parallelogram, sign gives orientation, V1
// T cross(Point2d &p1, Point2d &p2) { return p1.x * p2.y - p1.y * p2.x; }

/**
 * p = x + yi
 * conj(p) = x - yi
 * conj(p) * p2 = x * x2 + x * y2i - x2 * yi - y2 * y * i^2 =  (x * x2 + y * y2) + (x * y2 - x2 * y)i = dot + cross
 */

// Dot Product: measures projection (p1 ⋅ p2), V2
T dot(Point2d p1, Point2d p2) { return (conj(p1) * p2).x; }

// Cross Product: area of parallelogram, sign gives orientation, V2
T cross(Point2d p1, Point2d p2) { return (conj(p1) * p2).y; }

bool isPrep(Point2d &p1, Point2d &p2) { return dot(p1, p2) == 0; }

// T angleDot(Point2d &p1, Point2d &p2)
// {
//     T cosTheta = dot(p1, p2) / (abs(p1) * abs(p2));
//     return acos(max((T)-1, min((T)1, cosTheta)));
// }

// simple version for C++17 and higher
T angleDot(Point2d p1, Point2d p2)
{
    T cosTheta = dot(p1, p2) / (abs(p1) * abs(p2));
    return acos(clamp(cosTheta, (T)-1, (T)1));
}

T orient(Point2d p1, Point2d p2, Point2d p3)
{
    return cross((p2 - p1), (p3 - p1));
}
// ----------------------------------------------------------------------------
// Linear Transformation Using Mapped Points
// ----------------------------------------------------------------------------

/**
 * Version 1: Linear transform point `r` using mappings:
 * - f(p) = fp
 * - f(q) = fq
 * => Compute f(r)
 */
Point2d linearTransfo(Point2d p, Point2d q, Point2d r, Point2d fp, Point2d fq)
{
    return fp + (r - p) * (fq - fp) / (q - p);
}

/**
 * Version 2: Safer, using cross and dot instead of complex division
 * - Useful when coordinates are not normalized or edge cases exist
 */
Point2d linearTransfo2(Point2d p, Point2d q, Point2d r, Point2d fp, Point2d fq)
{
    Point2d pq = q - p;
    Point2d num{cross(pq, fq - fp), dot(pq, fq - fp)};
    return fp + Point2d{cross(r - p, num), dot(r - p, num)} / sq(pq);
}

// ============================================================================
// GAME THEORY (Grundy Numbers, MEX, Nim Game)
// ============================================================================

/**
 * Computes the minimum excluded value (mex) from a set of integers.
 * Typically used in computing Grundy numbers.
 * Time: O(n log n) due to set (or use bool array for O(n))
 */
int mex(const vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int m = 0;
    while (s.count(m))
        ++m;
    return m;
}

int mex_bool(const vector<int> &nums)
{
    bool present[100005] = {};
    for (int num : nums)
        if (num < 100005)
            present[num] = true;

    for (int i = 0;; i++)
        if (!present[i])
            return i;
}

/**
 * Computes Grundy numbers for positions in a game.
 * Each state `i` can move to states listed in `moves[i]`.
 * Uses memoization to cache results.
 *
 * @param i: Current state
 * @param moves: List of moves from each state
 * @param dp: Memoization table for Grundy numbers
 *
 * Usage:
 * vector<vector<int>> moves(n);
 * vector<int> dp(n, -1);
 * int g = grundy(start, moves, dp);
 */
int grundy(int i, const vector<vector<int>> &moves, vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];

    vector<int> next_grundies;
    for (int move : moves[i])
    {
        next_grundies.push_back(grundy(move, moves, dp));
    }

    return dp[i] = mex(next_grundies);
}

/**
 * Classic NIM Game win/lose checker.
 * If the XOR of all heaps is 0, it's a losing position.
 */
bool is_winning_nim(const vector<int> &heaps)
{
    int xor_sum = 0;
    for (int heap : heaps)
        xor_sum ^= heap;
    return xor_sum != 0;
}

// ============================================================================
// GRAPH ALGORITHMS
// ============================================================================

/**
 * BFS: Breadth-First Search (single-source, unweighted graphs)
 */
void bfs(int start, const vector<vector<int>> &adj, vector<int> &dist)
{
    int n = adj.size();
    dist.assign(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

/**
 * Multi-Source BFS
 */
void multi_source_bfs(const vector<int> &sources, const vector<vector<int>> &adj, vector<int> &dist)
{
    int n = adj.size();
    dist.assign(n, -1);
    queue<int> q;
    for (int src : sources)
    {
        dist[src] = 0;
        q.push(src);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

/**
 * DFS: Depth-First Search
 */
void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}

/**
 * Dijkstra's Algorithm (single-source, weighted graph with non-negative weights)
 */
void dijkstra(int start, const vector<vector<pair<int, int>>> &adj, vector<long long> &dist)
{
    int n = adj.size();
    dist.assign(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

/**
 * Multi-Source Dijkstra
 */
void multi_source_dijkstra(const vector<int> &sources, const vector<vector<pair<int, int>>> &adj, vector<long long> &dist)
{
    int n = adj.size();
    dist.assign(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    for (int src : sources)
    {
        dist[src] = 0;
        pq.emplace(0, src);
    }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

// ============================================================================
// DATA STRUCTURES
// ============================================================================

/**
 * Binary Indexed Tree (Fenwick Tree)
 */
struct BIT
{
    vector<long long> tree;
    int n;

    BIT(int size) : n(size)
    {
        tree.assign(n + 1, 0);
    }

    void update(int i, long long delta)
    {
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }

    long long query(int i)
    {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    long long range_query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

/**
 * Segment Tree (point update, range query)
 */
struct SegmentTree
{
    vector<long long> tree;
    int n;

    SegmentTree(int size) : n(size)
    {
        tree.assign(4 * n, 0);
    }

    void update(int idx, long long val, int node = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int ql, int qr, int node = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node, l, mid) + query(ql, qr, 2 * node + 1, mid + 1, r);
    }
};

// ============================================================================
// BITMASKING UTILITIES
// ============================================================================

/**
 * Examples:
 * - Iterate through all subsets of a mask
 * - Count set bits
 */

int count_bits(int mask)
{
    return __builtin_popcount(mask);
}

vector<int> get_submasks(int mask)
{
    vector<int> res;
    for (int sub = mask; sub; sub = (sub - 1) & mask)
        res.push_back(sub);
    res.push_back(0);
    return res;
}

// ============================================================================
// SOLUTION ENTRY POINT
// ============================================================================

void solve()
{
    // You can write sample uses for Hash here if you'd like to test it
}

signed main()
{
    IAMFAST
#ifndef ONLINE_JUDGE
    freopen("./input.in", "r", stdin);
    freopen("./output.out", "w", stdout);
#endif
    // Test
    solve();
    return 0;
}
```
