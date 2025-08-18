#include<iostream>
#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
        //Method 1 - The brute force
        // for(int i = 0; i < nums.size();i++) nums[i] *= nums[i];
        // sort(nums.begin(),nums.end());
        // return nums;

        //Method 2 - The optimal one
       int left = 0;
       int right = nums.size()-1;
       int k = nums.size()-1;
       vector<int> result(nums.size(),0);
       while(left <= right){
        if(abs(nums[left]) > abs(nums[right])){
            result[k--] = nums[left] * nums[left];
            left++;
        }
        else {
            result[k--] = nums[right] * nums[right];
            right--;
        }
       }
       return result;
    }
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n ; i++) cin>>nums[i];
    for(auto it : sortedSquares(nums)) cout<<it<<" ";
    return 0;
}
