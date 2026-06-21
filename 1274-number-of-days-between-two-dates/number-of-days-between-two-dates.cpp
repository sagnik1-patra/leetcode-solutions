class Solution {
public:
    bool isLeap(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }
    
    int countDays(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        
        vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        int days = 0;
        
        // count days for previous years
        for (int year = 1971; year < y; year++) {
            days += isLeap(year) ? 366 : 365;
        }
        
        // count days for previous months
        for (int i = 0; i < m - 1; i++) {
            days += monthDays[i];
            if (i == 1 && isLeap(y)) days++; // February
        }
        
        // add current days
        days += d;
        
        return days;
    }
    
    int daysBetweenDates(string date1, string date2) {
        return abs(countDays(date1) - countDays(date2));
    }
};