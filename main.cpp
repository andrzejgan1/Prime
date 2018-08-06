#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    std::vector<int> numbers(10);
    std::vector<int> prime;
    std::iota(numbers.begin(), numbers.end(), 1);
    std::transform(numbers.begin(), numbers.end(),
                    std::back_inserter(prime),
                    [](int a){
                        return a%2;
                    });
    for(auto iter : prime)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}
