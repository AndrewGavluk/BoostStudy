#include "libs/animal.hpp"
#include <iostream>


void exersize1()
{
  const auto animals {CreateAnimal<animal_multi_1_2>()};
  std::cout << animals.count("cat") << '\n';
  const animal_multi_1_2::nth_index<1>::type &legs_index = animals.get<1>();
  std::cout << legs_index.count(8) << '\n';
}

void exersize2()
{
  auto animals {CreateAnimal<animal_multi_1_2>()};
  auto &legs_index = animals.get<1>();
  auto it = legs_index.find(4);
  legs_index.modify(it, [](animal &a){ a.name = "dog"; });
  std::cout << animals.count("dog") << '\n';
}

void exersize3()
{
  const auto animals {CreateAnimal<animal_multi_3>()};
  auto &legs_index = animals.get<1>();
  std::cout << legs_index.count(4) << '\n';
}

void exersize4()
{
  const auto animals {CreateAnimal<animal_multi_4>()};

  auto &legs_index = animals.get<1>();
  auto it = legs_index.lower_bound(4);
  auto end = legs_index.upper_bound(8);
  for (; it != end; ++it)
    std::cout << it->name << '\n';

  const auto &rand_index = animals.get<2>();
  std::cout << rand_index[0].name << '\n';
}


void exersize5()
{
  const auto animals {CreateAnimal<animal_multi_5>()};
  std::cout << animals.begin()->name() << '\n';
  const auto &name_index = animals.get<1>();
  std::cout << name_index.count("shark") << '\n';
}

int main()
{
    exersize1();
    exersize2();
    exersize3();
    exersize4();
    exersize5();
}