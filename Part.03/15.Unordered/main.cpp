#include "libs/animal.hpp"
#include <iostream>


void exersize1()
{
  std::cout << "exersize1\n";
  const auto animals {CreateAnimal<animal_unordered_set_1>()};

  for (const std::string &s : animals)
    std::cout << s << '\n';

  std::cout << animals.size() << '\n';
  std::cout << animals.max_size() << '\n';

  std::cout << std::boolalpha << (animals.find("cat") != animals.end()) << '\n';
  std::cout << animals.count("shark") << '\n';
}

void exersize2()
{
  std::cout << "exersize2\n";
  auto animals {CreateAnimal<animal_unordered_map_2>()};

  for (const auto &p : animals)
    std::cout << p.first << ";" << p.second << '\n';

  std::cout << animals.size() << '\n';
  std::cout << animals.max_size() << '\n';

  std::cout << std::boolalpha << (animals.find("cat") != animals.end()) << '\n';
  std::cout << animals.count("shark") << '\n';
}

void exersize3()
{
  std::cout << "exersize3\n";
  const auto animals {CreateAnimal<animal_unordered_set_3>()};
}


int main()
{
    exersize1();
    exersize2();
    exersize3();

    return 0;
}