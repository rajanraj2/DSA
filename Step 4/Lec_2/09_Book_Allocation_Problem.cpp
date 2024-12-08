// https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM
// Allocate books


bool possible(vector<int>& arr, int n, int mid, int m) {
    int val = 0, count = 1;
    for (int i = 0; i < n; i++) {
        if (val + arr[i] <= mid) val += arr[i];
        else {
            count++;
            val = arr[i];
        }
    }
    if (count > m) return false;
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (n < m) return -1;
    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (possible(arr, n, mid, m)) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}