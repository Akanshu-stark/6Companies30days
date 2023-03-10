class Solution {
public:
    long long bias = 40000 + 7;
    long long bit[100007];
    int n = 1e5;
    void update(int i, long long v){
        int x = i;
        while(x < n){
            bit[x] += v;
            x += (x&-x);
        }
    }
    long long sum(int i){
        long long s = 0;
        while(i>0){
            s = s + bit[i];
            i -= (i&-i);
        }
        return s;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        update(nums1[0] - nums2[0] + bias, 1);
        long long ans = 0;
        for(int i=1;i<n;i++){
            ans += sum(nums1[i] - nums2[i] + bias + diff);
            update(nums1[i] - nums2[i] + bias, 1);
        }
        return ans;
    }
};