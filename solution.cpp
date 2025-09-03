#include <bits/stdc++.h>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Convert from any base to decimal
long long convertToDecimal(const string &value, int base) {
  long long result = 0;
  long long power = 1;

  for (int i = value.length() - 1; i >= 0; i--) {
    int digit = 0; // Initialize to 0
    if (value[i] >= '0' && value[i] <= '9') {
      digit = value[i] - '0';
    } else if (value[i] >= 'a' && value[i] <= 'z') {
      digit = value[i] - 'a' + 10;
    } else if (value[i] >= 'A' && value[i] <= 'Z') {
      digit = value[i] - 'A' + 10;
    } else {
      digit = 0; // Default case for invalid characters
    }
    result += digit * power;
    power *= base;
  }
  return result;
}

// Lagrange interpolation to find f(0)
long long
lagrangeInterpolation(const vector<pair<long long, long long>> &points, int k) {
  long long result = 0;

  for (int i = 0; i < k; i++) {
    long long numerator = points[i].second;
    long long denominator = 1;

    for (int j = 0; j < k; j++) {
      if (i != j) {
        numerator *= (0 - points[j].first);
        denominator *= (points[i].first - points[j].first);
      }
    }

    result += numerator / denominator;
  }

  return result;
}

// Simple JSON parser for this specific format
map<string, string> parseJSON(const string &filename) {
  map<string, string> data;
  ifstream file(filename);
  string line;

  while (getline(file, line)) {
    // Remove whitespace and find key-value pairs
    size_t colonPos = line.find(':');
    if (colonPos != string::npos) {
      // Extract key
      string key = line.substr(0, colonPos);
      key.erase(0, key.find_first_not_of(" \t\""));
      key.erase(key.find_last_not_of(" \t\"") + 1);

      // Extract value
      string value = line.substr(colonPos + 1);
      value.erase(0, value.find_first_not_of(" \t\""));
      value.erase(value.find_last_not_of(" \t\",") + 1);

      data[key] = value;
    }
  }

  return data;
}

int main() {
  // Test Case 1
  cout << "Test Case 1:" << endl;

  vector<pair<long long, long long>> points1;

  // Manual input for test case 1
  points1.push_back({1, convertToDecimal("4", 10)});  // (1, 4)
  points1.push_back({2, convertToDecimal("111", 2)}); // (2, 7)
  points1.push_back({3, convertToDecimal("12", 10)}); // (3, 12)

  int k1 = 3;
  long long secret1 = lagrangeInterpolation(points1, k1);
  cout << "Constant term (secret): " << secret1 << endl;

  cout << "\nTest Case 2:" << endl;

  vector<pair<long long, long long>> points2;

  // Manual input for test case 2
  points2.push_back({1, convertToDecimal("13444211440455345511", 6)});
  points2.push_back({2, convertToDecimal("aed7015a346d635", 15)});
  points2.push_back({3, convertToDecimal("6aeeb69631c227c", 15)});
  points2.push_back({4, convertToDecimal("e1b5e05623d881f", 16)});
  points2.push_back({5, convertToDecimal("316034514573652620673", 8)});
  points2.push_back(
      {6, convertToDecimal("2122212201122002221120200210011020220200", 3)});
  points2.push_back(
      {7, convertToDecimal("20120221122211000100210021102001201112121", 3)});

  int k2 = 7;
  long long secret2 = lagrangeInterpolation(points2, k2);
  cout << "Constant term (secret): " << secret2 << endl;

  return 0;
}