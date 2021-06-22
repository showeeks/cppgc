#ifndef V8_BASE_RING_BUFFER_H_
#define V8_BASE_RING_BUFFER_H_

#include "src/base/macros.h"

namespace v8 {
namespace base {

/**
 * 这个RingBuffer是GCTracer专用的。实现也非常简单，就是个数组，header-only。
 * 大小固定为10个。
 * 禁止复制
 **/
template <typename T>
class RingBuffer {
 public:
  RingBuffer() { Reset(); }
  RingBuffer(const RingBuffer&) = delete;
  RingBuffer& operator=(const RingBuffer&) = delete;

  static const int kSize = 10;

  /**
   * 没满就移动count_，满了以后就移动start_
   **/
  void Push(const T& value) {
    if (count_ == kSize) {
      elements_[start_++] = value;
      if (start_ == kSize) start_ = 0;
    } else {
      DCHECK_EQ(start_, 0);
      elements_[count_++] = value;
    }
  }

  int Count() const { return count_; }

  /**
   * Sum实际上是个reduce函数
   * @param callback 给一个reduce函数
   * @param initial 初始值
   **/
  template <typename Callback>
  T Sum(Callback callback, const T& initial) const {
    int j = start_ + count_ - 1;
    if (j >= kSize) j -= kSize;
    T result = initial;
    for (int i = 0; i < count_; i++) {
      result = callback(result, elements_[j]);
      if (--j == -1) j += kSize;
    }
    return result;
  }

  void Reset() { start_ = count_ = 0; }

 private:
  T elements_[kSize];
  // 头指标
  int start_;
  // 个数
  int count_;
};

}  // namespace base
}  // namespace v8

#endif  // V8_BASE_RING_BUFFER_H_