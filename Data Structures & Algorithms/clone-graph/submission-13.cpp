/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// Iterative (BFS)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> adjList;
        queue<Node*> q;
        adjList[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(Node* neighbor: cur->neighbors){
                if(!adjList.count(neighbor)){
                    adjList[neighbor] = new Node(neighbor->val);
                    q.push(neighbor); // push it when visit the node to avoid pushing duplicates
                }
                adjList[cur]->neighbors.push_back(adjList[neighbor]);
            }

        }
        return adjList[node];
        
    }
};
// Recursive (DFS)
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         unordered_map<Node*, Node*> adjList;
//         return dfs(node, adjList);
//     }

//     Node* dfs(Node* node, unordered_map<Node*, Node*>& adjList){
//         if(node == nullptr) return nullptr;

//         if(adjList.count(node)) return adjList[node];

//         Node* newNode = new Node(node->val);
//         adjList[node] = newNode;

//         for(Node* neighbor: node->neighbors){
//             Node* newNeighbor = dfs(neighbor, adjList);
//             newNode->neighbors.push_back(newNeighbor);
//         }

//         return newNode;
//     }


// };
