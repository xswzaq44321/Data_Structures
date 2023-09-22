#include "../Priority Queue/SelectivePriorityQueue.hpp"

#include <cassert>
#include <iostream>
#include <vector>

struct Ent {
    Ent(int val, const std::vector<int>& data)
        : val(val),
          data(data)
    {
        std::cout << "default ctor" << std::endl;
    }
    Ent(const Ent& other)
        : val(other.val),
          data(other.data)
    {
        std::cout << "copy ctor" << std::endl;
    }
    Ent(Ent&& other)
        : val(std::move(other.val)),
          data(std::move(other.data))
    {
        std::cout << "move ctor" << std::endl;
    }
    int val;
    std::vector<int> data;
    bool operator<(const Ent& other) const { return val < other.val; }
};

bool operator<(const Ent& lhs, int val)
{
    return lhs.val < val;
}
bool operator<(int val, const Ent& rhs)
{
    return val < rhs.val;
}

int main()
{
    SelectivePriorityQueue<Ent, std::less<>> spq;
    Ent bar = {5, {}};
    Ent const bar2 = {6, {}};
    spq.push(bar);
    spq.push(bar2);
    spq.push({3, {1, 2, 3}});

    std::cout << spq.top().val << std::endl;
    spq.pop();

    std::cout << spq.top().val << std::endl;
    auto it = spq.lower_bound({3, {1, 2, 3}});
    spq.erase(it);

    std::cout << spq.top().val << std::endl;
    auto it2 = spq.lower_bound(5);
    spq.erase(it2);
}