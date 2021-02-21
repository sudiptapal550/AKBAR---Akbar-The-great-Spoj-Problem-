#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = (int)1e6 + 5, M = 3005;
int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        
        int n, r, m;
        cin >> n >> r >> m;
        bool vis[n+2] = {
            false,
        };
        int dist[n+2] = {
            0,
        };
        unordered_map<long long, set<long long>> um;
        queue<pair<long long, long long>> q;
        vector<vector<int>>adj(n + 2);
        for(int i=0;i<r;i++)
            {
                long long s,d;
                cin >> s >> d;
                    adj[s].push_back(d);
                    adj[d].push_back(s);
            }
            for(int i=0;i<m;i++){
                long long v,p;
                cin >> v >> p;
                q.push({v,p});
                vis[v] = true;
                dist[v] = 0;
                um[v].insert(v);
            }
            int flag = 1;
            while(!q.empty()){
                if(flag == 0)
                    break;
                pair<long long,long long>temp = q.front();
                long long s = temp.first;
                long long p = temp.second;
                q.pop();
                if(um[s].size() > 1){
                    flag = 0;
                    break;
                }
                for(auto it:adj[s]){
                    if(vis[it] == true){
                        int curr_dis = dist[s] + 1;
                        if(p >= curr_dis){
                           um[it].insert(*um[s].begin());
                        }
                    }
                    else{
                        if(dist[s] + 1 <= p){
                            q.push(make_pair(it,p));
                            vis[it] = true;
                            dist[it] = dist[s] + 1;
                            um[it].insert(*um[s].begin());
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
               
                if(vis[i] == false){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;

        
    }
    return 0;
}
