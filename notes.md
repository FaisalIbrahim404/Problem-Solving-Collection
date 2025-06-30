# Competitive Programming Reference Book  

## Preface  
- **Purpose**: A comprehensive reference for math, algorithms, and problem-solving techniques in competitive programming.  
- **Target Audience**: Intermediate-to-advanced coders preparing for contests (e.g., ECPC, ICPC, Codeforces).  
- **How to Use**: Focus on weak areas, review before contests, or use code snippets as templates.  

---

## Table of Contents  

### 1. Math Fundamentals  
   - **Modular Arithmetic**  
   - **GCD/LCM & Number Theory**  
   - **Combinatorics & Probability**  
   - **Matrix Operations**  
   - **Floating-Point Precision**  

### 2. Geometry  
   - **2.1 Coordinate Systems**  
     - 2D (Cartesian, Polar)  
     - 3D (Cylindrical, Spherical)  
     - Conversion Formulas & Code  
   - **2.2 Lines & Slopes**  
     - Slope Calculation  
     - Collinearity & Line Representations  
   - **2.3 Triangles**  
     - Pythagorean Theorem, Heron’s Formula  
     - Law of Sines/Cosines  
     - Triangle Centers (Centroid, Circumradius)  
   - **2.4 Area & Volume**  
     - 2D Shapes (Polygons, Circles)  
     - 3D Shapes (Prisms, Spheres)  
     - Shoelace Formula for Polygons  
   - **2.5 Parametric Equations**  
     - Lines, Circles, and Motion Simulations  
   - **2.6 Edge Cases & Tips**  
     - Precision Handling  
     - Common Pitfalls in Geometry Problems  

### 3. Data Structures  
   - Arrays & Hash Maps  
   - Stacks & Queues  
   - Trees & Heaps  
   - Disjoint Set Union (Union-Find)  
   - Segment Trees & Binary Indexed Trees  

### 4. Algorithms  
   - Sorting & Searching  
   - Graph Algorithms (Dijkstra, DFS/BFS)  
   - Dynamic Programming Patterns  
   - Greedy Techniques  
   - Bit Manipulation  

### 5. Physics & Simulations  
   - Kinematics & Motion  
   - Forces & Energy  
   - Collision Detection  
   - Time-Based Simulations  

### 6. General Strategies  
   - Time Complexity Analysis  
   - Debugging Tips  
   - Edge Case Checklist  
   - Fast Input/Output (C++)  

### Appendices  
   - **A. Code Templates** (Fast IO, Binary Search)  
   - **B. Mathematical Constants** (π, e, √2)  

---

## 1. Math Fundamentals  

### 1.1 Modular Arithmetic  
- **Basic Properties**:  
  - $(a + b) \mod m = ((a \mod m) + (b \mod m)) \mod m$  
  - $(a \cdot b) \mod m = ((a \mod m) \cdot (b \mod m)) \mod m$  
- **Fermat’s Little Theorem**:  
  - $a^{m-1} \equiv 1 \mod m$ if $m$ is prime.  
  - Use for modular inverses: $a^{-1} \equiv a^{m-2} \mod m$.  
- **Chinese Remainder Theorem (CRT)**: Solve systems of congruences like $x \equiv a_i \mod m_i$.  
- **Modular Exponentiation**:  
  ```cpp  
  int mod_pow(int base, int exp, int mod) {  
      int result = 1;  
      while (exp > 0) {  
          if (exp % 2 == 1) result = (1LL * result * base) % mod;  
          base = (1LL * base * base) % mod;  
          exp /= 2;  
      }  
      return result;  
  }  
  ```  

---

### 1.2 GCD/LCM & Number Theory  
- **Euclidean Algorithm**:  
  - $\gcd(a, b) = \gcd(b, a \mod b)$  
  - Iterative implementation:  
    ```cpp  
    int gcd(int a, int b) {  
        while (b != 0) {  
            int temp = b;  
            b = a % b;  
            a = temp;  
        }  
        return a;  
    }  
    ```  
