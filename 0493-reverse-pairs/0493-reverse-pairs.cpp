class Solution {
    private:
        void merge(vector<int>&arr, int low, int mid, int high) {
            vector<int>temp;
            int left = low; 
            int right = mid + 1;  
            while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                }
                else {
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while (left <= mid) {
                temp.push_back(arr[left]);
                left++;
            }
            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }
            for (int i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
        }
        
        int countpairs(vector<int>&arr,int low,int mid,int high){
            int count=0;
            int right=mid+1;
            for(int i=low;i<=mid;i++){
                while(right<=high && arr[i]>2*(long long)arr[right]){
                    right++;
                }
                count+=(right-(mid+1));
            }
            return count;
        }

        int mergeSort(vector<int>&arr, int low, int high) {
            int count=0;
            if (low >= high) return count;
            int mid = low+(high-low) / 2 ;
            count+=mergeSort(arr, low, mid);
            count+=mergeSort(arr, mid + 1, high);
            //countpairs before merging array
            count+=countpairs(arr,low,mid,high);
            merge(arr, low, mid, high);
            return count;
        }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};