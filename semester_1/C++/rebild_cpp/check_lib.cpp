#include <iostream>
#include "sortings.hpp"
#include "split.hpp"

int main(){
    int arr[] = {1, 564542, 1321, 989, 15, 653212, 265, 44, 5, 2, 12, 4, 12, 3, 98, 74,  55, 8, 22, 58, 8};
    int len = sizeof(arr)/sizeof(int);

    std::cout << "Unsorted array:";
    for(int i = 0; i < len; i++){
        std::cout << " " << arr[i] ;
    }
    std::cout << std::endl;

    Quick_sort(arr, len);
    std::cout << "Quick sort:";
    for(int i = 0; i < len; i++){
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    int arr1[] = {1, 564542, 1321, 989, 15, 653212, 265, 44, 5, 2, 12, 4, 12, 3, 98, 74,  55, 8, 22, 58, 8};
    Merge_sort(arr1, len);
    std::cout << "Merge sort:";
    for(int i = 0; i < len; i++){
        std::cout << " " << arr1[i] ;
    }
    std::cout << std::endl;

    std::string text = "65446546.464646!6844686 66468";
    std::string septs = ",. !";
    int amnt_of_tokens = Count_tokens(text, septs);
    std::cout << "Amount of tokens: "<< amnt_of_tokens;
}