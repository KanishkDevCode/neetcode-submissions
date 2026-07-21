class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long currentTime = 0;
        long long totalWait = 0;

        for (auto & customer : customers) {

            int arrival = customer[0];
            int time = customer[1];
            
            // chef waits for customer
            if (currentTime < arrival)
                currentTime = arrival;

            // Prepare the order
            currentTime += time;

            // Waiting time of the customer
            totalWait += currentTime - arrival;
        }

        return (double)totalWait / customers.size();
    }
};