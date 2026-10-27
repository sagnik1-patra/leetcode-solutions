class Robot {
public:
    int w, h;
    int pos = 0;
    int perimeter;
    bool moved = false;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }

    void step(int num) {
        pos = (pos + num) % perimeter;
        moved = true;
    }

    vector<int> getPos() {
        int p = pos;

        if (p < w - 1) {
            return {p, 0};
        }

        p -= (w - 1);

        if (p < h - 1) {
            return {w - 1, p};
        }

        p -= (h - 1);

        if (p < w - 1) {
            return {w - 1 - p, h - 1};
        }

        p -= (w - 1);

        return {0, h - 1 - p};
    }

    string getDir() {
        if (pos == 0) {
            return moved ? "South" : "East";
        }

        if (pos <= w - 1) {
            return "East";
        }

        if (pos <= w + h - 2) {
            return "North";
        }

        if (pos <= 2 * w + h - 3) {
            return "West";
        }

        return "South";
    }
};