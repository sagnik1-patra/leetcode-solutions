
class StockPrice {
public:
    unordered_map<int, int> prices;
    multiset<int> sortedPrices;
    int latestTimestamp = 0;

    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (prices.count(timestamp)) {
            int oldPrice = prices[timestamp];
            sortedPrices.erase(sortedPrices.find(oldPrice));
        }

        prices[timestamp] = price;
        sortedPrices.insert(price);

        latestTimestamp = max(latestTimestamp, timestamp);
    }

    int current() {
        return prices[latestTimestamp];
    }

    int maximum() {
        return *sortedPrices.rbegin();
    }

    int minimum() {
        return *sortedPrices.begin();
    }
};