- **Extended GCD**: Find integers $x, y$ such that $ax + by = \gcd(a, b)$.  
- **LCM**: $\text{lcm}(a, b) = \frac{a \cdot b}{\gcd(a, b)}$.  
- **Prime Sieve (Eratosthenes)**:  
  ```cpp  
  vector<bool> is_prime(n+1, true);  
  for (int i=2; i*i<=n; ++i)  
      if (is_prime[i])  
          for (int j=i*i; j<=n; j+=i)  
              is_prime[j] = false;  
  ```  

---

### 1.3 Combinatorics & Probability  
- **Permutations**:  
  - $P(n, k) = \frac{n!}{(n-k)!}$  
- **Combinations**:  
  - $\binom{n}{k} = \frac{n!}{k!(n-k)!}$  
  - Precompute factorials and inverses modulo primes:  
    ```cpp  
    const int MOD = 1e9 + 7;  
    vector<int> fact(n+1, 1), inv_fact(n+1, 1);  
    for (int i=1; i<=n; ++i) fact[i] = (1LL * fact[i-1] * i) % MOD;  
    inv_fact[n] = mod_pow(fact[n], MOD-2, MOD);  
    for (int i=n-1; i>=0; --i) inv_fact[i] = (1LL * inv_fact[i+1] * (i+1)) % MOD;  
    ```
- **Inclusion-Exclusion Principle**:  
  - Count union of overlapping sets:  
    $|A_1 \cup A_2 \cup \dots \cup A_n| = \sum |A_i| - \sum |A_i \cap A_j| + \dots + (-1)^{k+1} |A_1 \cap \dots \cap A_k|$.  
- **Expected Value**:  
  - $E[X] = \sum x_i \cdot P(x_i)$.  

---

### 1.4 Matrix Operations  
- **Matrix Multiplication**:  
  ```cpp  
  vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b, int mod) {  
      int n = a.size(), m = b[0].size(), k = b.size();  
      vector<vector<int>> res(n, vector<int>(m, 0));  
      for (int i=0; i<n; ++i)  
          for (int j=0; j<m; ++j)  
              for (int x=0; x<k; ++x)  
                  res[i][j] = (res[i][j] + 1LL * a[i][x] * b[x][j]) % mod;  
      return res;  
  }  
  ```  
- **Matrix Exponentiation**: Use for linear recursions (e.g., Fibonacci):  
  - $F_n = F_{n-1} + F_{n-2}$ → represent as $\begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^n$.  
- **Determinant & Inverse (2x2)**:  
  - Determinant: $ad - bc$ for $\begin{bmatrix} a & b \\ c & d \end{bmatrix}$.  
  - Inverse: $\frac{1}{ad - bc} \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}$.  

---

### 1.5 Floating-Point Precision  
- **Precision Handling**:  
  - Use `EPS = 1e-9` for comparisons:  
    ```cpp  
    bool eq(double a, double b) { return abs(a - b) < EPS; }  
    ```  
- **Avoiding Errors**:  
  - Compare absolute differences for near-zero values.  
  - Use `long double` for higher precision (if needed).  
- **Edge Cases**:  
  - Check for division by zero in slope/ratio calculations.  
  - Clamp values to avoid overflow (e.g., `acos(max(-1.0, min(1.0, x)))`).

---

## Coordinate Systems & Conversions  

### 2.1 Coordinate Systems  
- **2D Systems**:  
  - **Cartesian Coordinates** $(x, y)$: Standard grid system.  
  - **Polar Coordinates** $(r, \theta)$:  
    - $x = r \cos\theta$, $y = r \sin\theta$  
    - $\theta = \text{atan2}(y, x)$, $r = \sqrt{x^2 + y^2}$  
- **3D Systems**:  
  - **Cartesian** $(x, y, z)$: Standard 3D grid.  
  - **Cylindrical** $(r, \theta, z)$:  
    - $x = r \cos\theta$, $y = r \sin\theta$, $z = z$  
  - **Spherical** $(r, \theta, \phi)$:  
    - $x = r \sin\phi \cos\theta$, $y = r \sin\phi \sin\theta$, $z = r \cos\phi$  

