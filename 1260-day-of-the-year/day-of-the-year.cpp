class Solution {
public:
    int dayOfYear(string date) {
        // Extract year, month, and day
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        // Days in each month
        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        // Check for leap year
        bool isLeap = false;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeap = true;
        }
        
        // If leap year, February has 29 days
        if (isLeap) {
            daysInMonth[1] = 29;
        }
        
        // Calculate total days
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }
        
        totalDays += day;
        
        return totalDays;
    }
};