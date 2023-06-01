#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Trade {
    double profit;
    // other fields here...
};

double calculate_profit_factor(const vector<Trade>& trades) {
    double sum_profit_winning_trades = 0;
    double sum_profit_losing_trades = 0;

    for (const auto& trade : trades) {
        if (trade.profit > 0) {
            sum_profit_winning_trades += trade.profit;
        }
        else {
            sum_profit_losing_trades += abs(trade.profit);
        }
    }

    return sum_profit_winning_trades / sum_profit_losing_trades;
}

double calculate_max_drawdown(const vector<Trade>& trades) {
    double max_so_far = 0;
    double max_drawdown = 0;
    double current_sum = 0;

    for (const auto& trade : trades) {
        current_sum += trade.profit;
        if (current_sum > max_so_far) {
            max_so_far = current_sum;
        }
        else {
            max_drawdown = max(max_drawdown, max_so_far - current_sum);
        }
    }

    return max_drawdown;
}

double averageWinningTrade(vector<Trade>& trades) {
    double sumWinningTrades = 0;
    int countWinningTrades = 0;

    for (auto& trade : trades) {
        if (trade.profit > 0) {
            sumWinningTrades += trade.profit;
            countWinningTrades++;
        }
    }

    if (countWinningTrades == 0) return 0; // avoid division by zero
    return sumWinningTrades / countWinningTrades;
}

double averageLosingTrade(vector<Trade>& trades) {
    double sumLosingTrades = 0;
    int countLosingTrades = 0;

    for (auto& trade : trades) {
        if (trade.profit < 0) {
            sumLosingTrades += trade.profit;
            countLosingTrades++;
        }
    }

    if (countLosingTrades == 0) return 0; // avoid division by zero
    return sumLosingTrades / countLosingTrades;
}

double percentWinning(vector<Trade>& trades) {
    int countWinningTrades = 0;

    for (auto& trade : trades) {
        if (trade.profit > 0) {
            countWinningTrades++;
        }
    }

    if (trades.size() == 0) return 0; // avoid division by zero
    return (double)countWinningTrades / trades.size() * 100; // convert to percent
}

double percentLosing(vector<Trade>& trades) {
    int countLosingTrades = 0;

    for (auto& trade : trades) {
        if (trade.profit < 0) {
            countLosingTrades++;
        }
    }

    if (trades.size() == 0) return 0; // avoid division by zero
    return (double)countLosingTrades / trades.size() * 100; // convert to percent
}


int main() {
    vector<Trade> trades = {
                {111.96},
        {114.96},
        {2.04},
        {6.93},
        {30.58},
        {41.76},
        {-74.53},
        {26.51},
        {117.04},
        {-45.62},
        {-4.5},
        {23.2},
        {32.5},
        {48.3},
        {80.5},
        {-7.7},
        {16},
        {20.6},
        {19.1},
        {16.6},
        {11.15},
        {-13.6},
        {52.3},
        {45.6},
        {-2.85},
        {109.1},
        {1.3},
        {-44.05},
        {16.17},
        {30.14},
        {28.49},
        {-84.72},
        {-20.74},
        {15.34},
        {123.5},
        {7.8},
        {104.65},
        {-66.48},
        {-118.05},
        {1.69},
        {20.15},
        {-1.9},
        {16.64},
        {-64.55},
        {92.17},
        {2.77},
        {60.72},
        {53.95},
        {34.06},
        {-118.72},
        {40.9},
        {49.7},
        {-4.3},
        {-112.9},
        {-115.15},
        {-47.72},
        {10},
        {-18.42},
        {-39.22},
        {-0.95},
        {-46.7},
        {88.6},
        {99.96},
        {52.44},
        {-31.94},
        {111.45},
        {96.9},
        {17.92},
        {-11.76},
        {-16.08},
        {-18.98},
        {-118.35},
        {-3.78},
        {52.36},
        {15.07},
        {65.6},
        {32.32},
        {-4.4},
        {24.65},
        {48.88},
        {-14.37},
        {30.09},
        {15.01},
        {25.18},
        {-122.78},
        {4.23},
        {119.51},
        {-33.7},
        {-120.52},
        {127.84},
        {30.4},
        {13.26},
        {0.31},
        {12.58},
        {9.18},
        {1.87},
        {-13.12},
        {-23.38},
        {-31.84},
        {-2.56},
        {7.28},
        {24.96},
        {60.16},
        {46.72},
        {43.84},
        {12.66},
        {10},
        {-126.4},
        {47.4},
        {64.8},
        {53.9},
        {-35.91},
        {-9.03},
        {44.46},
        {46.62},
        {-75.06},
        {-44.37},
        {18},
        {14},
        {17.46},
        {73.26},
        {20.33},
        {4.56},
        {25.2},
        {16.38},
        {30.82},
        {-90.05},
        {-12.19},
        {29.9},
        {-7.47},
        {-132.08},
        {-44.88},
        {9.22},
        {85.56},
        {10.32},
        {22.56},
        {13.31},
        {4.84},
        {5.06},
        {0.88},
        {37.13},
        {121.59},
        {65.69},
        {5.5},
        {-107.84},
        {63.9},
        {-15.58},
        {89.76},
        {-34.92},
        {-20.67},
        {-27.03},
        {-4.25},
        {-139.23},
        {-1.79},
        {-52.83},
        {77.86},
        {35.4},
        {27.2},
        {63.6},
        {0.1},
        {44.02},
        {24.68},
        {32.13},
        {28.56},
        {39.58},
        {53.57},
        {-1.68},
        {-63.65},
        {38.16},
        {31.44},
        {27.75},
        {44.25},
        {20.75},
        {83.5},
        {-146.38},
        {-32.5},
        {63.75},
        {77.84},
        {19.76},
        {37.57},
        {-96.51},
        {46.49},
        {-49.13},
        {34.04},
        {25.07},
        {24.15},
        {-30.82},
        {20.65},
        {56.76},
        {-103.56},
        {37.03},
        {-4.25},
        {25.17},
        {-145.86},
        {16.9},
        {46.28},
        {-21.52}
    };

    double profit_factor = calculate_profit_factor(trades);
    double max_drawdown = calculate_max_drawdown(trades);

    cout << "Profit Factor: " << profit_factor << "\n";
    cout << "Max Drawdown: " << max_drawdown << "\n";
    cout << "Average Winning Trade: $" << averageWinningTrade(trades) << "\n";
    cout << "Average Losing Trade: $" << averageLosingTrade(trades) << "\n";
    cout << "Percent Winning: " << percentWinning(trades) << "%\n";
    cout << "Percent Losing: " << percentLosing(trades) << "%\n";

    return 0;
}
