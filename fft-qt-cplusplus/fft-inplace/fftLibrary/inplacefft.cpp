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
  this->DoFFT(dataArray);

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

int InPlaceFFT::ReverseWidthBits(int value, int width)
{
  int result = 0;
  for (int i = 0; i < width; i++)
  {
    result = (result << 1) | (value & 1);
    value >>=1;
  }
  return result;
}

void InPlaceFFT::Unscramble(std::vector<FftPoint>& dataArray)
{
  int j;
  int fftSize = dataArray.size(); //N in javascript code
  int bitWidth = (int)log2(fftSize);
  float temp;
  for (int i = 0; i < fftSize; i++)
  {
    j = ReverseWidthBits(i, bitWidth);
    if (j > i)
    {
      temp = dataArray.at(i).realValue;
      dataArray.at(i).realValue = dataArray.at(j).realValue;
      dataArray.at(j).realValue = temp;
      temp = dataArray.at(i).imagValue;
      dataArray.at(i).imagValue = dataArray.at(j).imagValue;
      dataArray.at(j).imagValue = temp;
    }
  }
}
void InPlaceFFT::DoFFT(std::vector<FftPoint>& dataArray)
{
  int fftSize = dataArray.size(); //N in javascript code
  int bitWidth = (int)log2(fftSize);
  int index = 0;
  int pass = 1;
  int nspan, twiddleIndex;
  float cosTwiddle, sinTwiddle, tempReal, tempImag;

  for (int stride = fftSize>>1; stride > 0; stride>>=1)
  {
    for (int submatrix = 0; submatrix < (fftSize>>1)/stride; submatrix++)
    {
      for (int node = 0; node < stride; node++)
      {
        twiddleIndex = ReverseWidthBits(index >> (bitWidth - pass), bitWidth);
        cosTwiddle = cosTable->at(twiddleIndex);
        sinTwiddle = sinTable->at(twiddleIndex);

        nspan = index + stride;
        tempReal = dataArray.at(nspan).realValue*cosTwiddle + dataArray.at(nspan).imagValue*sinTwiddle;
        tempImag = dataArray.at(nspan).imagValue*cosTwiddle + dataArray.at(nspan).realValue*sinTwiddle;

        dataArray.at(nspan).realValue = dataArray.at(index).realValue - tempReal;
        dataArray.at(nspan).imagValue = dataArray.at(index).imagValue - tempImag;
        dataArray.at(index).realValue = dataArray.at(index).realValue + tempReal;
        dataArray.at(index).imagValue = dataArray.at(index).imagValue + tempImag;

        index++;
      }//for node
      index = (index + stride) & (fftSize - 1);
    }// for submatrix
    pass++;
  }// for stride
  Unscramble(dataArray);
}
