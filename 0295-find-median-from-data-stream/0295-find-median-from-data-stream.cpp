class MedianFinder {
public:
    priority_queue<int>
        left; // ak mx heap jisme sabhi ele right bale se chhote honge
    priority_queue<int, vector<int>, greater<int>>
        right; // min heap jisme sabhi ele left se bade honge
    MedianFinder() {}

    void addNum(int num) {
        if (left.size() == 0) { // left khali h to 
            left.push(num);
            return;
        }
        if (num < left.top()) { // num left k top se chhota h to left 
            left.push(num);
            if (left.size() - right.size() > 1) { // agr size diff >1 to 
                right.push(left.top()); // left se ak value right m shift kr do 
                left.pop(); // aur left se pop kr do 
            }
        } else { // agr num left top se bada y equal h 
            right.push(num); // right m push kia
            if (right.size() - left.size() > 1) { // agr size diff grtr then 1 to
                left.push(right.top()); // right k top ko left m shift kr do 
                right.pop(); // right se pop kr do
            }
        }
        return;
    }

    double findMedian() {
        if(left.size()==right.size()){ // agr size equal h to dono k top k avg hi mean hoga 
            return (left.top()+right.top())/2.0; // bcz mean indx se chhote value ko left heap and grte value right heap m hongi aur mean valu inke top pr 
        }
        if(left.size()>right.size()){ // left hi mean value ko hold kr rha h 
            return left.top(); // mean value se chhote value left heap m aur badi right heap m honge 
        }else{ // same here 
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */