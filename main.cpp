#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>
#include <stdexcept>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

int main()
{
    try
    {
    std::srand ( unsigned ( std::time(0) ) );
    int n, m;
    std::cin >> n;
    std::cin >> m;
    if (n <= 0 || n > m) throw std::invalid_argument("Bad data input");
    std::vector<int> numbers(m+1);
    std::iota(numbers.begin(), numbers.end(), 0);
//take n random numbers form 0 to m
    std::random_shuffle(numbers.begin(), numbers.end());
    numbers.resize(n);
    std::sort(numbers.begin(), numbers.end());
//give prime numbers in range less than M
    std::vector<int> prime(m-1);
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
//create map
    std::map<int,std::vector<int>> map;
    std::map<int,int> mapInt;
    std::vector<int> h;
    std::transform(prime.begin(), prime.end(),
                prime.begin(),
                std::inserter(map, map.begin()),
                [& numbers, & map, & h](int p1, int p2) {
                    h.clear();
                    std::copy_if(numbers.begin(), numbers.end(),
                             std::back_inserter(h),
                             [& p1](int n) {
                                return (n%p1==0 && n>=p1); 
                             });
                    return std::make_pair(p1,h);
                });
//show result
    std::cout << "Random N numbers from M:" << std::endl;
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nMap:" << std::endl;
    std::transform(map.begin(), map.end(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](auto a)
                   {
                        return a.first;
                   });

    for (auto iter : map)
    {
        std::cout << iter.first << "  - > ";
        for (auto iterV : iter.second) 
        {
            std::cout << " " << iterV; 
        }
        std::cout << std::endl;
    }
    }
    catch(const std::invalid_argument & exc)
    {
        std::cout << exc.what() << std::endl;
    }
    return 0;
}
