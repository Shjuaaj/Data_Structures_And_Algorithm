Prob Link: https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18

class TaskManager {
    set<pair<int,int>> st;
    unordered_map<int,int> mp1, mp2;

public:
    TaskManager(vector<vector<int>>& nums) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            int uid= nums[i][0];
            int tid= nums[i][1];
            int p= nums[i][2];
            st.insert({p,tid});
            mp1[tid]= uid;
            mp2[tid]= p;
        }
    }
    
    void add(int uid, int tid, int p) {
        st.insert({p,tid});
        mp1[tid]= uid;
        mp2[tid]= p;
    }
    
    void edit(int tid, int np) {
         int op= mp2[tid];
         st.erase({op,tid});
         st.insert({np,tid});
         mp2[tid]= np;
    }
    
    void rmv(int tid) {
        int p= mp2[tid];
        int uid= mp1[tid];
        st.erase({p,tid});
        mp1.erase(tid);
        mp2.erase(tid);
    }
    
    int execTop() {
        if(st.size()==0) return -1;
        auto it= st.end();
        it--;
        int p= (*it).first;
        int tid= (*it).second;
        int uid= mp1[tid];
        mp1.erase(tid);
        mp2.erase(tid);
        st.erase({p,tid});
        return uid;
    }
};

