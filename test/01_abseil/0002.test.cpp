// Abseil Containers
// ref: https://abseil.io/docs/cpp/guides/container#abseil-containers
#include <string>
#include <vector>
#include <absl/container/btree_map.h>
#include <absl/container/btree_set.h>
#include <absl/container/fixed_array.h>
#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>
#include <absl/container/hash_container_defaults.h>
#include <absl/container/inlined_vector.h>
#include <absl/container/node_hash_map.h>
#include <absl/container/node_hash_set.h>

int main()
{
    {
        // Examples using node_hash_set and node_hash_map are equivalent

        // Default constructor
        // No allocation for the table's elements is made.
        [[maybe_unused]] absl::flat_hash_set<std::string> set1;

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map1;

        // Initializer List constructor
        [[maybe_unused]] absl::flat_hash_set<std::string> set2 = {
            {"huey"},
            {"dewey"},
            {"louie"},
        };

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map2 =
            {
                {1, "huey"},
                {2, "dewey"},
                {3, "louie"},
            };

        // Copy constructor
        [[maybe_unused]] absl::flat_hash_set<std::string> set3(set2);

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map3(map2);

        // Copy assignment operator
        // Hash functor and Comparator are copied as well
        [[maybe_unused]] absl::flat_hash_set<std::string> set4;
        set4 = set3;

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map4;
        map4 = map3;

        // Move constructor
        // Move is guaranteed efficient
        [[maybe_unused]] absl::flat_hash_set<std::string> set5(std::move(set4));

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map5(std::move(map4));

        // Move assignment operator
        // May be efficient if allocators are compatible
        [[maybe_unused]] absl::flat_hash_set<std::string> set6;
        set6 = std::move(set5);

        [[maybe_unused]] absl::flat_hash_map<int, std::string> map6;
        map6 = std::move(map5);

        // Range constructor
        std::vector<std::string> v1 = {"a", "b"};
        [[maybe_unused]] absl::flat_hash_set<std::string> set7(v1.begin(), v1.end());

        std::vector<std::pair<int, std::string>> v2 = {{1, "a"}, {2, "b"}};
        [[maybe_unused]] absl::flat_hash_map<int, std::string> map7(v2.begin(), v2.end());
    }
    {
        absl::flat_hash_map<int, std::string> numbers =
            {{1, "one"}, {2, "two"}, {3, "three"}};
        numbers.try_emplace(4, "four");

        absl::flat_hash_map<std::string, std::unique_ptr<std::string>> strings;
        strings.try_emplace("foo", absl::make_unique<std::string>("bar"));
    }
    {
        // Examples using btree_multimap and btree_multiset are equivalent

        // Default constructor
        // No allocation for the B-tree's elements is made.
        absl::btree_set<std::string> set1;

        absl::btree_map<int, std::string> map1;

        // Initializer List constructor
        absl::btree_set<std::string> set2 = {
            {"huey"},
            {"dewey"},
            {"louie"},
        };

        absl::btree_map<int, std::string> map2 =
            {
                {1, "huey"},
                {2, "dewey"},
                {3, "louie"},
            };

        // Copy constructor
        absl::btree_set<std::string> set3(set2);

        absl::btree_map<int, std::string> map3(map2);

        // Copy assignment operator
        // Hash functor and Comparator are copied as well
        absl::btree_set<std::string> set4;
        set4 = set3;

        absl::btree_map<int, std::string> map4;
        map4 = map3;

        // Move constructor
        // Move is guaranteed efficient
        absl::btree_set<std::string> set5(std::move(set4));

        absl::btree_map<int, std::string> map5(std::move(map4));

        // Move assignment operator
        // May be efficient if allocators are compatible
        absl::btree_set<std::string> set6;
        set6 = std::move(set5);

        absl::btree_map<int, std::string> map6;
        map6 = std::move(map5);

        // Range constructor
        std::vector<std::string> v1 = {"a", "b"};
        absl::btree_set<std::string> set7(v1.begin(), v1.end());

        std::vector<std::pair<int, std::string>> v2 = {{1, "a"}, {2, "b"}};
        absl::btree_map<int, std::string> map7(v2.begin(), v2.end());
    }
}
