#ifndef FFTPOINT_H
#define FFTPOINT_H

#include <complex>

class FftPoint : public std::complex<float>
{
public:
  FftPoint(float real=0.0, float imag=0.0);

  float realValue, imagValue;
};

#endif // FFTPOINT_H
