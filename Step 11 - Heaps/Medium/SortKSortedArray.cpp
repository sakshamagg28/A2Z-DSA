void nearlySorted(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;

    // Push first k+1 elements
    for (; i <= k && i < arr.size(); i++)
        pq.push(arr[i]);

    int idx = 0;

    while (i < arr.size()) {
        arr[idx++] = pq.top();
        pq.pop();

        pq.push(arr[i++]);
    }

    while (!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
}