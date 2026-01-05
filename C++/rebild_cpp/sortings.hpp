#ifndef SORTINGS_HPP
#define SORTINGS_HPP

#include <random>
#include <algorithm>

namespace {
    inline int Separation(int *arr, int left, int right){
        static thread_local std::random_device rd;
        static thread_local std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(left, right);
        int pivot_index = dis(gen);
        int pivot_value = arr[pivot_index];
        int i = left - 1, j = left;
        std::swap(arr[pivot_index], arr[right]);
        while(j <= right){
            if(arr[j] <= pivot_value){
                std::swap(arr[++i], arr[j++]);
            } else {
                ++j;
            }
        }
        return i;
    }
    inline void Merge(int *arr, int left, int mid, int right){
        int *temp = new int[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= right) temp[k++] = arr[j++];
        for(int i = 0; i < k; i++){
            arr[left + i] = temp [i];
        }
        delete[] temp;
    }
}

inline void Quick_sort(int *arr, int left, int right){
    if(left >= right) return;
    int pivot_pos = Separation(arr, left, right);
    Quick_sort(arr, left, pivot_pos - 1);
    Quick_sort(arr, pivot_pos + 1, right);
}

inline void Quick_sort(int *arr, int len){
    if(len <= 1) return;
    int left = 0, right = len - 1;
    Quick_sort(arr, left, right);
}

inline void Merge_sort(int *arr, int left, int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    Merge_sort(arr, left, mid);
    Merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

inline void Merge_sort(int *arr, int len){
    if(len <= 1) return;
    int left = 0, right = len - 1;
    Merge_sort(arr, left, right);
}

#endif