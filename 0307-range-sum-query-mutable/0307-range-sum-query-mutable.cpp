class NumArray {
public:
    int n;
    vector<int>seg;
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n+1);
        build(0,0,n-1,nums,seg);
    }
    void build(int idx,int low,int high,vector<int>&nums,vector<int>&seg){
        if(low==high){
            seg[idx]=nums[low];
            return ;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,nums,seg);
        build(2*idx+2,mid+1,high,nums,seg);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    void point_update(int idx,int low,int high,int i,int val,vector<int>&seg){
        if(low==high){
            seg[idx]=val;
            return ;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            point_update(2*idx+1,low,mid,i,val,seg);
        }
        else{
            point_update(2*idx+2,mid+1,high,i,val,seg);
        }
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int evaluate_query(int idx,int low,int high,int l,int r,vector<int>&seg){
        if(high<l || r<low)return 0;
        if(low>=l && high<=r)return seg[idx];
        int mid=(low+high)/2;
        int left=evaluate_query(2*idx+1,low,mid,l,r,seg);
        int right=evaluate_query(2*idx+2,mid+1,high,l,r,seg);
        return left+right;
    }
    void update(int index, int val) {
        point_update(0,0,n-1,index,val,seg);
    }
    
    int sumRange(int left, int right) {
        return evaluate_query(0,0,n-1,left,right,seg);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */