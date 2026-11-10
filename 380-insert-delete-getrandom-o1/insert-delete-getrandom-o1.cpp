
class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        arr.push_back(val);
        mp[val] = arr.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = arr.back();

        arr[index] = last;
        mp[last] = index;

        arr.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int index = rand() % arr.size();
        return arr[index];
    }
};
