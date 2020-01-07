#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

namespace bez {

class NonCopyable {
protected:
  NonCopyable() {}
  virtual ~NonCopyable() {}

private:
  NonCopyable(const NonCopyable &);
  NonCopyable &operator=(const NonCopyable &);
};

} // namespace bez

#endif // NONCOPYABLE_H
