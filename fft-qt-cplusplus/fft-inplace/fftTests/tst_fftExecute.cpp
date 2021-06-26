#include "inplacefft.h"
#include "fftpoint.h"

#include "match_FftPoint.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <complex>
#include <vector>

#define _USE_MATH_DEFINES

#include <cmath>


using namespace ::testing;

class FFTExecuteTest: public Test
{
protected:
  FFTExecuteTest() {}
  ~FFTExecuteTest() {}

  InPlaceFFT myFFT;
};
TEST_F(FFTExecuteTest, FFTProducesExpectedResultsInPlace)
{
  std::vector<FftPoint> inputData;
  std::vector<FftPoint> expectedData;
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(2.414214, -1.000002));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(2.999998, 2.414216));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(0.999618, 2.413216));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(1.585786, -1.000002));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(1.585786, 1.000002));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(1.000002, -2.414216));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(3.000382, -2.414216));
  expectedData.push_back(FftPoint(0.0, 0.0));
  expectedData.push_back(FftPoint(2.414214, 1.000002));

  float cosineValue;
  float twoPiN = 2.0 * M_PI / 16.0;

  for (int i = 0; i < 16; i++)
  {
    cosineValue = std::cos(twoPiN*i);
    inputData.push_back(FftPoint(cosineValue, 0.0));
  }

  myFFT.Execute(inputData);

  ASSERT_EQ(inputData.size(), expectedData.size());

  for (uint i = 0; i < inputData.size(); i++)
  {
    EXPECT_THAT(inputData[i],MatchFftPoint(expectedData[i])) << "Vectors x and y differ at index " << i;
  }

 }

