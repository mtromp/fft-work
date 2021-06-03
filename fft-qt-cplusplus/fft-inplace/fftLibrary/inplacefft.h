#ifndef INPLACEFFT_H
#define INPLACEFFT_H

#include <complex>
#include <vector>

class InPlaceFFT
{
public:
  InPlaceFFT();

  void Execute(std::vector<std::complex<float> >* dataArray);
};

#endif // INPLACEFFT_H
