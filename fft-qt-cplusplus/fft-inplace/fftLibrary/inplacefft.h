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
};

#endif // INPLACEFFT_H
