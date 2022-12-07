#pragma once

#include <stdio.h>

#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

namespace lexi {
namespace common {
class LogMessageStream {
 public:
  LogMessageStream();
  void AddOutPutSource(FILE* output_fd);
  void write(const char* buf);
  ~LogMessageStream();

 private:
  std::vector<FILE*> out_fd_;
};

class CalibrateLog {
 public:
  CalibrateLog(const char* file, int32_t line);
  ~CalibrateLog();

  std::stringstream& stream();

  static void AddOutPutSource(const std::string& output_file);
  static void AddOutPutSource(FILE* output_fd);

 private:
  static LogMessageStream out_;
  static std::stringstream stream_;
};

class AssertLog : public CalibrateLog {
 public:
  AssertLog(const char* file, int32_t line, bool cond);
  ~AssertLog();

 private:
  bool cond_;
};
}  // namespace common
}  // namespace lexi

#define LOG lexi::common::CalibrateLog(__FILE__, __LINE__).stream()
#define ASSERT(cond) lexi::common::AssertLog(__FILE__, __LINE__, cond).stream()