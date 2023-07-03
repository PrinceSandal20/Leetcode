class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>maxH;
    unordered_map<int,int>m;
    int idx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxH.push({m[val]++,{idx++,val}});
    }
    
    int pop() {
        int ans=maxH.top().second.second;
        maxH.pop();
        m[ans]--;
        if(m[ans]==0)m.erase(ans);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */