class Solution {
public:
    int le(vector<int>& a,int ele){
        int low=0,high=a.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]<=ele){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int re(vector<int>& a,int ele){
        int low=0,high=a.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]>=ele){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int mod=1e9+7;
        vector<int>a(n,0);
        for(int i=0;i<n;i++){
            a[i]=nums1[i];
        }
        sort(a.begin(),a.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums1[i]-nums2[i]);
        }
        long long ans=sum;
        for(int i=0;i<n;i++){
            long long cur=abs(nums1[i]-nums2[i]);
           // sum-=cur;
            int li=le(a,nums2[i]);
            int ri=re(a,nums2[i]);
            long long ls=INT_MAX,rs=INT_MAX;
            if(li!=-1){
                ls=abs(a[li]-nums2[i]);
            }
            if(ri!=-1){
                rs=abs(a[ri]-nums2[i]);
            }
            ans=min(ans,sum-cur+min(ls,rs));
        }
        ans=(ans)%mod;
        return (int)ans;
    }
};