
class Solution {
public:
    struct Node {
        int zero, one;
    };

    Node combine(Node a, Node b, char op) {
        Node res = {INT_MAX, INT_MAX};

        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                int cost = (x == 0 ? a.zero : a.one)
                         + (y == 0 ? b.zero : b.one);

                for (char o : {'&', '|'}) {
                    int result = (o == '&') ? (x & y) : (x | y);

                    int total = cost + (o != op);

                    if (result == 0)
                        res.zero = min(res.zero, total);
                    else
                        res.one = min(res.one, total);
                }
            }
        }

        return res;
    }

    int minOperationsToFlip(string expression) {
        stack<Node> values;
        stack<char> ops;

        auto evaluate = [&]() {
            Node b = values.top();
            values.pop();

            Node a = values.top();
            values.pop();

            char op = ops.top();
            ops.pop();

            values.push(combine(a, b, op));
        };

        for (char c : expression) {
            if (c == '0') {
                values.push({0, 1});
            }
            else if (c == '1') {
                values.push({1, 0});
            }
            else if (c == '(') {
                ops.push(c);
            }
            else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    evaluate();
                }
                ops.pop();
            }
            else {
                while (!ops.empty() && ops.top() != '(') {
                    evaluate();
                }
                ops.push(c);
            }
        }

        while (!ops.empty()) {
            evaluate();
        }

        Node ans = values.top();

        return max(ans.zero, ans.one);
    }
};
