class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>> maxHeap;
        for(auto& p: points){
            float distance = sqrt(p[0]*p[0] + p[1]*p[1]);
            maxHeap.push({ distance, {p[0], p[1]} });
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second[0],
                           maxHeap.top().second[1]});
            maxHeap.pop();
        }
        return res;

    }

// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         int L = 0, R = points.size() - 1;
//         int pivot = points.size();

//         while (pivot != k) {
//             pivot = partition(points, L, R);
//             if (pivot < k) {
//                 L = pivot + 1;
//             } else {
//                 R = pivot - 1;
//             }
//         }
//         return vector<std::vector<int>>(points.begin(), points.begin() + k);
//     }

// private:
//     int partition(vector<vector<int>>& points, int l, int r) {
//         int pivotIdx = r;
//         int pivotDist = euclidean(points[pivotIdx]);
//         int i = l;
//         for (int j = l; j < r; j++) {
//             if (euclidean(points[j]) <= pivotDist) {
//                 swap(points[i], points[j]);
//                 i++;
//             }
//         }
//         swap(points[i], points[r]);
//         return i;
//     }

//     int euclidean(vector<int>& point) {
//         return point[0] * point[0] + point[1] * point[1];
//     }
};