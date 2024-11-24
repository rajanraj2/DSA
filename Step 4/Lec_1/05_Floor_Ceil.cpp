// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM
// Ceil the Floor


pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
	pair<int, int> result = {-1, -1};
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] <= x) {
			result.first = arr[mid];
			left = mid + 1;
		}
		else right = mid - 1;
	}
	left = 0;
	right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] >= x) {
			result.second = arr[mid];
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return result;
}