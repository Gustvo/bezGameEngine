#include <stdafx.hpp>

#include "Shader.hpp"

#include <bez/Logger/Log.hpp>

std::string loadFile(const std::string &path) {
  std::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  std::string output;
  try {
    file.open(path);

    std::stringstream shaderStream;

    shaderStream << file.rdbuf();

    file.close();

    output = shaderStream.str();
  } catch (std::ifstream::failure &e) {
    std::cout << "[ERR] - Failed to load shader source file" << std::endl;
    return output;
  }
  return output;
}

Shader::Shader(const std::string &p_fileName) {
  BEZ_CORE_INFO("Loading shader from source");
  std::string code;
  code = loadFile("Shaders/" + p_fileName + ".vert");
  const GLchar *shaderSource = code.c_str();

  m_shaders[VERTEX_SHADER] = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(m_shaders[VERTEX_SHADER], 1, &shaderSource, NULL);
  glCompileShader(m_shaders[VERTEX_SHADER]);
  checkSuccess(m_shaders[VERTEX_SHADER], false);

  code = loadFile("Shaders/" + p_fileName + ".frag");
  shaderSource = code.c_str();
  m_shaders[FRAGMENT_SHADER] = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(m_shaders[FRAGMENT_SHADER], 1, &shaderSource, NULL);
  glCompileShader(m_shaders[FRAGMENT_SHADER]);
  checkSuccess(m_shaders[FRAGMENT_SHADER], false);

  BEZ_CORE_INFO("Creating shader program");
  m_program = glCreateProgram();
  glAttachShader(m_program, m_shaders[VERTEX_SHADER]);
  glAttachShader(m_program, m_shaders[FRAGMENT_SHADER]);
  glLinkProgram(m_program);
  checkSuccess(m_program, true);

  glDeleteShader(m_shaders[VERTEX_SHADER]);
  glDeleteShader(m_shaders[FRAGMENT_SHADER]);
}

Shader::~Shader() {
  // dtor
}

void Shader::useProgram() const { glUseProgram(m_program); }

bool Shader::checkSuccess(GLuint p_shader, bool isProgram) {
  int success;
  char infoLog[512];

  if (isProgram) {
    glGetProgramiv(p_shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(p_shader, 512, NULL, infoLog);
      std::cerr << "[ERR] Failed to link program - " << infoLog << std::endl;
      return false;
    }
    return true;
  }
  glGetShaderiv(p_shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(p_shader, 512, NULL, infoLog);
    std::cerr << "[ERR] Failed to compile shader - " << infoLog << std::endl;
    return false;
  }
  return true;
}

void Shader::setUniform(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(m_program, name.c_str()), value);
}

void Shader::setUniform(const std::string &name, float value) const {
  glUniform1f(glGetUniformLocation(m_program, name.c_str()), value);
}

void Shader::setUniform(const std::string &name, const glm::vec2 &value) const {
  glUniform2f(glGetUniformLocation(m_program, name.c_str()), value.x, value.y);
}

void Shader::setUniform(const std::string &name, const glm::vec3 &value) const {
  glUniform3f(glGetUniformLocation(m_program, name.c_str()), value.x, value.y,
              value.z);
}

void Shader::setUniform(const std::string &name, const glm::vec4 &value) const {
  glUniform4f(glGetUniformLocation(m_program, name.c_str()), value.x, value.y,
              value.z, value.w);
}

void Shader::setUniform(const std::string &name, const glm::mat3 &value) const {
  glUniformMatrix3fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE,
                     glm::value_ptr(value));
}

void Shader::setUniform(const std::string &name, const glm::mat4 &value) const {
  glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE,
                     glm::value_ptr(value));
}

GLuint Shader::getProgram() const { return m_program; }
