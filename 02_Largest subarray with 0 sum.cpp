/*Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mapp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(mapp.find(sum) != mapp.end()){
                    maxi=max(maxi,i-mapp[sum]);
                }
                else{
                    mapp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
