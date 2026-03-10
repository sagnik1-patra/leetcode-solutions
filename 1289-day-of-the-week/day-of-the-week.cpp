class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        
        vector<string> days = {
            "Sunday","Monday","Tuesday",
            "Wednesday","Thursday","Friday","Saturday"
        };
        
        vector<int> monthDays = {
            31,28,31,30,31,30,
            31,31,30,31,30,31
        };

        int totalDays = 0;

        // count days from 1971 to previous year
        for(int y = 1971; y < year; y++){
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                totalDays += 366;
            else
                totalDays += 365;
        }

        // count days for months
        for(int m = 1; m < month; m++){
            totalDays += monthDays[m-1];
            if(m == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
                totalDays += 1;
        }

        totalDays += day;

        return days[(totalDays + 4) % 7];
    }
};