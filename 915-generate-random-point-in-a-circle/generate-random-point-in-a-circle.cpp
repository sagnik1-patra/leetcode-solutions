class Solution {
    double R, Xc, Yc;
    mt19937 rng;
    uniform_real_distribution<double> uni;
public:
    Solution(double radius, double x_center, double y_center)
        : R(radius), Xc(x_center), Yc(y_center), rng(random_device{}()), uni(0.0, 1.0) {}

    vector<double> randPoint() {
        double ang = 2 * M_PI * uni(rng);
        double rad = sqrt(uni(rng)) * R;
        double x = Xc + rad * cos(ang);
        double y = Yc + rad * sin(ang);
        return {x, y};
    }
};