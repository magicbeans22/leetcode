#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
  int i=0;
  for (int j=0; j<n;j++)
    i^=A[j];
  return i; 
}

int main() {
  int a[] = {1, 2, 3, 3, 2};
  int b = singleNumber(a, 5);
  cout << b << endl;  
}
