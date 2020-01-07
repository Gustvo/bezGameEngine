#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include <NonCopyable.hpp>

class Shader : public bez::NonCopyable {
public:
  Shader(const std::string &fileName);
  virtual ~Shader();

  void useProgram() const;

  void setInt(const std::string &name, int value);
  void setFloat(const std::string &name, float value);

  void setUniform(const std::string &name, int value) const;
  void setUniform(const std::string &name, float value) const;
  void setUniform(const std::string &name, const glm::vec2 &value) const;
  void setUniform(const std::string &name, const glm::vec3 &value) const;
  void setUniform(const std::string &name, const glm::vec4 &value) const;
  void setUniform(const std::string &name, const glm::mat3 &value) const;
  void setUniform(const std::string &name, const glm::mat4 &value) const;

  GLuint getProgram() const;

protected:
private:
  static const unsigned int NUMSHADERS = 2;
  bool checkSuccess(GLuint, bool);

  enum { VERTEX_SHADER, FRAGMENT_SHADER };

  GLuint m_shaders[NUMSHADERS];
  GLuint m_program;

  // void createShader(const std::string& fileName);
};

#endif // SHADER_H
