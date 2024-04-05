#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int cnt = 0;
        int left = low;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (arr[i] > 2LL*arr[right])) right++;
            cnt += (right - (mid + 1));
        }
        // while (left <= mid && right <= high) {
        //     if (arr[left] > 2LL * arr[right]) {
        //         cnt += (mid - left + 1); // Increment count by the number of elements from left to mid
        //         right++; // Move the right pointer
        //     } else {
        //         left++; // Move the left pointer
        //     }
        // }
       
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt =  0;
        if (low >= high) return 0;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += countPairs(arr, low,  mid, high);
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << s.reversePairs(nums) << endl;
    return 0;
}