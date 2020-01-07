#ifndef DRAWABLE_H
#define DRAWABLE_H

namespace bez {

class Drawable {
public:
protected:
  Drawable(){};
  virtual ~Drawable(){};
  virtual void draw() const = 0;

private:
  friend class Window;
};
} // namespace bez

#endif // DRAWABLE_H
