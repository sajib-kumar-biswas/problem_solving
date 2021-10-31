class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        
        if(n==1)                  // if the nums.length is equal to 1. we are already at the last position.
            return true;
        
        if(nums[0]==0)            /// if length of the array is  greater than 1 and nums[0] is equal to 0. then you can not even jump to the next position.
            return false;
        
        bool ans = true;
        
        for(int i=0;i<n-1;i++)
        {
            if(curr<i)                 /// if value of curr < i  . it means you can not even reach to this i th position. so you can't go further. 
            {
                ans = false;
                break;
            }
            
            curr = max(curr,i+nums[i]);    /// if you are at this line, it means you atleast can come to this i th position. and now you can jump to the (i + nums[i]) th position
                                          /// you are going to pick the best or furthest one.
        }
        
        if(curr>=n-1)
            ans = true;           
        else
            ans = false;
        
        return ans;
    }
};
