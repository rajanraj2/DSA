// Link - https://www.interviewbit.com/problems/nearest-smaller-element/
// Nearest Smaller Element


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        
        result[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    
    return result;
}
