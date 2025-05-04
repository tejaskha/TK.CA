// #include <iostream>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int profit, weight;
    double ratio;
};

// Compare function to sort items by decreasing profit/weight ratio
bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    for (auto &item : items)
    {
        item.ratio = (double)item.profit / item.weight;
    }

    sort(items.begin(), items.end(), cmp);

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= remainingCapacity)
        {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        }
        else
        {
            totalProfit += items[i].ratio * remainingCapacity;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ":\n";
        cout << "  Profit: ";
        cin >> items[i].profit;
        cout << "  Weight: ";
        cin >> items[i].weight;
    }

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "\nMaximum profit: " << maxProfit << endl;

    return 0;
}
