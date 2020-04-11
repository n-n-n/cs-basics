class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find a pivot.
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        int l = 0;
        int r = nums.size() - 1;
        while(l + 1 < r and nums[l] > nums[r]) {
  
            int m = (r - l) / 2 + l;
            int v = nums[m];
            if (v == target) return m;
            if (nums[l] < v) {
                if (nums[l] <= target and target < v) {
                    r = m - 1;
                    break; // optional nums[l] <= nums[r]
                } else {
                    l = m + 1;
                }
            } else {
                if (v < target and target <= nums[r]) {
                    l = m + 1;
                    break; // optional  nums[l] <= nums[r] 
                } else {
                    r = m - 1;
                }
            }
        }
        // I did not understand the following boundary checking is needed....
        if (r - l == 1) {
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            return -1;
        }      
            
        while (l <= r) {
            int m = (r - l) / 2 + l;
            int v = nums[m];
            if (v == target) return m;
            if (target < nums[m]) {
                r = m - 1;
            } else {
               l = m + 1;
           }
        }
        return -1;
    }
};
