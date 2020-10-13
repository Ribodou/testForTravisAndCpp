#include <iostream>
#include <compare>

// g++ compileOnlycpp20.cpp -o out -std=c++20
struct Player {
    std::string name;
    int lvl;
 
    std::strong_ordering operator<=>(const Player& that) { 
        if(auto ret = name <=> that.name; ret != 0) 
            return ret;
        if(auto ret = lvl <=> that.lvl; ret != 0)
            return ret;
        return std::strong_ordering::equal;
    }
};
 
int main() {
    Player p1{"A", 2};
    Player p2{"B", 5};
 
    std::cout << std::boolalpha << (p1 <=> p2 == 0) << '\n';
    std::cout << (p1 <= p2) << ' ' << (p1 >= p2) << '\n';
}
