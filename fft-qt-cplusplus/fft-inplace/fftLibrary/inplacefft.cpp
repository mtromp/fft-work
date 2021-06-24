#include "inplacefft.h"

InPlaceFFT::InPlaceFFT()
{

}

void InPlaceFFT::Execute(std::vector<FftPoint>& dataArray)
{
  int fftSize = dataArray.size();
  // need to create the tables from scratch
  delete cosTable;
  delete sinTable;
  InitializeSinCosTables(fftSize);
}

void InPlaceFFT::InitializeSinCosTables(int theSize)
{
  cosTable = new std::vector<float>;
  sinTable = new std::vector<float>;
  float twoPiN = 2.0 * M_PI / theSize;

  for (int i = 0; i < theSize; i++)
  {
    cosTable->push_back(std::cos(twoPiN * i));
    sinTable->push_back(std::sin(twoPiN * i));
  }
}
