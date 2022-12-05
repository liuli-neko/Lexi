#pragma once

#include <memory>
#include <string>
#include <type_traits>

namespace lexi {
namespace common {

template <typename T, class Enable = void>
struct traits {
 public:
  typedef T *Pointer;
  typedef std::shared_ptr<T> Ptr;
  typedef T type;
  typedef T *Iterator;
  typedef T &Ref;
};

template <typename T>
struct traits<typename std::shared_ptr<T>, void> {
 public:
  typedef T *Pointer;
  typedef std::shared_ptr<T> Ptr;
  typedef Ptr type;
  typedef T *Iterator;
  typedef T Ref;
};

template <typename T>
struct traits<T, std::enable_if_t<std::is_pointer<T>::value>> {
 public:
  typedef T Pointer;
  typedef std::shared_ptr<std::remove_pointer_t<T>> Ptr;
  typedef T type;
  typedef T Iterator;
  typedef T &Ref;
};

template <typename T>
struct traits<T, std::enable_if_t<std::is_arithmetic<T>::value>> {
 public:
  typedef T *Pointer;
  typedef std::shared_ptr<T> Ptr;
  typedef T type;
  typedef T *Iterator;
  typedef T &Ref;
};

}  // namespace common
}  // namespace lexi