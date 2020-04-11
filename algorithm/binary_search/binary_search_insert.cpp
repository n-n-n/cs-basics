#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int lo = -1; // allow boundary
  int hi = nums.size(); // allow baoundary
  while(lo + 1 < hi) {
    int m = (hi + lo) / 2;
    //cout << lo << '-' << hi <<  " (" << m << ')' << endl;
    if (target == nums[m]) {
      return m;
    } else if (target < nums[m]) {
      hi = m;
    } else {
      lo = m;
    }
  }
  return hi;                   
}
