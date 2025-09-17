Prob link: https://leetcode.com/problems/design-a-food-rating-system/submissions/1773771658/?envType=daily-question&envId=2025-09-17

class FoodRatings {
    unordered_map<string,set<pair<int,string>>> mp;
    unordered_map<string,string> mp1;
    unordered_map<string,int> mp2;

public:
    FoodRatings(vector<string>& f, vector<string>& cu, vector<int>& rat) {
        int n= f.size();
        for(int i=0;i<n;i++){
            mp2[f[i]]= rat[i];
            mp1[f[i]]= cu[i];
            mp[cu[i]].insert({rat[i],f[i]});
        }
    }
    
    void changeRating(string f, int nr) {
        int prev= mp2[f];
        string cu= mp1[f];
        mp[cu].erase({prev,f});
        mp2[f]= nr;
        mp[cu].insert({nr,f});

    }
    
    string highestRated(string cu) {
        auto it= mp[cu].end();
        it--;
        auto prev= it;
        
        while(it!=mp[cu].begin()){
            auto next= it;
            it--;
            if((*it).first!=(*next).first){
                it= next;
                break;
            }
        }
        return (*it).second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */