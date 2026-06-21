class Cashier {
public:
    unordered_map<int, int> priceMap;
    int n, discount;
    int customerCount;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        customerCount = 0;
        
        for (int i = 0; i < products.size(); i++) {
            priceMap[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        
        // Step 1: calculate bill
        for (int i = 0; i < product.size(); i++) {
            total += priceMap[product[i]] * amount[i];
        }
        
        // Step 2: increment customer count
        customerCount++;
        
        // Step 3: apply discount if nth customer
        if (customerCount % n == 0) {
            total = total * (100 - discount) / 100.0;
        }
        
        return total;
    }
};