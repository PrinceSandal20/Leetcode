class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        //used constraints here
        for(int i=1;i<=1000;i++)
        {
            st.insert(i);
        }
    }
    
    int popSmallest() {
        //taking smallest element from the set
        int removed=*st.begin();
        st.erase(removed);
        return removed;
    }
    
    void addBack(int num) {
        //cheking if the element is not in the set then we will add that into the set
        if(st.find(num)==st.end())
        {
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */