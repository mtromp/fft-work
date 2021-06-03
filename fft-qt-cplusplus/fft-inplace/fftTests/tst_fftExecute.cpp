#include "inplacefft.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include <complex>
#include <vector>

#define _USE_MATH_DEFINES

#include <cmath>


using namespace ::testing;

class FftPoint : public std::complex<float>
{
public:
  FftPoint(float real=0.0, float imag=0.0) : std::complex<float>(real, imag){
    this->realValue = this->real();
    this->imagValue = this->imag();
  }

  float realValue;
  float imagValue;
};

Matcher<float> MatchFloat(float expected)
{
  return FloatNear(expected, 0.0001);
}

Matcher<FftPoint> MatchFftPoint(Matcher<float> mReal, Matcher<float> mImag)
{
  return AllOf(
        Field(&FftPoint::realValue, mReal),
        Field(&FftPoint::imagValue, mImag)
        );
}

Matcher<FftPoint> MatchFftPoint(const FftPoint& expectedPoint)
{
  return MatchFftPoint(expectedPoint.realValue, expectedPoint.imagValue);
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
  std::vector<FftPoint > inputData;
  std::vector<FftPoint > expectedData;

  float cosineValue;
  float twoPiN = 2.0 * M_PI / 16.0;

  for (int i = 0; i < 16; i++)
  {
    cosineValue = std::cos(twoPiN*i);
    inputData.push_back(FftPoint(cosineValue, 0.0));
    expectedData.push_back(FftPoint(cosineValue, 0.0));
  }

  EXPECT_THAT(FftPoint(1.0,0.0),MatchFftPoint(FftPoint(1.002,0.0)));

 }

