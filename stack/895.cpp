class FreqStack {
public:
    priority_queue < pair < double , int > > number; // to store the numbers along with its count
    map < int , int > count ; // to count the number of numbers 
    double pos = 0.0;
    FreqStack() {
        count.clear();
     //   number.clear();
    }
    
    void push(int x) {
        count[x]++;
        number.push(make_pair(count[x]+pos , x));
        pos+= 0.0001;
    }
    int pop() {
        //show();
        pair < int ,int > ans = number.top();
        number.pop();
        count[ans.second]--;
        return ans.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
