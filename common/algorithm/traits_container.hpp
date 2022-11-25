#pragma once
#include <memory>
#include <type_traits>

template <typename T, class Enable = void> struct traits {
public:
  typedef T *Pointer;
  typedef std::shared_ptr<T> Ptr;
  typedef T type;
};

template <typename T> struct traits<typename std::shared_ptr<T>, void> {
public:
  typedef T *Pointer;
  typedef std::shared_ptr<T> Ptr;
  typedef Ptr type;
};

template <typename T>
struct traits<T, std::enable_if_t<std::is_pointer<T>::value>> {
public:
  typedef T Pointer;
  typedef std::shared_ptr<std::remove_pointer_t<T>> Ptr;
  typedef T type;
};

template <typename T>
struct traits<T, std::enable_if_t<std::is_base_of<traits<T>, T>::value>> {
public:
  typedef typename T::Pointer Pointer;
  typedef typename T::Ptr Ptr;
  typedef typename T::type type;
};