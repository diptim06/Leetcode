class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //1. create adjlist;
        vector<vector<pair<int,int>>> adj(n+1); //1 based indexing

        for(auto t : times)
        {
            adj[t[0]].push_back({t[2], t[1]});
        }

        //2. build a set
        set<pair<int,int>> st;
        st.insert({0,k}); //k is the starting node

        //3. build a dist array
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0; 

        //4. loop for calculating dist array

        while(!st.empty())
        {
            auto [currdist, currnode] = *st.begin();
            st.erase(st.begin());

            for(auto [wt, nextnode] : adj[currnode])
            {
                if(currdist + wt < dist[nextnode])
                {
                    if(dist[nextnode] != INT_MAX) 
                        {
                            st.erase({dist[nextnode],nextnode});
                        }
                    dist[nextnode] = currdist + wt;
                    st.insert({dist[nextnode], nextnode});
                }
            }
        }

        //return the max time of the dist array as it will represt the last node of the graph practically
        int maxtime = 0;

        for(int i = 1; i<=n; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;
            maxtime = max(maxtime, dist[i]);
        }

        return maxtime;
    }
};