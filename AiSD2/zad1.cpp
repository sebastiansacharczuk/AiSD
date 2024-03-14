#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define pairll pair<long, long>
using namespace std;

struct Location {
    int nr;
    long x, y;
};

bool cmp1(const Location a, const Location b){ return a.x < b.x; }
bool cmp2(const Location a, const Location b){ return a.y < b.y; }
long travelCost(Location a, Location b){ return min(abs(a.x - b.x), abs(a.y - b.y)); }

void dijkstra(vector<pair<long, long>> adj[], int vertices, int source, int finish){
    bool visited[vertices];
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    long shortest_dist[vertices];
    for(int i = 0; i < vertices; i++)
        shortest_dist[i] = LONG_MAX;

    shortest_dist[source] = 0;

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> q;
    q.push({shortest_dist[source], source});
    while(!q.empty()){
        pair<long, long> prev = q.top();
        q.pop();
        if(visited[prev.second]) continue;
        visited[prev.second] = true;
        for(auto edge : adj[prev.second]){
            if(shortest_dist[prev.second] + edge.second < shortest_dist[edge.first]){
                shortest_dist[edge.first] = shortest_dist[prev.second] + edge.second;
                q.push({shortest_dist[edge.first], edge.first});
            }
        }
    }
    cout << shortest_dist[finish] << '\n';
}

int main(){
    int n, start, finish;
    cin >> n;
    Location arr[n];
    for(int i = 0; i < n; i++){
        arr[i].nr = i;
        cin >> arr[i].x >> arr[i].y;
    }
    cin >> start >> finish;
    long weight;
    vector<pairll> adj[n];
    sort(arr, arr + n, cmp1);
    for(int i = 1; i < n; i++){
        weight = travelCost(arr[i], arr[i-1]);
        adj[arr[i].nr].push_back({arr[i-1].nr, weight});
        adj[arr[i-1].nr].push_back({arr[i].nr, weight});
    }
    sort(arr, arr + n, cmp2);
    for(int i = 1; i < n; i++){
        weight = travelCost(arr[i], arr[i-1]);
        adj[arr[i].nr].push_back({arr[i-1].nr, weight});
        adj[arr[i-1].nr].push_back({arr[i].nr, weight});
    }
    
    dijkstra(adj, n, start, finish);

    return 0;
}