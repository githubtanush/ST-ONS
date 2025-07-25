#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" ";
}
int removeduplicate(vector<int>& arr){
    //Brute force - i can take set in set the main benefit is that 
    // i store the different elements in the set
    //Time complexity - O(Nlogn + N) Nlogn = insertion + N traversal
    //Space complexity - O(N) as set is same as size of array
    // set<int> st;
    // for(int i = 0; i < arr.size();i++) st.insert(arr[i]);
    // int index = 0;
    // for(auto i : st) arr[index++] = i;
    // return index;

    //Method 2 - Use Hashmap to count the frequency of the array and then if freq == 1 push into array else remove it
    //Time complexity - O(Nlogn + 2k)
    //Space complexity - O(k) 
    //Step 1 - declare map
    // map<int,int> mp;
    // //Step 2 - count frequencies in map
    // for(int i = 0; i < arr.size();i++) 
    // // {
    // //     if(mp[arr[i]] == 0)
    //     mp[arr[i]]++;
    // // }
    // //Step 3 - push into array 
    // int index = 0;
    // for(auto i : mp){
    //     if(i.second > 0){
    //     arr[index++] = i.first;
    //     i.second = 0;
    //     }
    // }
    // return index;

    //Method 3 - Two pointers
    //Use two pointers effectively when i found the same then simply iterate j else iterate i and insert arr[j]
    // at place of arr[i] then move j then simply return it 
//     int i = 0;
//     int j = 1;
//     while(j < arr.size()){
//         if(arr[i] == arr[j]) j++;
//         else {
//             //arr[i] != arr[j]
//             i++;
//             arr[i] = arr[j];
//             j++;
//         }
//     }
// return i+1;

    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    cout<<removeduplicate(arr)<<endl;
    outputarr(arr);
    return 0;
}
