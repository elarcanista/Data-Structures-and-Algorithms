#include <bits/stdc++.h>
using namespace std;

//Bijective function from N^2 to N
long long cantorPairing(long long k1, long long k2){
  return (k1+k2)*(k1+k2+1)/2+k2;
}

//Bijective function from N^n to N
long long cantorPairing(vector<long long> &v){
  long long kn = v.back();
  v.pop_back();
  if(v.empty())
    return kn;
  if(v.size() == 1)
    return cantorPairing(v[0], kn);
  return cantorPairing(cantorPairing(v), kn);
}

//returns the gcd between 2 numbers (greatest c such that c|a ^ c|b)
int gcd(int a, int b){
  if(!b) return a;
  return gcd(b, a%b);
}

//returns 2 numbers x and y such that a*x + b*y = gdc(a, b).
//Can be used to find the multiplicative inverse of b mod a (a and b coprimes)
pair<int, int> extendedEuclid(int a, int b){
  int s1 = 0, s2 = 1, t1 = 1, t2 = 0, r2 = a, r1 = b;
  while(r1){
    int q = r2/r1;
    int rtemp = r2 - q*r1;
    r2 = r1;
    r1 = rtemp;
    int stemp = s2 - q*s1;
    s2 = s1;
    s1 = stemp;
    int ttemp = t2 - q*t1;
    t2 = t1;
    t1 = ttemp;
  }
  return {s2, t2};
}
