#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    const char* id;   // Changed from char to const char*
    int deadline;
    int profit;
};

// Comparison function to sort jobs by profit (descending)
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    Job jobs[] = {{"j1", 2, 60}, {"j2", 1, 100}, {"j3", 3, 20}, {"j4", 2, 40}, {"j5", 1, 20}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    const char* slot[10];
    bool filled[10] = {false};

    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = "-";
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(jobs[i].deadline, maxDeadline) - 1; j >= 0; j--)
        {
            if (!filled[j])
            {
                slot[j] = jobs[i].id;
                filled[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (filled[i])
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
