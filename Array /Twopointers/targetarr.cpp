#include<iostream>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        //Method 1 - nested loops
        // vector<int> ans;
        // for(int i = 0; i < nums.size();i++){
        //     for(int j = i+1; j < nums.size();j++){
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //Method 2 - The hashmap method 
       unordered_map<int,int>  mpp;
       for(int i = 0; i < nums.size();i++){
       int curr_num = nums[i];
       int req_sum = target - curr_num;

       if(mpp.find(req_sum) != mpp.end()) return {mpp[req_sum] + 1, i + 1};
       
       mpp[curr_num] = i;
    }
    return {};


        //Method 3 - Two pointers
        // vector<int> ans;//To store the ans index array 
        // int left = 0;
        // int right = nums.size()-1;
        // while(left < right){
        //     if((nums[left] + nums[right]) == target){
        //         ans.push_back(left+1);
        //         ans.push_back(right+1);
        //         break;
        //     }
        //     else if((nums[left] + nums[right]) < target) left++;
        //     else right--;
        // }
        // return ans;

    }
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ;i++) cin>>v[i];
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    for(auto it : twoSum(v,target)) cout<<it<<" ";
    for(int i = 0; i < n ;i++) cout<<v[i]<<" ";
    return 0;
}