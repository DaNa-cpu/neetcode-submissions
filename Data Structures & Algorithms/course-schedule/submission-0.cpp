class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList(numCourses);
        unordered_set<int> visited;

        for(const auto& prerequisit: prerequisites){
            adjList[prerequisit[0]].push_back(prerequisit[1]);
        }

        for( int course = 0; course < numCourses; course++){
            if(!dfs(course, adjList, visited)){
                return false;
            }
        }
        return true;

    }

    bool dfs(int course, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited){
        if(visited.count(course)){
            return false;
        }

        if(adjList[course].empty()){
            return true;
        }

        visited.insert(course);
        for( int pre: adjList[course]){
            if(!dfs(pre, adjList, visited)){
                return false;
            }
        }
        visited.erase(course);
        adjList[course].clear();
        return true;
    }
};
