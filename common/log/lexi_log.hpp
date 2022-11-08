#pragma once

#include <stdio.h>

#include <chrono>

#define LOG_INFO(fmt, ...)                                               \
  printf("INFO - [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
  void(0)

#define LOG_WARN(fmt, ...)                                               \
  printf("WARN - [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
  void(0)

#define LOG_ERROR(fmt, ...)                                               \
  printf("ERROR - [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
  exit(0)

#define ASSERT(cond, ...)     \
  if (!(cond)) {              \
    LOG_ERROR(##__VA_ARGS__); \
  }                           \
  void(0)