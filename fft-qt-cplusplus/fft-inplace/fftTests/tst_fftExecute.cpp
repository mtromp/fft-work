#include "inplacefft.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <complex>
#include <vector>

#define _USE_MATH_DEFINES

#include <cmath>


using namespace testing;


bool compare_complex(std::complex<float> x, std::complex<float> y, float epsilon = 0.01f){
   if((fabs(x.real() - y.real()) < epsilon) && (fabs(x.imag() - y.imag() < epsilon)))
   {
      return true; //they are same
   }
   else
   {
      return false; //they are not same
   }
}

MATCHER_P(ComplexNear, expected, "Expected %(expected): ")
{
  return compare_complex(arg, expected, 0.001);
}

class FFTExecuteTest: public Test
{
protected:
  FFTExecuteTest() {}
  ~FFTExecuteTest() {}

  InPlaceFFT myFFT;
};

TEST_F(FFTExecuteTest, FFTProducesExpectedResultsInPlace)
{
  std::vector<std::complex<float> > inputData;
  std::vector<std::complex<float> > expectedData;

  float cosineValue;
  float twoPiN = 2.0 * M_PI / 16.0;

  for (int i = 0; i < 16; i++)
  {
    cosineValue = std::cos(twoPiN*i);
    inputData.push_back(std::complex<float>(cosineValue, 0.0));
    expectedData.push_back(std::complex<float>(cosineValue, 0.0));
  }

  EXPECT_THAT(std::complex<float>(1.0,0.0),ComplexNear(std::complex<float>(1.1,0.0)));

 }

