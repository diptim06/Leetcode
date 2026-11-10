class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supply(supplies.begin(), supplies.end());
        unordered_set<string> recipeSet(recipes.begin(), recipes.end());
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for (const string& r : recipes) {
            indegree[r] = 0;
        }

        for (int i = 0; i < recipes.size(); i++) {
            bool canBeMade = true;
            for (const string& ing : ingredients[i]) {
                if (!supply.count(ing)) {
                    if (recipeSet.count(ing)) {
                        graph[ing].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    } else {
                        canBeMade = false;
                    }
                }
            }
            if (!canBeMade) {
                indegree[recipes[i]] = 1e9; // Mark as unresolvable
            }
        }

        queue<string> q;
        for (const auto& p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            ans.push_back(u);

            for (const string& v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans;
    }
};