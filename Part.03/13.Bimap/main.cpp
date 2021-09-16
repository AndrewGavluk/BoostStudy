#include "libs/animal.hpp"
#include <iostream>


void exersize1()
{
  std::cout << "exersize1\n";
  const animal_bimap_1_2 animals{CreateAnimal<animal_bimap_1_2>()};
  std::cout << animals.left.count("cat") << '\n';
  std::cout << animals.right.count(8) << '\n';
}

void exersize2()
{
  std::cout << "exersize2\n";
  const animal_bimap_1_2 animals{CreateAnimal<animal_bimap_1_2>()};
  for (auto it = animals.begin(); it != animals.end(); ++it)
      std::cout << it->left << " has " << it->right << " legs\n";
}

void exersize3()
{
  std::cout << "exersize3\n";
  const animal_bimap_3 animals{CreateAnimal<animal_bimap_3>()};
  std::cout << animals.left.count("spider") << '\n';
  std::cout << animals.right.count(8) << '\n';
}

void exersize4()
{
  std::cout << "exersize4\n";
  const animal_bimap_4 animals{CreateAnimal<animal_bimap_4>()};
  std::cout << animals.left.count("dog") << '\n';
  std::cout << animals.right.count(4) << '\n';
}

void exersize5()
{
  std::cout << "exersize5\n";
  const animal_bimap_5 animals{CreateAnimal<animal_bimap_5>()};
  auto it = animals.left.find("cat");
 // animals.left.modify_key(it, boost::bimaps::_key = "dog");
  std::cout << it->first << '\n';
}

int main()
{
    exersize1();
    exersize2();
    exersize3();
    exersize4();
    exersize5();
}