#ifndef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

#include <spdlog/spdlog.h>

#define LOGT SPDLOG_TRACE
#define LOGD SPDLOG_DEBUG
#define LOGI SPDLOG_INFO
#define LOGW SPDLOG_WARN
#define LOGE SPDLOG_ERROR
#define LOGC SPDLOG_CRITICAL

#ifndef NDEBUG
#define LOG_PATTERN "[%T.%e] [%^%L%$] [%@] %v"
#else
#define LOG_PATTERN "[%Y-%m-%d %T.%e] [%^%L%$] %v"
#endif

#include <catch.hpp>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <string>

TEST_CASE("spdlog::init") {
  spdlog::init_thread_pool(8192, 1);
  spdlog::set_pattern(LOG_PATTERN, spdlog::pattern_time_type::local);
  spdlog::set_level(spdlog::level::trace);
  spdlog::flush_on(spdlog::level::trace);
  REQUIRE(spdlog::default_logger() != nullptr);
}
