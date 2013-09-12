// test@10130
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ITEM_N = 1001;
const int W_LIM = 31;

const int  DIAGONAL = 1;
const int  LEFT = 0;

struct Item
{
	int value, weight;
};

int cost[ITEM_N+1][W_LIM+1];
int from[ITEM_N+1][W_LIM+1];

// limit : “ü‚ê•¨‚Ì‘å‚«‚³
int knapsack(const int limit, vector<Item> &items, vector<int> &path)
{
	fill(cost[0], cost[0]+W_LIM, 0);
	fill(from[0], from[0]+W_LIM, DIAGONAL);

	int n = items.size();
	for (int i = 1; i <= n; i++) cost[i][0] = 0;

	for (int i=1; i <= n; i++) {
		for (int w=1; w <= limit; w++) {
			if (items[i-1].weight <= w) {
				int nw = w - items[i-1].weight;
				if (items[i-1].value + cost[i-1][nw] > cost[i-1][w]) {
					cost[i][w] = items[i-1].value + cost[i-1][nw];
					from[i][w] = DIAGONAL;
				} else {
					cost[i][w] = cost[i-1][w];
					from[i][w] = LEFT;
				}
			} else {
				cost[i][w] = cost[i-1][w];
				from[i][w] = LEFT;
			}
		}
	}

	// path‚ð‹‚ß‚é
	path.clear();
	int w = limit;
	for (int i = n; i >=1; i--){
		if (from[i][w] == DIAGONAL){
			path.push_back(i);
			w -= items[i-1].weight;
		}
	}
	reverse(path.begin(), path.end());

	return cost[n][limit];
}