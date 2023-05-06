#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LruCache{
    public:
    LruCache(size_t capacity) { }
    explicit LruCache(int capacity) : capacity_(capacity) { }

    int Lookup(int isbn) {
        auto it = isbn_price_table_.find(isbn);
        if(it == isbn_price_table_.end()) {
            return -1;
        } else {
            int price = it->second.second;
            MoveToFront(isbn, it);
            return price;
        }
    }

    void Insert(int isbn, int price) {
        auto it = isbn_price_table_.find(isbn);
        if(it != isbn_price_table_.end()) {
            MoveToFront(isbn, it);
        } else {
            if(isbn_price_table_.size() == capacity_) {
                isbn_price_table_.erase(lru_queue_.back());
                lru_queue_.pop_back();
            }
            lru_queue_.emplace_front(isbn);
            isbn_price_table_[isbn] = {lru_queue_.begin(), price};
        }
    }

    bool Erase(int isbn) {
        auto it = isbn_price_table_.find(isbn);
        if(it == isbn_price_table_.end()) {
            return false;
        } else {
            lru_queue_.erase(it->second.first);
            isbn_price_table_.erase(it);
            return true;
        }
    }
    private:
    typedef unordered_map<int, pair<list<int>::iterator, int>> Table;
    
    void MoveToFront(int isbn, const Table::iterator& it) {
        lru_queue_.erase(it->second.first);
        lru_queue_.emplace_front(isbn);
        it->second.first = lru_queue_.begin();
    }

    int capacity_;
    Table isbn_price_table_;
    list<int> lru_queue_;
};

int main() {
    // Create an LruCache with capacity for 3 items
    LruCache cache(3);

    // Insert some ISBNs and prices
    cache.Insert(12345, 10);
    cache.Insert(67890, 20);
    cache.Insert(11111, 30);

    // Lookup some prices
    std::cout << "Price for ISBN 12345: " << cache.Lookup(12345) << std::endl;
    std::cout << "Price for ISBN 67890: " << cache.Lookup(67890) << std::endl;

    // Erase an ISBN
    cache.Erase(12345);

    // Insert a new ISBN
    cache.Insert(22222, 40);

    // Lookup the prices again
    std::cout << "Price for ISBN 12345: " << cache.Lookup(12345) << std::endl;
    std::cout << "Price for ISBN 67890: " << cache.Lookup(67890) << std::endl;
    std::cout << "Price for ISBN 11111: " << cache.Lookup(11111) << std::endl;
    std::cout << "Price for ISBN 22222: " << cache.Lookup(22222) << std::endl;

    return 0;
}