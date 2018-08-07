#include<iostream>
#include<algorithm>
#include<vector>


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> prime(n-1);
    std::vector<int> p;
    std::iota(prime.begin(), prime.end(), 2);
    auto iterEnd = prime.end();
    std::transform(prime.begin(), iterEnd,
            std::back_inserter(p),
            [& iterEnd, & prime](int pi){
                iterEnd = std::remove_if(prime.begin(), iterEnd,
                    [& pi](int number){
                            return ((number>pi) && (number%pi == 0));
                    });
                    return 0;
                });
    prime.resize(std::distance(prime.begin(), iterEnd));

    for (auto iter : prime)
    {
        std::cout << iter << std::endl;
    }
    return 0;
}
