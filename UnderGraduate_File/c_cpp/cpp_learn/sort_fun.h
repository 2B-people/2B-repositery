#ifndef __SORT_FUN_H__
#define __SORT_FUN_H__

#include <cstring>

#include "timer/timer.h"

class SortBase
{
private:
  int r_[];

public:
  SortBase(const int *data)
  {
    memcpy(r_, data, sizeof(data));
  }
  ~SortBase() = default;

  bool SortLoop()
  {
    if (sizeof(r_) / sizeof(r_[0]) != 0)
    {
      TIMER_START(SortFun);
      bool flag = SortFun(r_);
      TIMER_END(SortFun);
    }
    return false;
  }

  virtual bool SortFun(int *data) = 0;
};

class BubbleSort : public SortBase
{
public:
  BubbleSort(const int *data_) : SortBase::SortBase(data_);
  ~BubbleSort() = default;

  bool SortFun(int *data);
};

#endif //__SORT_FUN_H__