class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int> safeSet;
        int j = graph.size() - 1;
        while(j--){
        for(int i=0; i<graph.size(); i++) {
            if (graph[i].size()) {
                bool flag = false;
                for(int j:graph[i]) {
                    if (safeSet.find(j) != safeSet.end()) {
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (flag && safeSet.begin() != safeSet.end()) {
                    safeSet.insert(i);
                    graph[i].clear();
                }
            } else {
                safeSet.insert(i);
            }
        }
    }
    vector<int> intVector(safeSet.begin(), safeSet.end());
    return intVector;
    }
};