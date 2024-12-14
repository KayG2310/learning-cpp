// nlogn
class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size()==0 || num <= left.top()){
            left.push(num);
            // return;
        }
        else right.push(num);

        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        else if(left.size() -1 > right.size()){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        int tot = left.size()+right.size();
        if(tot % 2) return left.top();
        return ((double)left.top()+(double) right.top())/2.0;
    }
private:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */ 
