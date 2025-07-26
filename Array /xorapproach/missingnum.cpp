#include<iostream>
#include<vector>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" ";
}
int missingnumber(vector<int>& arr){
    int n = arr.size();
//  Method 1 = brute force find missing number in the range [1,n]
//  for each integer , try to find it in the given array 
//  we take use of flag that element is present or not
// initially set flag = 0 whlie iterating flag = 1 break the loop
//Time complexity - O(N^2)
//Space complexity - O(1)
// int n = arr.size();
//  for(int i = 1; i <= n;i++){
//     bool flag = 0;
//     for(int j = 0 ;j < n ;j++){
//         if(i == arr[j]) flag = 1;
//         if(flag == 1) break;
//     }
//     if(flag == 0) return i;
// }
// return n+1;

//Method 2 - brute force in another way 
//Time complexity - O(Nlogn + N)
//Space complexity - O(1)
// sort(arr.begin(),arr.end());
// for(int i = 0; i < n ;i++ ) if(arr[i] != i+1) return i+1;
// return n+1;


//Method 3 - Better Appraoch Use hashmap
// we count the element using hashmap and where wee find no count we simply return it;
    // vector<int> freq(n+1,0); 
    //by unordered map 
    // unordered_map<int,int> freq;
    // for(int i = 0; i < n ;i++) freq[arr[i]]++;
    // for(int i = 1; i <= n;i++) if(freq[i] == 0) return i;
    // return n+1; 

//Method 4 - Optimal Appraoch 
// sum approach i find the total sum of n natural numbers and then i found array sum 
// then i subtract the resultant is my ans;
//Time complexity - O(N)
//Space complexity - O(1)
    // int tsum = ( n * (n + 1))/2;
    // int sum = 0;
    // for(int i = 0; i < n ;i++){
    //     sum += arr[i];
    // }
    // return abs(tsum - sum);


//Method 5 - More best Optimal Approach 
// i xor all of the array members in the array itself 
// and then i xor with their index and which is not present return it
// int ans = 0;
// for(int i = 0; i < n ;i++) ans = ans ^ arr[i] ^ i+1;

// return ans ^ n+1;

int ans = 0;
for(int i = 0; i < n ;i++) ans ^= arr[i];
for(int i = 1; i <= n ;i++) ans ^= i;
return ans ^ n+1;



}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    cout<<missingnumber(arr)<<endl;
    outputarr(arr);
    return 0;
}

