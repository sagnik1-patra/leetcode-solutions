class UndergroundSystem {
public:
    // id -> {station, time}
    unordered_map<int, pair<string, int>> checkInMap;
    
    // "start_end" -> {totalTime, count}
    unordered_map<string, pair<long long, int>> routeMap;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkInMap[id];
        checkInMap.erase(id);
        
        int travelTime = t - startTime;
        string route = startStation + "_" + stationName;
        
        routeMap[route].first += travelTime; // total time
        routeMap[route].second += 1;         // count
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto [totalTime, count] = routeMap[route];
        
        return (double) totalTime / count;
    }
};