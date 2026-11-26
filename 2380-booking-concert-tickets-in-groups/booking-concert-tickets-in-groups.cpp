class BookMyShow {
private:
    int n, m;
    int firstRow = 0;

    vector<long long> sumTree;
    vector<int> maxTree;
    vector<int> remaining;

    // Build segment tree
    void build(int node, int l, int r) {
        if (l == r) {
            sumTree[node] = m;
            maxTree[node] = m;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        pull(node);
    }

    // Update parent using its children
    void pull(int node) {
        sumTree[node] = sumTree[2 * node] +
                        sumTree[2 * node + 1];

        maxTree[node] = max(maxTree[2 * node],
                            maxTree[2 * node + 1]);
    }

    // Update available seats in a particular row
    void update(int node, int l, int r,
                int row, int seats) {

        if (l == r) {
            sumTree[node] = seats;
            maxTree[node] = seats;
            return;
        }

        int mid = l + (r - l) / 2;

        if (row <= mid) {
            update(2 * node, l, mid, row, seats);
        } else {
            update(2 * node + 1, mid + 1, r,
                   row, seats);
        }

        pull(node);
    }

    // Find total available seats in rows [0, maxRow]
    long long querySum(int node, int l, int r,
                       int maxRow) {

        if (l > maxRow)
            return 0;

        if (r <= maxRow)
            return sumTree[node];

        int mid = l + (r - l) / 2;

        return querySum(2 * node, l, mid, maxRow) +
               querySum(2 * node + 1, mid + 1, r,
                        maxRow);
    }

    // Find first row containing at least k seats
    int findRow(int node, int l, int r,
                int k, int maxRow) {

        if (l > maxRow || maxTree[node] < k)
            return -1;

        if (l == r)
            return l;

        int mid = l + (r - l) / 2;

        int row = findRow(2 * node, l, mid,
                          k, maxRow);

        if (row != -1)
            return row;

        return findRow(2 * node + 1, mid + 1, r,
                       k, maxRow);
    }

public:
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;

        remaining.resize(n, m);
        sumTree.resize(4 * n, 0);
        maxTree.resize(4 * n, 0);

        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow) {
        int row = findRow(1, 0, n - 1, k, maxRow);

        if (row == -1)
            return {};

        int seat = m - remaining[row];

        remaining[row] -= k;

        update(1, 0, n - 1, row, remaining[row]);

        return {row, seat};
    }

    bool scatter(int k, int maxRow) {

        // Check whether enough seats exist
        if (querySum(1, 0, n - 1, maxRow) < k)
            return false;

        while (k > 0) {

            // Skip completely occupied rows
            while (firstRow < n &&
                   remaining[firstRow] == 0) {
                firstRow++;
            }

            int take = min(k, remaining[firstRow]);

            remaining[firstRow] -= take;
            k -= take;

            update(1, 0, n - 1, firstRow,
                   remaining[firstRow]);
        }

        return true;
    }
};