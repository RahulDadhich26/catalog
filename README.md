# Hashira Placements Assignment - Polynomial Reconstruction

## Problem Overview
This assignment involves reconstructing a polynomial from given points using Lagrange interpolation to find the constant term (secret) in Shamir's Secret Sharing scheme.

## Algorithm Used
**Lagrange Interpolation** - Mathematical method to reconstruct a polynomial of degree m using m+1 points.

## Solution Approach

### Step 1: Base Conversion
- Convert values from different bases (2, 3, 6, 8, 10, 15, 16) to decimal
- Handle both numeric and alphabetic characters for bases > 10

### Step 2: Point Extraction
- Extract (x, y) coordinates from JSON test cases
- x = key number, y = converted decimal value

### Step 3: Lagrange Interpolation
- Use first k points to reconstruct polynomial
- Calculate f(0) using formula: f(0) = Σ(yi × Π((0-xj)/(xi-xj))) for i≠j
- f(0) gives us the constant term (secret)

## Code Structure

```cpp
convertToDecimal()        // Base conversion function
lagrangeInterpolation()   // Main algorithm implementation
main()                    // Test case execution
```

## Test Cases & Results

### Test Case 1:
```json
{
    "keys": {"n": 4, "k": 3},
    "1": {"base": "10", "value": "4"},
    "2": {"base": "2", "value": "111"},
    "3": {"base": "10", "value": "12"},
    "6": {"base": "4", "value": "213"}
}
```
**Output:** `3`

### Test Case 2:
```json
{
    "keys": {"n": 10, "k": 7},
    "1": {"base": "6", "value": "13444211440455345511"},
    "2": {"base": "15", "value": "aed7015a346d635"},
    // ... more points
}
```
**Output:** `-346065875551169830`

## How to Run

### Prerequisites
- C++ compiler (g++)
- Any C++ IDE (VS Code recommended)

### Compilation & Execution
```bash
g++ -o solution solution.cpp
./solution
```

### Using VS Code
1. Install C++ extension
2. Open `solution.cpp`
3. Press `Ctrl + Alt + N` (with Code Runner extension)

## Program Output
```
Test Case 1:
Constant term (secret): 3

Test Case 2:
Constant term (secret): -346065875551169830
```

## **🏆 FINAL ANSWERS:**
- **Test Case 1:** `3`
- **Test Case 2:** `-346065875551169830`

## Key Features
- Handles multiple number bases (2-16)
- Robust error handling for invalid characters
- Efficient Lagrange interpolation implementation
- Clean, readable C++ code structure

## Verification
**Test Case 1 Manual Check:**
- Points: (1,4), (2,7), (3,12)
- Reconstructed polynomial: f(x) = x² + 3
- Verification: f(1)=4 ✓, f(2)=7 ✓, f(3)=12 ✓
- Secret (constant term): 3 ✓

## Time Complexity
- Base conversion: O(d) where d is number of digits
- Lagrange interpolation: O(k²) where k is number of points
- Overall: O(k² + nd) where n is total points

## Assignment Requirements Met
- ✅ Language: C++ (not Python)
- ✅ Duration: Completed within 45 mins
- ✅ JSON input parsing
- ✅ Multiple test cases handled
- ✅ Correct mathematical implementation
- ✅ Working code with proper output

---

**Author:** [Your Name]  
**Assignment:** Hashira Placements - Online Assessment  
**Date:** September 2025
