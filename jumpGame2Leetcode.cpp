Solution 1 : O(length * min(maxLenthJump,length))

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return 0;
            
        vector<int> vis(n,INT_MAX);
        vis[0] = 0;
        for(int i=0;i<n-1;i++)
        {
            if(vis[i]!=INT_MAX)
            {
                int r = min(n-1,i+nums[i]);
                for(int j=i+1;j<=r;j++)
                {
                    vis[j] = min(vis[i]+1,vis[j]);
                }
            }
        }
        
        return vis[n-1];
    }
};



Solution 2 : O(N=length of the nums array)
  
  class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)            // you are already at the final position and you didn't need to jump.
            return 0;  
        
        vector<int> minJump(n,INT_MAX);
        minJump[0] = 0; // you are at the first position 
        int curr = 0; // you already evaluate the answer for till this curr position. minJump required to reach till this curr position
        for(int i=0;i<n-1;i++)
        {
            if(minJump[i]!=INT_MAX)         // is it possible to jump from this position.
            {
                int r = min(i + nums[i],n-1);  // maxPosition, you can jump to 
                for(int j=curr+1;j<=r;j++)  // you already know the answer till curr and now you start to evaluate from (curr + 1) th position
                {
                    minJump[j] = minJump[i] + 1;
                }
                curr = max(r,curr);  // which is maximum "curr = you already done with or  r = immediate jump position"
            }
        }
        
        return minJump[n-1];
    }
};
