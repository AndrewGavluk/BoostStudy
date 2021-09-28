#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/priority_queue.hpp>
#include <iostream>

using namespace boost::heap;

void exersize1()
{
  std::cout << "exersize1:\n";
  priority_queue<int> pq;
  pq.push(2);
  pq.push(3);
  pq.push(1);

  for (int i : pq)
    std::cout << i << '\n';

  priority_queue<int> pq2;
  pq2.push(4);
  std::cout << std::boolalpha << (pq > pq2) << '\n';
}

void exersize2()
{
  std::cout << "\nexersize2:\n";
  binomial_heap<int> bh;
  bh.push(2);
  bh.push(3);
  bh.push(1);

  binomial_heap<int> bh2;
  bh2.push(4);
  bh.merge(bh2);

  for (auto it = bh.ordered_begin(); it != bh.ordered_end(); ++it)
    std::cout << *it << '\n';
  std::cout << std::boolalpha << bh2.empty() << '\n';
}

void exersize3()
{
  std::cout << "\nexersize3:\n";

  binomial_heap<int> bh;
  auto handle = bh.push(2);
  bh.push(3);
  bh.push(1);

  bh.decrease(handle, 3);

  std::cout << bh.top() << '\n';
}


int main()
{
  exersize1();
  exersize2();
  exersize3();

  return 0;
}