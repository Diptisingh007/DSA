class Solution {
public:
    bool solve(vector<int>& time, int totalTrips,long long mid){
        int n=time.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(mid/time[i]);
           if(cnt>=totalTrips) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long low=1;
        long long high=1LL*(*min_element(time.begin(),time.end()))*totalTrips;
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;

            if(solve(time,totalTrips,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};