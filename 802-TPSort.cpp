class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(), 0);
        vector<vector<int>> reverse(graph.size());
        vector<int> ans;
        queue<int> queue;
        for(int i=0; i<graph.size(); i++) {
            for(int j:graph[i]) {
                reverse[j].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0; i<indegree.size(); i++) {
            if(!indegree[i]){
                queue.push(i);
            }
            // cout<<i<< " " << indegree[i]<< " ";
        }

        while(!queue.empty()) {
            // cout << queue.front() << " ";
            for(int j:reverse[queue.front()]) {
                // cout << j << " ";
                indegree[j]--;
                if(indegree[j] == 0) {
                    queue.push(j);
                }
            }
            ans.push_back(queue.front());
            queue.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};