class Solution {
public:
    static const int MOUSE_TURN = 0;
    static const int CAT_TURN = 1;

    static const int UNKNOWN = 0;
    static const int MOUSE_WIN = 1;
    static const int CAT_WIN = 2;

    int rows, cols;
    int food;

    vector<vector<int>> mouseMoves;
    vector<vector<int>> catMoves;

    vector<int> getMoves(
        int pos,
        int jump,
        vector<string>& grid
    ) {
        vector<int> moves;

        int r = pos / cols;
        int c = pos % cols;

        // Staying at the same position is allowed
        moves.push_back(pos);

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (auto& dir : directions) {

            for (int step = 1; step <= jump; step++) {

                int nr = r + dir[0] * step;
                int nc = c + dir[1] * step;

                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols ||
                    grid[nr][nc] == '#') {
                    break;
                }

                moves.push_back(nr * cols + nc);
            }
        }

        return moves;
    }

    bool canMouseWin(
        vector<string>& grid,
        int catJump,
        int mouseJump
    ) {
        rows = grid.size();
        cols = grid[0].size();

        int total = rows * cols;

        int mouseStart = -1;
        int catStart = -1;

        vector<int> validCells;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '#')
                    continue;

                int pos = r * cols + c;

                validCells.push_back(pos);

                if (grid[r][c] == 'M')
                    mouseStart = pos;

                else if (grid[r][c] == 'C')
                    catStart = pos;

                else if (grid[r][c] == 'F')
                    food = pos;
            }
        }

        // Precompute all possible moves
        mouseMoves.assign(total, {});
        catMoves.assign(total, {});

        for (int pos : validCells) {
            mouseMoves[pos] =
                getMoves(pos, mouseJump, grid);

            catMoves[pos] =
                getMoves(pos, catJump, grid);
        }

        /*
            result[mouse][cat][turn]

            0 = unknown
            1 = mouse wins
            2 = cat wins
        */
        vector<vector<array<int, 2>>> result(
            total,
            vector<array<int, 2>>(total)
        );

        /*
            degree = number of moves available
            to the player whose turn it is.
        */
        vector<vector<array<int, 2>>> degree(
            total,
            vector<array<int, 2>>(total)
        );

        for (int m : validCells) {
            for (int c : validCells) {

                degree[m][c][MOUSE_TURN] =
                    mouseMoves[m].size();

                degree[m][c][CAT_TURN] =
                    catMoves[c].size();
            }
        }

        queue<array<int, 3>> q;

        // --------------------------------------------------
        // Terminal states
        // --------------------------------------------------

        for (int m : validCells) {
            for (int c : validCells) {

                // Cat catches mouse
                if (m == c) {

                    for (int turn = 0; turn < 2; turn++) {

                        if (result[m][c][turn] == UNKNOWN) {
                            result[m][c][turn] = CAT_WIN;
                            q.push({m, c, turn});
                        }
                    }

                    continue;
                }

                // Cat reaches food
                if (c == food) {

                    for (int turn = 0; turn < 2; turn++) {

                        if (result[m][c][turn] == UNKNOWN) {
                            result[m][c][turn] = CAT_WIN;
                            q.push({m, c, turn});
                        }
                    }

                    continue;
                }

                // Mouse reaches food
                if (m == food) {

                    for (int turn = 0; turn < 2; turn++) {

                        if (result[m][c][turn] == UNKNOWN) {
                            result[m][c][turn] = MOUSE_WIN;
                            q.push({m, c, turn});
                        }
                    }
                }
            }
        }

        // --------------------------------------------------
        // Build reverse moves
        // --------------------------------------------------

        vector<vector<int>> reverseMouse(total);
        vector<vector<int>> reverseCat(total);

        for (int from : validCells) {

            for (int to : mouseMoves[from]) {
                reverseMouse[to].push_back(from);
            }

            for (int to : catMoves[from]) {
                reverseCat[to].push_back(from);
            }
        }

        // --------------------------------------------------
        // Retrograde BFS
        // --------------------------------------------------

        while (!q.empty()) {

            auto state = q.front();
            q.pop();

            int mouse = state[0];
            int cat = state[1];
            int turn = state[2];

            int winner = result[mouse][cat][turn];

            /*
                If current state is Mouse's turn,
                previous state must have been Cat's turn.
            */
            if (turn == MOUSE_TURN) {

                for (int previousCat : reverseCat[cat]) {

                    int pm = mouse;
                    int pc = previousCat;
                    int previousTurn = CAT_TURN;

                    if (result[pm][pc][previousTurn] != UNKNOWN)
                        continue;

                    /*
                        Cat wants CAT_WIN.

                        If Cat can move into a CAT_WIN state,
                        previous state is also CAT_WIN.
                    */
                    if (winner == CAT_WIN) {

                        result[pm][pc][previousTurn] = CAT_WIN;

                        q.push({
                            pm,
                            pc,
                            previousTurn
                        });
                    }

                    else {

                        /*
                            This move leads to Mouse winning.

                            Remove this option from Cat's
                            available moves.
                        */
                        degree[pm][pc][previousTurn]--;

                        /*
                            If every Cat move leads to
                            Mouse winning, Mouse wins.
                        */
                        if (degree[pm][pc][previousTurn] == 0) {

                            result[pm][pc][previousTurn] =
                                MOUSE_WIN;

                            q.push({
                                pm,
                                pc,
                                previousTurn
                            });
                        }
                    }
                }
            }

            /*
                If current state is Cat's turn,
                previous state must have been Mouse's turn.
            */
            else {

                for (int previousMouse :
                     reverseMouse[mouse]) {

                    int pm = previousMouse;
                    int pc = cat;
                    int previousTurn = MOUSE_TURN;

                    if (result[pm][pc][previousTurn] != UNKNOWN)
                        continue;

                    /*
                        Mouse wants MOUSE_WIN.

                        If Mouse can move into a
                        MOUSE_WIN state, previous state
                        is also MOUSE_WIN.
                    */
                    if (winner == MOUSE_WIN) {

                        result[pm][pc][previousTurn] =
                            MOUSE_WIN;

                        q.push({
                            pm,
                            pc,
                            previousTurn
                        });
                    }

                    else {

                        /*
                            This move leads to Cat winning.
                        */
                        degree[pm][pc][previousTurn]--;

                        /*
                            If every Mouse move leads to
                            Cat winning, Cat wins.
                        */
                        if (degree[pm][pc][previousTurn] == 0) {

                            result[pm][pc][previousTurn] =
                                CAT_WIN;

                            q.push({
                                pm,
                                pc,
                                previousTurn
                            });
                        }
                    }
                }
            }
        }

        /*
            Any unresolved state corresponds to a game
            that can continue indefinitely.

            According to the problem, if Mouse cannot
            reach food within the turn limit, Cat wins.

            Therefore Mouse wins only when the initial
            state is explicitly MOUSE_WIN.
        */
        return result[mouseStart][catStart][MOUSE_TURN]
               == MOUSE_WIN;
    }
};