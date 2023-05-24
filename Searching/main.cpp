#include <iostream>
using namespace std;

class LinearSearch{
public:
    int search(int arr[], int sizeOfArr, int target){
        if(arr[sizeOfArr-1]==target){
            return sizeOfArr-1;
        }else{
            return search(arr, sizeOfArr-1, target );
        }
    }
};

class BinarySearch{
public:
    int search(int arr[], int firstIndex, int lastIndex, int target){
        int mid;
        if(lastIndex>=firstIndex){
            mid= firstIndex + (lastIndex-firstIndex)/2 ;
            if(arr[mid]== target){
                return mid;
            }
            if(arr[mid]>target){
                return search(arr, firstIndex, mid-1, target);
            }
         return search(arr, mid+1, lastIndex, target);
        }
        return -1;
    }
};

void printResult(int pos,int target, string searchName){
    if(pos==-1){
        cout<<"Not Found";
    }
    else{
        cout<<"By "<<searchName <<" the number "<<target <<" found at position: "<< pos << endl;
    }
}

int main(){
    int pos;
    int arr[] = {8,3,6,5,1,9,2,7};
    int sortedArr[] = {1,2,3,4,5,6,7,8,9};
    int target = 6;
    int sizeOfSortedArr = sizeof(sortedArr)/sizeof(sortedArr[0]);
    int n = sizeof(arr)/sizeof(arr[0]);
    
    LinearSearch linearSearch;
    BinarySearch binarySearch;
    
    pos = linearSearch.search(arr,n, target);
    printResult(pos, target, "Linear Search");
    
    pos = binarySearch.search(sortedArr, 0, sizeOfSortedArr-1, target);
    printResult(pos, target, "Binary Search");
   
}

