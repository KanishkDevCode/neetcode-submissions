class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        // Available room numbers (smallest room first)
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // (endTime, roomNumber)
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busyRooms;

        for(int i=0;i<n;i++)
            freeRooms.push(i);

        vector<long long> count(n,0);

        for(auto &meeting: meetings){

            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end-start;

            // Free all rooms that have become available
            while(!busyRooms.empty() && busyRooms.top().first<=start){

                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            // Free room exists
            if(!freeRooms.empty()){

                int room = freeRooms.top();
                freeRooms.pop();

                count[room]++;

                busyRooms.push({end,room});
            }

            // Need to delay
            else{

                auto [finish,room]=busyRooms.top();
                busyRooms.pop();

                count[room]++;

                busyRooms.push({finish+duration,room});
            }
        }

        int ans=0;

        for(int i=1;i<n;i++){

            if(count[i]>count[ans])
                ans=i;
        }

        return ans;
    }
};