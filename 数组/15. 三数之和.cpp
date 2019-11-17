


//固定一个，移动另外两个



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()< 3)
            return res;
        else if(nums.size()== 3){
            int sum  = 0;
            for(int i =0;i<3;++i) sum+=nums[i];
            if(sum == 0) res.push_back(nums);
            return res;
        }
        
        
        sort(nums.begin(), nums.end());
        cout<<nums[0]<<endl;
        int k = 0;
        while(k <= nums.size()-3){
            if(nums[k] > 0)
                break;
            if(k>0 && nums[k] == nums[k-1])
                continue;
            
            cout<<"k: "<<k<<endl;
            int i = k+1;
            int j = nums.size() -1;
            while(i<j){
                
                int sum = nums[k]+nums[i]+nums[j];
                cout<<i<<" "<<j<<endl;
                if(sum < 0){
                    i++;
                    while(i<j && nums[i] == nums[i-1]) i++;
                }else if(sum > 0){
                    j--;
                    while(i<j && nums[j] == nums[j+1]) j--;
                }else{
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    while(i<j && nums[i] == nums[i-1]) i++;
                    
                    j--;
                    while(i<j && nums[j] == nums[j+1]) j--;
                }
            }
            
            k++;
        }
        
        return res;
        
        
    }
    
    

    
};


    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int l = i + 1;
            int r = n - 1;
            
            while(l < r){
                while(l > i+1 && l < r && nums[l] == nums[l-1]){
                    l++;
                }
                while(r < n-2 &&  l < r && nums[r] == nums[r+1]){
                    r--;
                }
                if(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum == 0){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[l]);
                        t.push_back(nums[r]);
                        ans.push_back(t);
                        l++;
                        r--;
                    }else if(sum < 0){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
