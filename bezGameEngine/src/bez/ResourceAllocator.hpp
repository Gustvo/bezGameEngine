#ifndef RESOURCEALLOCATOR_H
#define RESOURCEALLOCATOR_H

#include <map>
#include <memory>

#include <NonCopyable.hpp>

template <class T> class ResourceAllocator : public bez::NonCopyable {
public:
  void addResource(const std::string &name, T *resource);
  std::shared_ptr<T> getResource(const std::string &name);
  std::map<std::string, std::shared_ptr<T>> getResourceContainer();

protected:
private:
  std::map<std::string, std::shared_ptr<T>> m_resources;
};

template <class T>
void ResourceAllocator<T>::addResource(const std::string &p_name,
                                       T *p_resource) {
  m_resources.insert(std::make_pair(p_name, std::shared_ptr<T>(p_resource)));
}

template <class T>
std::shared_ptr<T>
ResourceAllocator<T>::getResource(const std::string &p_name) {
  return m_resources[p_name];
}

template <class T>
std::map<std::string, std::shared_ptr<T>>
ResourceAllocator<T>::getResourceContainer() {
  return m_resources;
}

#endif // RESOURCEALLOCATOR_H
