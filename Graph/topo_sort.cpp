vector<int> topo_sort(const vector<vector<int>> &G){
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);
    for (int i = 0; i < n; i++) {  
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e] == 0) {
                que.push(e);
            }
        }
    }
    return ans;
}