class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leaders;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> count;
        leaders.resize(persons.size());

        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); i++) {
            int p = persons[i];
            count[p]++;

            if (count[p] >= maxVotes) {
                maxVotes = count[p];
                leader = p;
            }
            leaders[i] = leader;
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};
