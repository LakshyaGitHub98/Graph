#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    int numVertices;
    vector<vector<int>>adjLists;
    vector<bool>visited;
public:
    Graph(int vertices){
        numVertices=vertices;
        adjLists.resize(vertices);
        visited.resize(vertices);
    }
    void addEdges(int src,int dest){
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }
    void BFS(int start){
        queue<int>q;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int cVertex=q.front();
            cout<<"Visited: "<<cVertex<<" ";
            q.pop();
            for(int i=0;i<adjLists[cVertex].size();++i){
                int adjVertex=adjLists[cVertex][i];
                if(!visited[adjVertex]){
                    visited[adjVertex]=true;
                    q.push(adjVertex);
                }
            }
        }
    }
    void DFS(int vertex){
        visited[vertex]=true;
        cout<<"Visited: "<<vertex<<" ";
        for(auto i=adjLists[vertex].begin();i!=adjLists[vertex].end();++i){
           if(!visited[*i]){
               DFS(*i);
           } 
        }
    }
};
int main(){
    Graph g(6);
    char ch;
    g.addEdges(0,1);
    g.addEdges(0,2);
    g.addEdges(1,3);
    g.addEdges(1,4);
    g.addEdges(2,5);
    cout<<"Choose 'b/B' for BFS traversal or 'd/D' for DFS traversal : "<<endl;
    cin>>ch;
    if(ch=='b' or ch=='B'){
        int v;
        cout<<"Enter the vertex from where you wanna to traverse : ";
        cin>>v;
        cout<<"The Breadth-Fist-Search tarversal : "<<endl;
        g.BFS(v);
    }
    else if(ch=='d' or ch=='D'){
        int v;
        cout<<"Enter the vertex from where you wanna to traverse : ";
        cin>>v;
        cout<<"The Depth-Fist-Search tarversal : "<<endl;
        g.DFS(v);        
    }
    else {
        cout<<"Wrong choice !";
    }
    return 0;
}