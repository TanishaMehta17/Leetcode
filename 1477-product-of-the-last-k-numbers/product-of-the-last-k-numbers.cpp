class ProductOfNumbers {
public:
    vector<int> prefix;
    int p = 1, i = 0;
    
    ProductOfNumbers() {
        prefix.push_back(1); 
    }
    
    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
            p = 1;
            i = 0;
        } else {
            p *= num;
            prefix.push_back(p);
            i++;
        }
    }
    
    int getProduct(int k) {
        if (k > i) return 0;
        return prefix[i] / prefix[i - k];
    }
};
