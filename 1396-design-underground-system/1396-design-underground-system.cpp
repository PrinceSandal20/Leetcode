class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>in;
    unordered_map<string,pair<int,int>>out;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s=in[id].first+ " " + stationName;
        if(out.find(s)==out.end()){
          out[s]={t-in[id].second,1};
        }
        else if(out.find(s)!=out.end()){
           int one=out[s].first;
           int two=out[s].second;
           out[s]={one+t-in[id].second,two+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s=startStation + " " + endStation;
        return  (double)out[s].first/(double)out[s].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */