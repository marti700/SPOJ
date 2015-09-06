#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
//perform a Breth first search on the tree
int BFS(map<int,vector<int> > &graph, int source, bool flag);

int main()
{
    std::ios::sync_with_stdio(false);

    int number_of_nodes,u,v,source;
    vector<int> distances;

    cin>>number_of_nodes;
    map<int, vector<int> > tree_adjacenty_list;

    //create the adjacency list for the tree
    for(int i=0;i<number_of_nodes-1;++i){
        cin>>u>>v;
        //add neighbors
        tree_adjacenty_list[v].push_back(u);
        tree_adjacenty_list[u].push_back(v);
    }
    //performs a BFS to get the longest path from the node No. 1 to the node that is
    //at the bottom of the tree, but this wont give the longest path.
    source = BFS(tree_adjacenty_list,1, false);
    //print the longest path by runing a BFS using the node that is at the bottom of the tree
    //as source
    cout<<BFS(tree_adjacenty_list,source,true);

    return 0;
}

int BFS(map<int,vector<int> > &graph, int source, bool flag)
{
    int distance = 0;
    int i=0,d,new_source, possible_source;
    int current_node = 0;
    queue<int> bfs_queue;
    pair<int,int> node_info; //saves this node predecesor node and it distance from the source.
    map <int,pair<int,int> > antecesor; //saves information about the current node 
    vector<int> distances_between_vertices; //saves the distances of all nodes on the same BFS level 
    //inserts the source in the queue
    bfs_queue.push(source);
    node_info.first = -1; node_info.second = 0; //-1 means it is the starting node
    antecesor[source] = node_info;

    while(!bfs_queue.empty()){
        current_node = bfs_queue.front(); // gets the element at the front of the queue
        bfs_queue.pop(); // dequeue the element
        for(int j=0;j<graph[current_node].size();++j){
            if (antecesor.find(graph[current_node][j]) == antecesor.end()){
                bfs_queue.push(graph[current_node][j]);
                node_info.first = current_node;
                node_info.second = antecesor[current_node].second + 1;
                antecesor[graph[current_node][j]] = node_info;
                distances_between_vertices.push_back(node_info.second);
                possible_source = graph[current_node][j];
            }
        }
        d = *max_element(distances_between_vertices.begin(), distances_between_vertices.end());
        if(d > distance){distance = d; new_source = possible_source;}
        distances_between_vertices.clear();
    }
    if (flag){
        return distance;
    }
    else{
        return new_source;
    }
}
