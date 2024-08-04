//
// Created by Kesu Peterill on 8/3/2024.
//
#include "all.h"

class RandomizedSet {
public:
    unordered_map<int, int> seeds;
    vector<int> storage;
    bool insert(int val) {
        if (seeds.contains(val))
            return false;
        storage.push_back(val);
        seeds.insert({val, storage.size()-1});
        return true;
    }

    bool remove(int val) {
        if (!seeds.contains(val))
            return false;
        int index = seeds.at(val);
        storage.at(index) = storage.back();
        seeds.at(storage.at(index)) = index;
        storage.pop_back();
        seeds.erase(val);
        return true;
    }

    int getRandom() {
        return storage.at(rand()%storage.size());
    }
};