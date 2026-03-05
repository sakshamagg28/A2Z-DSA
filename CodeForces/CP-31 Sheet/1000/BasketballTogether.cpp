#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, D;
    cin >> N >> D;
    vector<int> power(N);
    for (int i=0; i<N; i++){
        cin >> power[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < N; i++){
        minHeap.push(power[i]);
        maxHeap.push(power[i]);
    }

    int numCount = 0;
    int numWins = 0;

    while (numCount < N && !maxHeap.empty()){
        int maxNum = maxHeap.top();
        maxHeap.pop();
        int numEle = D/maxNum + 1;

        for (int i = 1; i < numEle; i++){
            if (!minHeap.empty())
                minHeap.pop();
        }

        if (numCount + numEle <= N){
            numWins++;
            numCount += numEle;
        }
        else break;
    }
    cout << numWins << endl;
    return 0;
}