class MedianFinder {
public:
    priority_queue <int> minHeap; // upper half of elements
    priority_queue <int, vector <int>, greater <int>> maxHeap; // lower half of elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int size = maxHeap.size() + minHeap.size();
        if(size&1) return maxHeap.top()*1.0;
        else return (maxHeap.top() + minHeap.top())*1.0/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */