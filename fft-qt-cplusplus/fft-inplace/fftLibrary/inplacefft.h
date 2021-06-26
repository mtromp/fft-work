#ifndef INPLACEFFT_H
#define INPLACEFFT_H

#include "fftpoint.h"

#include <complex>
#include <vector>

class InPlaceFFT
{
public:
  InPlaceFFT();

  void Execute(std::vector<FftPoint>& dataArray);

private:

  void InitializeSinCosTables(int theSize);
  void DoFFT(std::vector<FftPoint>& dataArray);
  int ReverseWidthBits(int value, int width);
  void Unscramble(std::vector<FftPoint>& dataArray);
  std::vector<float> * sinTable = nullptr;
  std::vector<float> * cosTable = nullptr;
};

#endif // INPLACEFFT_H
