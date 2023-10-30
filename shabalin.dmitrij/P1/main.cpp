#include "loc_max.hpp"
#include <iostream>
#include <stdexcept>

using namespace shabalin;

int main()
{
  int behindNum = 1, curNum = 1,  nextNum = 1, Number = 1;
  std::cin >> behindNum;
  if (!std::cin)
  {
    std::cerr << "Is not sequence" << std::endl;
    return 1;
  }
  else if (behindNum == 0)
  {
    std::cerr << "must be no zero sequence" << std::endl;
    return 2;
  }
  std::cin >> curNum;
  if (!std::cin)
  {
    std::cerr << "Is not sequence" << std::endl;
    return 1;
  }
  else if (curNum == 0)
  {
    std::cerr << "Can not be calculated" << std::endl;
    return 0;
  }
  std::cin >> nextNum;
  if (!std::cin)
  {
    std::cerr << "Is not sequence" << std::endl;
    return 1;
  }
  else if (nextNum == 0)
  {
    std::cerr << "Can not be calculated" << std::endl;
    return 0;
  }

  LocMax counter(behindNum,curNum,nextNum);

  do
  {
    std::cin >> Number;
    if (!std::cin)
    {
      std::cerr << "is not sequence" << std::endl;
      return 1;
    }
    if (nextNum != 0)
    {
      try
      {
        counter(nextNum);
      }
      catch(const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << std::endl;
        return 2;
      }
    }
  }
  while (Number != 0);

  std::cout << counter() << std::endl;
}
