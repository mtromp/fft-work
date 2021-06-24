#include "fftpoint.h"

FftPoint::FftPoint(float real, float imag) : std::complex<float>(real, imag)
{
  this->realValue = this->real();
  this->imagValue = this->imag();
}
