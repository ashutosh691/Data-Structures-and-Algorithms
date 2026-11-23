class ProductOfNumbers {
public:
    list<int> l;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        l.push_front(num);
    }
    
    int getProduct(int k) {
        int res = 1;
        for(int i : l) {
            --k;
            res *= i;
            if(!k) return res;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */