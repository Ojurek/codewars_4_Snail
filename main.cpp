#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    std::vector<int> result;
    std::vector<std::vector<int>> snail_copy = snail_map;
    int expected_size = snail_map.size() * snail_map.size();

    while (snail_map.size() == 0)
    {
        return {};
    }

    while (snail_map.size() == 1)
    {
        return snail_map[0];
    }

    while (snail_copy.size() > 0)
    {
        for (int i = 0; i < snail_copy[0].size(); i++)
        {
            result.push_back(snail_copy[0][i]);
        }
        snail_copy.erase(snail_copy.begin());

        if (result.size() == expected_size)
            break;

        for (int i = 0; i < snail_copy.size(); i++)
        {
            result.push_back(snail_copy[i].back());

            snail_copy[i].pop_back();
        }

        if (result.size() == expected_size)
            break;

        for (int i = (snail_copy[snail_copy.size() - 1].size() - 1); i >= 0; i--)
        {
            result.push_back(snail_copy[snail_copy.size() - 1][i]);
        }
        snail_copy.pop_back();

        if (result.size() == expected_size)
            break;

        for (int i = (snail_copy.size() - 1); i >= 0; i--)
        {
            result.push_back(snail_copy[i].front());
            snail_copy[i].erase(snail_copy[i].begin());
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> v;
    std::vector<int> expected;

    v = {{}};
    expected = {};
    assert(snail(v) == expected);

    v = {{1}};
    expected = {1};
    assert(snail(v) == expected);

    v = {{1, 2}, {4, 3}};
    expected = {1, 2, 3, 4};
    assert(snail(v) == expected);

    v = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(snail(v) == expected);

    v = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    assert(snail(v) == expected);

    std::cout << "done" << std::endl;
    return 0;
}
