class MedianFinder {
public:
    priority_queue <int> maxHeap; // upper half of elements
    priority_queue <int, vector <int>, greater <int>> minHeap; // lower half of elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        int size = minHeap.size() + maxHeap.size();
        if(size&1) return minHeap.top()*1.0;
        else return (minHeap.top() + maxHeap.top())*1.0/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */