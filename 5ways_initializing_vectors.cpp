
#include <bits/stdc++.h>
using namespace std;
// initializing a vector in C++

// 1. initializing one by one by pushing values
vector<int> vect;

vec.push_back(10);
vec.push_back(20);

// 2. specifying size and initializing all values:
// create a vector of size n with all values as 10
vector<int> vect(n, 10); 

// 3. initializing like arrays:
vector<int> vect{10, 20, 30};

// 4. initializing from array
int arr[] = {10,20,30};
int n = sizeof(arr) / sizeof(arr[0]);

// 5. initializing from another vector:
vector<int> vect1{10, 20, 30};
vector<int> vect2(vect1.begin(), vect1.end());


