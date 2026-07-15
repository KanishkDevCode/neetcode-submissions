class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(), trips.end(),
             [](auto &a, auto &b) {
                return a[1] < b[1];
             });
        
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;

        int passengers = 0;

        for (auto &trip : trips)
        {
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];

            while (!pq.empty() && pq.top().first <= from)
            {
                passengers -= pq.top().second;
                pq.pop();
            }

            passengers += num;

            if (passengers > capacity)
                return false;

            pq.push({to, num});
        }

        return true;
    }
};