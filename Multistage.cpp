#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void run_multistage(vector<vector<int>> &graph, int src, int tar, int stage)
{   
    vector<vector<int>> dp; // [stage][index or node number];
    // stage - 1 to m
    // index - 0 to n-1
    // start from tar and end at start
    // for iterative approach
    queue<int> bfs;
    
    for(int i = stage; i > 0; --i)
    {
        vector<int> stage_level; // [stage][index or node number]
        for(int j = 0; j < stage_level; j++)
        {

        }

    }
}

int main()
{
    vector<vector<int>> graph(8);
    int src = 0;
    int tar = 7;
    run_multistage(graph, src, tar);
    return 0;
}