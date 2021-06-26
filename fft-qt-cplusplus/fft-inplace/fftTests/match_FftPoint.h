#ifndef MATCH_FFTPOINT_H
#define MATCH_FFTPOINT_H

#include "fftpoint.h"

#include <gmock/gmock-matchers.h>

using namespace ::testing;

Matcher<float> MatchFloat(float expected)
{
  return FloatNear(expected, 0.001);
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
  return MatchFftPoint(MatchFloat(expectedPoint.realValue), MatchFloat(expectedPoint.imagValue));
}
#endif // MATCH_FFTPOINT_H
