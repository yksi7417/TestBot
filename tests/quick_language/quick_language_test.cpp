#include "gtest/gtest.h"
#include <stdlib.h>
#include "Poco/HashMap.h"

TEST(TestQuickLanguage, SolvingTheMysteryOfMapSizes) {
    std::map<int, std::string> a_map;
    EXPECT_EQ(0, a_map.size());
    a_map.emplace(123,"onetwothree");
    EXPECT_EQ(1, a_map.size());
    a_map.erase(123);
    EXPECT_EQ(a_map.end(), a_map.find(123));
    EXPECT_EQ(0, a_map.size());
}

class Node {
public:
    int key; 
    std::string value; 
    Node(int key_, std::string value_) : key(key_), value(value_) {}
};

TEST(TestQuickLanguage, SolvingTheMysteryOfMapSizesWithPointersToObject) {
    std::map<int, Node*> a_map;
    EXPECT_EQ(0, a_map.size());
    a_map.emplace(123, new Node(123,"onetwothree"));
    a_map.emplace(1, new Node(1,"one"));
    a_map.emplace(2, new Node(2,"two"));
    a_map.emplace(3, new Node(3,"three"));
    EXPECT_EQ(4, a_map.size());
    a_map.erase(123);
    EXPECT_EQ(a_map.end(), a_map.find(123));
    EXPECT_EQ(3, a_map.size());
}

TEST(TestQuickLanguage, PocoHashTale) {
    Poco::HashMap<int, std::string> map;
    map.insert(std::make_pair(1, "one"));
    map.insert(std::make_pair(2, "two"));
    map.insert(std::make_pair(3, "three"));
    EXPECT_EQ(3, map.size());

    // Lookup a value by key
    auto value = map.find(2);
    EXPECT_NE(map.end(), value);
    EXPECT_EQ(2, value->first);
    EXPECT_EQ("two", value->second);

    // Remove a key-value pair from the map
    map.erase(1);

    EXPECT_EQ(2, map.size());
}

TEST(TestQuickLanguage, TestUnOrderedMapFromStandardizedLibrary) {
    std::unordered_map<int, std::string> map;
    map.emplace(1, std::string("one"));
    map.emplace(2, "two");
    map.emplace(3, "three");
    EXPECT_EQ(3, map.size());

    // Lookup a value by key
    auto value = map.find(2);
    EXPECT_NE(map.end(), value);
    EXPECT_EQ(2, value->first);
    EXPECT_EQ("two", value->second);

    // Remove a key-value pair from the map
    map.erase(1);

    EXPECT_EQ(2, map.size());
}

TEST(TestQuickLanguage, TestUnOrderedMapUsingUniquePointers) {
    std::unordered_map<int, std::unique_ptr<std::string>> map;
    map.emplace(1, std::make_unique<std::string>(std::string("one")));
    map.emplace(2, std::make_unique<std::string>(std::string("two")));
    map.emplace(3, std::make_unique<std::string>(std::string("three")));
    EXPECT_EQ(3, map.size());

    // Lookup a value by key
    {
        auto value = map.find(2);
        EXPECT_NE(map.end(), value);
        EXPECT_EQ(2, value->first);
        EXPECT_EQ("two", *(value->second));
    }

    // Remove a key-value pair from the map
    map.erase(1);
    EXPECT_EQ(2, map.size());

    {
        auto value = map.find(1);
        EXPECT_EQ(map.end(), value);
    }

    {
        auto value = map.find(3);
        EXPECT_NE(map.end(), value);
        EXPECT_EQ(3, value->first);
        EXPECT_EQ("three", *(value->second));
    }
}
