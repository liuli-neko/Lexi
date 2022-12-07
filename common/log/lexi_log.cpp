#include "lexi_log.hpp"

#include <string.h>
#include <time.h>

namespace lexi {
namespace common {
LogMessageStream CalibrateLog::out_;
std::stringstream CalibrateLog::stream_;

const char* baseName(const char* filepath) {
  const char* base = strrchr(filepath, '/');
  return base ? (base + 1) : filepath;
}

std::string getTime() {
  time_t timep;
  time(&timep);
  char tmp[64];
  strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
  return tmp;
}

CalibrateLog::CalibrateLog(const char* file, int32_t line) {
  stream_.str("");
  stream_ << "[" << getTime() << "|" << baseName(file) << ":" << line << "]";
}

std::stringstream& CalibrateLog::stream() { return stream_; }

CalibrateLog::~CalibrateLog() {
  stream_ << std::endl;
  out_.write(stream_.str().c_str());
  stream_.clear();
}

void CalibrateLog::AddOutPutSource(const std::string& output_file) {
  FILE* file_fd;
  file_fd = fopen(output_file.c_str(), "a");
  out_.AddOutPutSource(file_fd);
}

void CalibrateLog::AddOutPutSource(FILE* output_fd) {
  out_.AddOutPutSource(output_fd);
}

LogMessageStream::LogMessageStream() {}

void LogMessageStream::AddOutPutSource(FILE* output_fd) {
  out_fd_.push_back(output_fd);
}

void LogMessageStream::write(const char* buf) {
  if (out_fd_.size() == 0) {
    std::cout << "WARNING: outstream not set ,auto set stdout." << std::endl;
    out_fd_.push_back(stdout);
  }
  for (auto out_fd : out_fd_) {
    fputs(buf, out_fd);
  }
}

LogMessageStream::~LogMessageStream() {
  for (auto fd : out_fd_) {
    fclose(fd);
  }
}

AssertLog::AssertLog(const char* file, int32_t line, bool cond)
    : CalibrateLog(file, line), cond_(cond) {}
AssertLog::~AssertLog() {
  if (!cond_) {
    exit(-1);
  }
}

}  // namespace common
}  // namespace lexi