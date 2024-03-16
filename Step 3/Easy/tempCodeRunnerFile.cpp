int getSingleElement(vector<int> &arr){
	int result = 0;
    for (int i=0; i<arr.size(); i++) {
        result = result ^ arr[i];
    }
    return result;
}