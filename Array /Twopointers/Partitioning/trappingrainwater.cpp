#include<iostream>
#include<vector>
using namespace std;
 int trap(vector<int>& height) {
        //Method 1 - Brute force mein jis jagah par khra hu us jagah se left or right ko check krunga jo jitna jada height par hoga us hisab se paani ka level tay hoga

        // int total_water = 0;
        // for(int i = 0; i < height.size(); i++){

        //     //go to find left_max 
        //     int left_max = 0;
        //     for(int j = i ; j >= 0; j--) left_max = max(left_max,height[j]);

        //     //go to find right_max
        //     int right_max = 0;
        //     for(int k = i; k < height.size(); k++) right_max = max(right_max,height[k]);

        //     //calculate water 
        //     total_water += min(left_max,right_max) - height[i];
        // }
        // return total_water;

        //Method 2 - Ab mein precomputation technique chlata hu or store hi krta jata hu chizo ko
        // int n = height.size();
        // vector<int> prefixsum(n);
        // prefixsum[0] = height[0];
        // for(int i = 1; i < n ; i++) prefixsum[i] = max(prefixsum[i-1],height[i]);
        // vector<int> suffixsum(n);
        // suffixsum[n-1] = height[n-1];
        // for(int i = n-2; i >= 0 ; i--) suffixsum[i] = max(suffixsum[i+1],height[i]);
        
        // int total_water = 0;
        // for(int i = 0; i < height.size(); i++)
        //     total_water += min(prefixsum[i],suffixsum[i]) - height[i];

        // return total_water;

        //Method 3 - Two pointers
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;
        while( left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= left_max) left_max = height[left];
                else total_water += left_max - height[left];
                left++;
            }
            else{
                if(height[right] >= right_max) right_max = height[right];
                else total_water += right_max - height[right];
                right--;
            }
        }
        return total_water;   
    }
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ;i < n ; i++) cin>>v[i];
    return 0;
}