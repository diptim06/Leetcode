class ProductOfNumbers {
public:
    
    ProductOfNumbers() {
        
    }
    vector<int> a;
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int n = a.size();

        int prod = 1;

        for(int i = n-1; i>=n-k; i--)
        {
            prod *= a[i];
        }

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */