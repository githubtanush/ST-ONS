#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i];
}

int secondlargest(vector<int>& arr){
    //brute - sort and last second print
    //time complexity - O(nlogn)
    //space complexity - O(1)
    // sort(arr.begin(),arr.end());
    // int largest = arr[arr.size()-1];
    // int slargest = -1;
    // for(int i = arr.size()-2; i>=0 ;i--){
    //     if(arr[i] != largest) {
    //         slargest = arr[i];
    //         break;
    //     }
    // }
    // return slargest;

    //but wait if there is duplicates if not found the second largest there is 2 largest 
    //at last 2 places of array then 
    //better approach - we first find largest then find second largest with 2 loops 
    // so time complexity - O(N+N) = O(2N)
    // int largest = INT_MIN;
    // int slargest = INT_MIN;
    // for(int i = 0;i < arr.size();i++) if(arr[i] > largest) largest = arr[i];
    // for(int i = 0; i < arr.size();i++) if(arr[i] > slargest && largest != arr[i]) slargest = arr[i];
    // return slargest;


    //3rd appraoch - we can say that we find largest as well as simultaneously we find the second largest element 
    // means we find both the elements simultaneously 
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i = 1; i < arr.size();i++){
       if(arr[i] > largest) largest = arr[i];
       else if(arr[i]< largest && arr[i] > slargest) slargest = arr[i];
    }
    return slargest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    cout<<secondlargest(arr)<<endl;
    return 0;
}