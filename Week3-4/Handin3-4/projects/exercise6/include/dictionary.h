#include <vector>
#include <utility>
#include <iostream>

template<typename KeyType, typename ValueType>
class Dictionary {
private:
    std::vector<std::pair<KeyType, ValueType>> data;

public:
    // Function to add a key–value pair to the dictionary
    void insert(const KeyType& key, const ValueType& value) {
        // Hvis key allerede findes, opdater value:
        for (auto& pair : data) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
     
        data.emplace_back(key, value);
    }


    void remove(const KeyType& key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
    }

    bool contains(const KeyType& key) const {
        for (const auto& pair : data) {
            if (pair.first == key)
                return true;
        }
        return false;
    }


    ValueType get(const KeyType& key) const {
        for (const auto& pair : data) {
            if (pair.first == key)
                return pair.second;
        }
        throw std::out_of_range("Key not found.");
    }


    size_t size() const {
        return data.size();
    }


    bool isEmpty() const {
        return data.empty();
    }
    void display() const {
        for (const auto& pair : data) {
            std::cout << "(" << pair.first << ", " << pair.second << ")\n";
        }
    }
};