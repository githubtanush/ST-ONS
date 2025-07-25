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
void rotatearr(vector<int>& arr,int k){
    int n = arr.size();
    //Method 1 - make one extra temporary array of size k 
    //then put the extra rotating elements into that array 
    //firstly bound the k with the boundary 
    //Time complexity - O(N + 2k)
    //Space complexity - O(k)
    // k = k % n;
    
    // vector<int> temp(k);
    // for(int i = 0; i < k; i++) temp[i] = arr[n - i - 1];
    // for(int i = n - 1; i>=0;i--) arr[i] = arr[i-k];
    // for(int i = 0; i < k;i++) arr[i] = temp[k-i-1];

    // vector<int> temp(k);
    // for(int i = 0; i < k ; i++) temp[i] = arr[i];
    // for(int i = n - 1 ; i >= 0 ; i--) arr[i-k] = arr[i];
    // for(int i = 0; i < k ; i++) arr[n-k+i] = temp[i];


    //Method 2 - Using Modulus
    //Again we do modularization to set in the bound 
    //so to set in the boundary then to arrange it in boundary we use modulization
    //Time complexity - O(N)
    //Space complexity - O(N)
    // vector<int> ans(n);
    // for(int i = 0; i < n ;i++){
    //     int index = (i + k) % n;
    //     ans[index] = arr[i];
    // }
    // arr = ans;


    //Method 3 -> optimal approach 
    // k = k % n;
    // reverse(arr.begin(),arr.end());
    // reverse(arr.begin(),arr.begin()+k);
    // reverse(arr.begin()+k,arr.end());

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    inputarr(arr);
    int k;
    cout<<"How many times you want to rotate : ";
    cin>>k;

    rotatearr(arr,k);

    outputarr(arr);
    
    return 0;
}
