class TimeMap {
public:
    map <string, vector <pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector <pair<int, string>> &vp = mp[key];
        int lo = 0, hi = vp.size()-1;
        int id = -1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(vp[mid].first <= timestamp){
                id = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        if(id == -1) return "";
        return vp[id].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */