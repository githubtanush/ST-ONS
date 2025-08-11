#include<iostream>
#include<vector>
#include<limits>
using namespace std;
    int maxArea(vector<int>& height) {
        //Method 1 - The brute force
        // int maxArea = INT_MIN;
        // for(int i = 0; i < height.size();i++){
        //     for(int j = i+1; j < height.size();j++){
        //         maxArea = max(maxArea,min(height[j],height[i]) * (j - i));
        //     }
        // }
        // return maxArea;

        //Method2 - The optimal approach 
        int left = 0;
        int right = height.size()-1;
        int maxArea = INT_MIN;
        while(left < right){
            maxArea = max(maxArea,min(height[left],height[right])* ( right - left ));
            if(height[left] < height[right]) left++;
            else right--;    
        }
        return maxArea;
    }
int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i = 0; i < n ;i++) cin>>height[i];
    cout<<maxArea(height);
    return 0;
}