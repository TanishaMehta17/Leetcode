class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to store the gain and class information
        priority_queue<pair<double, pair<int, int>>> pq;
        double sum = 0;

        // Initialize the priority queue with the current gain for each class
        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, {pass, total}});
        }

        // Distribute the extra students
        while (extraStudents > 0) {
            auto top = pq.top();
            pq.pop();
            double currentGain = top.first;
            int pass = top.second.first;
            int total = top.second.second;

            // Add an extra student to this class
            pass++;
            total++;
            extraStudents--;

            // Calculate the new gain and push the updated class back
            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({newGain, {pass, total}});
        }

        // Calculate the final average ratio
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};