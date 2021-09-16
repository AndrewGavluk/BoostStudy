#include "animal.hpp"

template <typename T>
T CreateAnimal ()
{
  T animals;
  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"dog", 4});
  animals.insert({"spider", 8});
return animals;
}

template animal_bimap_1_2 CreateAnimal ();
template animal_bimap_3 CreateAnimal ();
template animal_bimap_4 CreateAnimal ();
template animal_bimap_5 CreateAnimal ();
