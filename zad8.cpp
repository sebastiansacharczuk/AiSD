#include <iostream>
#include <vector>
#include <queue>

void solution(std::vector<int> adj[], int vertices, int source, int max_time){
    int counter = 0;
    int max_distance = 0;
    bool visited[vertices]{false};
    int distance[vertices]{0};
    std::queue<int> q;

    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int current = q.front();
		q.pop();
		for(int i = 0; i < adj[current].size(); i++){
			if(visited[adj[current][i]] == false){
				visited[adj[current][i]] = true;
                distance[adj[current][i]] = distance[current] + 1; // co kazdy level bedzie zwiekszany
                if(distance[adj[current][i]]*2 <= max_time)
                    counter++;
                if(distance[adj[current][i]] >= max_distance){
                    max_distance = distance[adj[current][i]];
                }
                
				q.push(adj[current][i]);
			}
		}
    }
    std::cout << max_distance << ' ' << counter;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int cities, connections, attacked, max_time;
    std::cin >> cities >> connections >> attacked >> max_time;
    std::vector<int> adj[cities];

    int s, d;
    for(int i = 0; i < connections; i++){
        std::cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    if(attacked > cities || max_time == 0 || connections == 0 || cities == 0)
        std::cout << "0 0";
    else
        solution(adj, cities, attacked, max_time);

    return 0;
}