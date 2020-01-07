#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <memory>
#include <vector>

namespace bez {
class Log {
public:
  Log(){};
  virtual ~Log(){};

  template <typename T, typename... Args>
  static void warn(T consoleName, Args... args) {
    std::cout << consoleName << ": [WARN] -> ";
    print(args...);
    std::cout << std::endl;
  }

  template <typename T, typename... Args>
  static void info(T consoleName, Args... args) {
    std::cout << consoleName << ": [INFO] -> ";

    print(args...);

    std::cout << std::endl;
  }

  template <typename T, typename... Args>
  static void critical(T consoleName, Args... args) {
    std::cout << consoleName << ": [CRIT] -> ";
    print(args...);
    std::cout << std::endl;
  }

protected:
private:
  static void print(){};

  template <typename T, typename... Arguments>
  static void print(T message, Arguments... args) {
    std::cout << message << " ";
    print(args...);
  }
};

} // namespace bez

// Logging macros for core
#define BEZ_CORE_INFO(...) ::bez::Log::info("CORE", __VA_ARGS__)
#define BEZ_CORE_WARN(...) ::bez::Log::warn("CORE", __VA_ARGS__)
#define BEZ_CORE_CRIT(...) ::bez::Log::critical("CORE", __VA_ARGS__)

// Logging macros for App
#define BEZ_INFO(...) ::bez::Log::info("CLIENT", __VA_ARGS__)
#define BEZ_WARN(...) ::bez::Log::warn("CLIENT", __VA_ARGS__)
#define BEZ_CRIT(...) ::bez::Log::critical("CLIENT", __VA_ARGS__)

#endif // LOG_H