### Conversion Code Snippet  
```cpp  
// Polar to Cartesian  
Point2D polar_to_cartesian(double r, double theta) {  
    return {r * cos(theta), r * sin(theta)};  
}  

// Spherical to Cartesian  
Point3D spherical_to_cartesian(double r, double theta, double phi) {  
    return {  
        r * sin(phi) * cos(theta),  
        r * sin(phi) * sin(theta),  
        r * cos(phi)  
    };  
}  
```  

---

## Lines & Slopes  

### 2.2 Lines & Slopes  
- **Slope Formula**:  
  - $m = \frac{y_2 - y_1}{x_2 - x_1}$ (undefined for vertical lines).  
  - **Point-Slope Form**: $y - y_1 = m(x - x_1)$  
- **Collinearity Check**:  
  - **3 Points**: Use cross product → $(\vec{AB} \times \vec{AC}) = 0$.  
  - **Edge Case**: Handle vertical/horizontal lines separately to avoid division by zero.  

---

## Triangle Relations & Theorems  

### 2.3 Triangles  
- **Key Formulas**:  
  - **Pythagorean Theorem**: $a^2 + b^2 = c^2$ (right triangles).  
  - **Heron’s Formula**: Area = $\sqrt{s(s-a)(s-b)(s-c)}$, $s = \frac{a+b+c}{2}$.  
  - **Law of Cosines**: $c^2 = a^2 + b^2 - 2ab\cos C$.  
- **Triangle Centers**:  
  - **Centroid**: $(\frac{x_1+x_2+x_3}{3}, \frac{y_1+y_2+y_3}{3})$.  
  - **Circumradius**: $R = \frac{abc}{4 \cdot \text{Area}}$.  

---

## Area, Perimeter, Volume & Surface Area  

### 2.4 Area & Volume  
- **2D Shapes**:  
  | Shape       | Area Formula                          | Perimeter Formula       |  
  |-------------|---------------------------------------|-------------------------|  
  | **Circle**  | $\pi r^2$                           | $2\pi r$                |  
  | **Sector**  | $\frac{1}{2} r^2 \theta$ (θ in rad) | $r\theta + 2r$          |  
  | **Polygon** | Shoelace formula                      | Sum of side lengths     |  

- **3D Shapes**:  
  | Shape         | Volume Formula                     | Surface Area Formula         |  
  |---------------|------------------------------------|-------------------------------|  
  | **Sphere**    | $\frac{4}{3}\pi r^3$               | $4\pi r^2$                    |  
  | **Cone**      | $\frac{1}{3}\pi r^2 h$             | $\pi r(r + l)$ (l = slant height) |  
  | **Cylinder**  | $\pi r^2 h$                        | $2\pi r(h + r)$               |  

- **Shoelace Formula**:  
  $$  
  \text{Area} = \frac{1}{2} \left| \sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i) \right|  
  $$  

---

## Parametric Equations  

### 2.5 Parametric Equations  
- **Line (Parametric)**:  
  $$(x, y) = (x_0 + t \cdot dx, y_0 + t \cdot dy)$$  
  (Use for ray casting or motion simulations.)  
- **Circle (Parametric)**:  
  $$x = r \cos\theta + x_c, \quad y = r \sin\theta + y_c$$  
  (For generating points on a circle.)  

---

## Edge Cases & Tips  

### 2.6 Edge Cases & Tips  
- **Common Pitfalls**:  
  - **Division by Zero**: Check for vertical lines in slope calculations.  
  - **Precision Errors**: Use `EPS = 1e-9` for floating-point comparisons.  
  - **Polygon Ordering**: Ensure vertices are ordered (clockwise/counter-clockwise) for Shoelace formula.  
- **Efficiency Hacks**:  
  - **Precompute Trigonometric Values**: Avoid repeated `sin/cos` calls in loops.  
  - **Use Cross Products**: For orientation checks (convex hulls, polygon area).  

---

## Example Code: Coordinate Conversion  
```cpp  
struct Point3D {  
    double x, y, z;  
};  

Point3D spherical_to_cartesian(double r, double theta, double phi) {  
    return {  
        r * sin(phi) * cos(theta),  
        r * sin(phi) * sin(theta),  
        r * cos(phi)  
    };  
}  
```  
