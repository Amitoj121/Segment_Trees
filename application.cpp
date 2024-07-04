#include <iostream>
#include <vector>
#include "Segment_Tree.h"

int main() {
    // Example daily closing prices
    std::vector<int> stock_prices = {120, 130, 125, 140, 135};

    // Initialize Segment Tree with stock prices
    Segment_Tree st(stock_prices);
    st.build(0, 0, stock_prices.size() - 1, stock_prices);

    // Example queries
    int start_date = 1; // 0-based index
    int end_date = 3;   // 0-based index

    // Query maximum closing price between start_date and end_date
    int max_price = st.maximum(start_date, end_date);
    std::cout << "Maximum closing price between dates " << start_date << " and " << end_date << ": " << max_price << std::endl;

    // Query minimum closing price between start_date and end_date
    int min_price = st.minimum(start_date, end_date);
    std::cout << "Minimum closing price between dates " << start_date << " and " << end_date << ": " << min_price << std::endl;

    // Query sum of closing prices between start_date and end_date
    int sum_prices = st.sumi(start_date, end_date);
    std::cout << "Total closing prices between dates " << start_date << " and " << end_date << ": " << sum_prices << std::endl;

    return 0;
}
