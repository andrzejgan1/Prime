#include<iostream>
#include<algorithm>
#include<vector>


int main()
{
    std::vector<int> numbers(1000);
    std::vector<int> prime;
    std::iota(numbers.begin(), numbers.end(), 2);
    std::transform(numbers.begin(), numbers.end(),
                    std::back_inserter(prime),
                    [](int a){
                    std::vector<int> v1(a-2);
                    std::vector<int> v2;
                    std::iota(v1.begin(), v1.end(), 2);
                    std::transform((begin(v1))++, v1.end(),
                            std::back_inserter(v2),
                            [a](int b) {return  a%b==0;});
                    return std::count(v2.begin(), v2.end(), 1)==0? a:0;
                    });
    for(auto iter : prime)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}
