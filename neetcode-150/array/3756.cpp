class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Union adjacent nodes
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                unite(i, i - 1);
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};
