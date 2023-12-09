#include <fstream>
#include <iostream>
#include "matrix.hpp"


int* fillMatrix(int* m, char* arg, int numOfTask)
{
  std::ifstream input(arg);
  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  size_t size = rows * cols;
  if (!input.is_open())
  {
    std::cerr << "Error opening file";
    if (numOfTask == 2)
    {
      delete[] m;
    }
    throw;
  }

  try
  {
    for (size_t i = 0; i < size; i++)
    {
      if (m[i] == '\0' && i < size)
      {
        std::cout << "size is not equal to number of elements\n";
        return nullptr;
      }
      input >> m[i];
    }
    return m;
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Error with array\n";
    if (numOfTask == 2)
    {
      delete[] m;
    }
    throw;
  }
}
