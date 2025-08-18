#include<iostream>
#include<vector>
using namespace std;
// merge sort is also teach the divide and conquer technique and recursion
//1 case hm solve krenge baaki recursion bhaiya par chod do

//merge sort we divide the array in 2 parts how we divide mid = ( s + e )/2;
//Step 1  -  divide the array
//Step 2  -  recursion bhaiya
//Step 3  -  merge2sortedarray
//Dividde and conquer means phoot daalo or raaj kro

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Array length + left array + right array + actual merge n time
// T(n) = k1 + T(n/2)+ T(n/2) + n * k;
// merge krna ka time n ka multiple ka hi kuch lg rah to n * k 
// T(n) = k1 + 2T(n/2) + n * k;
// 2T(n/2) = 2k1 + 2T(N/4) + n/2*k;
// .......
// .......
// T(1) = k1 + baki left right kt jayega + a * n * k
// T(n) = neglect constant + kt gya  + k neglect * a * n;
// T(n) = (a = logn) *n
// so it is T(n) = nlogN
//Space complexity = O(N);

//Step 1 = break krlo left and right
//Step 2 = recursion lga do
//Step 3 = merge 2 sorted arrays

void merge(vector<int>& v,int s,int e){
    //Now we written the merge logic
    //firstly find the mid of the array according to that we take the decision
    int mid = ( s + e )/2;
    //left side array ki length nikalna ke liye
    int n1 = mid - s + 1;
    //Right side array ki length nikalna ke liye
    int n2 = e - mid;
    
    //create the 2 temporary vector arrays of left and right 
    vector<int> l(n1),r(n2);

    //Now i am divide values into left and right array according to our need
    int k = s;
    for(int i = 0; i < n1 ; i++) l[i] = v[k++];
    k = mid+1;
    for(int j = 0; j < n2 ; j++) r[j] = v[k++];

    //Now i am initialize the i and j pointer with 0 and start moving ahead also taking comparisons of each 
    int i = 0;
    int j = 0;
    k = s;
    while(i < n1 && j < n2){
        if(l[i] < r[j]) v[k++] = l[i++];
        else v[k++] = r[j++];
    }

    while(i < n1) v[k++] = l[i++];
    while(j < n2) v[k++] = r[j++];
}
void mergeSort(vector<int>& v,int s,int e){
    //Step 1 - Base case
    if( s >= e ) return ;


    //Step 2 - follow the recurison rule
    int mid =  s + ( e - s )/2;
    //divide the leftArray 
    mergeSort(v,s,mid);
    //divide the rightArray 
    mergeSort(v,mid+1,e);
    //and lastly we merge the array 
    merge(v,s,e);
}

//quick sort - given an unsorted array 
// 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4
//simply we choose one pivot element such that the elements to the right
//of pivot > a[pivot]
// element left of pivot element < a[pivot]
// we make partition as such as posssible that in the left of pivot all element are 
// small and in the right of the pivot all the larger elements than pivot


//Steps for quickSort :- 
// 1.) Choose the pivotElement
// 2.) Make the partition is like that :- 
//     i.) In the left of pivot all element are less than the pivotElement
//     ii.) and On the Right of pivot all element are greater than the pivotElement

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// quick sort simple and good logic is take one pivot element and in the left of pivot 
// take all small elements and in the right of pivot take larger elements

// array -> 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4

// pivot = end
// 1.) pivot = 7
// 2.) i = start - 1 , j = start;
// 3.) a[pivot] = 4; 


//logic - hr baar mein aarray ke last element ko hi pivot maanunga
//means simply we have logic that ki last element uthao or usko 
//pivot maan kar uska left or right arrange kr do

//New way to do partitioning
// 1.) Always taken last as pivotElement
// 2.) Take two pointers 
// 3.) Take Two pointers i and j 
//       i.) Start i from start-1
//      ii.) Start j from start 

// while(i < pivot)
// if(a[j] >= a[pivot]) j++;
// else i++ swap(a[i],a[j]) j++;

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void quickSort(vector<int>& v, int s,int e){
    //base case
    if(s >= e) return ;

    //3 steps
    // 1.) Take last element as pivot 
    // 2.) start i from start - 1 and j from start take two pointers for partitioning
    // 3.) Start the loop and then check j < pivotIndex if j < pivotIndex 
                // i.) Then if v[j] < v[pivotIndex] i++ swap(v[i],v[j]);
                // ii.) else always add j++

    int i = s - 1;
    int j = s;
    int pivot = e;
    while(j < pivot){
        if(v[j] < v[pivot]) swap(v[++i],v[j]);
        j++;
    }
    i++;
    swap(v[i],v[pivot]);
    quickSort(v,s,i-1);
    quickSort(v,i+1,e);

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++) cin>>v[i];
    // mergeSort(v,0,n-1);
    quickSort(v,0,n-1);
    for(int i = 0; i < n ;i++) cout<<v[i]<<" ";
    return 0;
}