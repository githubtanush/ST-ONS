#include<iostream>
#include<vector>
using namespace std;
// Sorting - means we make array to increasing order or decreasing order 
// generally sort means sort in increasing order
// -> algorithm depends on basic logic  
// swap the adjacents if needed till we get all the array sorted
// let's consider an array  - 5 | 4 | 3 | 2 | 1

//Step 1 -> 5 | 4 | 3 | 2 | 1
// 1.) 4 | 5 | 3 | 2 | 1
// 2.) 4 | 3 | 5 | 2 | 1
// 3.) 4 | 3 | 2 | 5 | 1
// 4.) 4 | 3 | 2 | 1 | 5 
// number of comparisons = 4
// now we see the last element is sorted this algorithm worked on this 
//logic that at 1st iteration largest element is at rightmost position

//Step 2 ->  4 | 3 | 2 | 1 | 5
// 1.) 3 | 4 | 2 | 1 | 5
// 2.) 3 | 2 | 4 | 1 | 5
// 3.) 3 | 2 | 1 | 4 | 5
//number of comparisons = 3
// now we see the last second element is sorted in this algorithm and make 
// at last second position 

//Step 3 -> 3 | 2 | 1 | 4 | 5
// 1.) 2 | 3 | 1 | 4 | 5
// 2.) 2 | 1 | 3 | 4 | 5
//number of comparisons = 2;
// now we see the last third element is sorted in this algorithm at last 
// third position

//Step 4 -> 2 | 1 | 3 | 4 | 5
// 1.) 1 | 2 | 3 | 4 | 5=
// number of comparisons = 1
// now we see the last fourth element is sorted in this algorithm 
// and all the array is sorted


//means n - 1 iteration mein kaam ho gya

                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration        4                     n-1
// 2nd Iteration        3                     n-2
// 3rd Iteration        2                     n-3
// 4th Iteration        1                       1 comparison

// Sn = n ( n - 1 )/2;
// O(n) = O(n^2 /2 - n /2) => O(N^2) -> Time complexity
//Space complexity - O(1)

//Outerloop -> (n-1)
//Innerloop -> comparisons (n - i - 1)


void bubbleSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1;i++){
        for(int j = 0 ; j < n - i - 1 ; j++ ){
                if(v[j] > v[j+1]) swap(v[j],v[j+1]);
        }
    }
}


// Insertion sort - in general increasing order
// example - take array - 5 | 4 | 3 | 2 | 1
// In insertion sort let us we ignore the 5 assume 5 is already sorted
// and starting sorting from 4
// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Steps in insertion sort
// array -> 5 | 4 | 3 | 2 | 1
// Step 1 -> ignore 5 start from 4
//  5 | 4 | 3 | 2 | 1 
// 1.) 4 | 5 | 3 | 2 | 1
// 2.) 3 | 4 | 5 | 2 | 1
// 3.) 2 | 3 | 4 | 5 | 1
// 4.) 1 | 2 | 3 | 4 | 5

// i = 1 , key = v[i] => key = 4
// variable j = i - 1 while(j>=0 && v[j] > key) v[j+1] = v[j] j--;
// v[j+1] = key

// i = 2 , key = v[i]

// i = 0 kuch nhi krna 
// i = 1 to n - 1
// j = i - 1 to j >= 0


                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration        1                     1
// 2nd Iteration        2                     2
// 3rd Iteration        3                     3
// 4th Iteration        4                     n-1 comparison

// Sn = n ( n - 1 )/2 => O(n^2/2 - n/2) => O(n^2)
//Time complexity - O(N^2) and space complexity - O(1)
// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void insertionSort(vector<int>& v){
    int n = v.size();
    for(int i = 1; i < n ; i++){
        int key = v[i];
        int j = i - 1;
        while(j>=0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key; //placed key 
    }
}

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Selection sort - what if , i select the minimum element and 
// put it at the right position
// in general sorting in ascending order


// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// array -> 44 | 33 | 55 | 22 | 11
// Step 1 -> 44 | 33 | 55 | 22 | 11
// select the minimum element - 11 and place it at their right position
// 1.) 11 | 33 | 55 | 22 | 44
// 2.) 11 | 22 | 55 | 33 | 44 
// 3.) 11 | 22 | 33 | 55 | 44
// 4.) 11 | 22 | 33 | 44 | 55

// for ith iteration , pick smallest element from i to n - 1 index 
// and swap it with ith element

// i -> 0 to n - 1


                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration(i=0)       4                     n-1
// 2nd Iteration(i=1)       3                     n-2
// 3rd Iteration(i=2)       2                     n-3
// 4th Iteration(i=3)       1                     1 comparison

// outerloop -> n - 1 times;
// innerloop -> n - 1 times;
// Sn = n ( n - 1 )/2 => O(N^2)

//Time complexity - O(N^2) and space complexity - O(1)

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void selectionSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n-1 ; i++){
        int minIndex = i ; //ith element hi smallest element hai 
        for(int j = i + 1; j < n ;j++){
            if(v[j] < v[minIndex]) minIndex = j;
        }
        //swap the ith element with minIndex element 
        swap(v[i],v[minIndex]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    // bubbleSort(arr);
    // insertionSort(arr);
    selectionSort(arr);
    for(int i = 0; i < n ;i++) cout<<arr[i]<<" ";
    return 0;
}