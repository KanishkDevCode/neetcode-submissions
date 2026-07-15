class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<vector<int>>arr;

        for(int i=0; i < tasks.size(); i++)
            arr.push_back({tasks[i][0], tasks[i][1], i});

        sort(arr.begin(), arr.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < arr.size() || !pq.empty()) {

            if (pq.empty() && time < arr[i][0])
                time = arr[i][0];

            while (i < arr.size() && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            auto curr = pq.top();
            pq.pop();

            time += curr.first;
            ans.push_back(curr.second);
        }

        return ans;
    }
};