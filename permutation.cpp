//File Name: permutation.cpp
//Author: Waryam Mazhar Editted
//Student ID: D338N574
//Assignment Number: 6
//Description: Use Recursion to find permutation of set of numbers

#include <iostream>
void enumerate(int arr[]);

int main(){

    int arr[5] = {1,2,3,4,5};

    enumerate(arr);

    return 0;
}

bool isConsistent(int arr[], int n){ //function that checks if placement of number valid
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[n]){ //checks, conflicting in same column
            return false;
        }
    }
    return true; //not conflicting then place number
}

void printPermutation(int arr[],int n){ //print each valid set of 5

    int arr2[120]; //create array to hold total number of permutation
    int a, b = 1;

    for(int i = 1; i <= 1;i++){
        a += b; //each time recursion add one
        arr2[i] = a; //place data into array
    }
    std::cout << "P#" << arr2[1] << ": ";

    for(int j = 0; j < n; j++){ //loop that prints all five numbers as permutation
        std::cout << arr[j] << " ";
    }
    std::cout  << "\n";
}

void enumerate(int arr[], int k){ //backtracking for all the permuations,helper function
    if(k == 5){ //once there is five in set
        printPermutation(arr,5); //call print function if full
    }
    else{
        for(int i = 1; i <= 5; i++){
            arr[k] = i;
            if(isConsistent(arr,k)){ //numbers are in valid spot
                enumerate(arr,k+1); //calling own function, recursion, backtracking
            }
        }
    }
}

void enumerate(int arr[]){
    enumerate(arr,0);
}
