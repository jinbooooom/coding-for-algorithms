
#ifndef JINBO_LOG_HPP
#define JINBO_LOG_HPP

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define unuse(x) ((x) = (x))
#define LOG_TIME_SIZE (128)

#define DEBUG (1)
#define PRINT_FULL_FUNCTION_NAME (0)
#define PRINT_THREAD_PROCESS_ID_AND_FULL_TIME (1)

#if PRINT_FULL_FUNCTION_NAME
#define FUNC_FORMAT __PRETTY_FUNCTION__
#else
#define FUNC_FORMAT __func__
#endif

// Print only file names (filter out directories)
#define FILE_NAME(x) (strrchr((x), '/') ? strrchr((x), '/') + 1 : (x))

static char logTime[LOG_TIME_SIZE] = {0};

static void getTimeStr(char *t)
{
      struct timeval tv;
      struct timezone tz;
      struct tm *p;

      gettimeofday(&tv, &tz);
      p = localtime(&tv.tv_sec);
#if (PRINT_THREAD_PROCESS_ID_AND_FULL_TIME)
      snprintf(t, LOG_TIME_SIZE, "%04d/%02d/%02d %02d:%02d:%02d.%06ld %u %d",
               p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, tv.tv_usec,
               (unsigned int)pthread_self(), getpid());
#else
      snprintf(t, LOG_TIME_SIZE, "%02d:%02d:%02d.%06ld",
               p->tm_hour, p->tm_min, p->tm_sec, tv.tv_usec);
#endif
}

#if defined(ANDROID) || defined(__ANDROID__)
#include <android/log.h>

#define DEBUG_LOG 1

#if (DEBUG_LOG == 1)
#ifndef LOG_TAG
#define LOG_TAG "[Jinbo]"
#endif
#define logv(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define logi(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define logd(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define logw(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define loge(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
#define logv(...) cout << __VA_ARGS__ << endl;
#define logi(...) cout << __VA_ARGS__ << endl;
#define logd(...) cout << __VA_ARGS__ << endl;
#define logw(...) cout << __VA_ARGS__ << endl;
#define loge(...) cout << __VA_ARGS__ << endl;
#endif

#else //LINUX

#if (DEBUG)
#define logi(format, ...)                                                                                          \
      getTimeStr(logTime);                                                                                         \
      fprintf(stdout, "\033[1m\033[40;37m %s I [%s:%s:%d] ", logTime, FILE_NAME(__FILE__), FUNC_FORMAT, __LINE__); \
      fprintf(stdout, format, ##__VA_ARGS__);                                                                      \
      fprintf(stdout, "\033[0m\n");

#define logd(format, ...)                                                                                          \
      getTimeStr(logTime);                                                                                         \
      fprintf(stdout, "\033[1m\033[40;32m %s D [%s:%s:%d] ", logTime, FILE_NAME(__FILE__), FUNC_FORMAT, __LINE__); \
      fprintf(stdout, format, ##__VA_ARGS__);                                                                      \
      fprintf(stdout, "\033[0m\n");

#define logw(format, ...)                                                                                          \
      getTimeStr(logTime);                                                                                         \
      fprintf(stdout, "\033[1m\033[40;33m %s W [%s:%s:%d] ", logTime, FILE_NAME(__FILE__), FUNC_FORMAT, __LINE__); \
      fprintf(stdout, format, ##__VA_ARGS__);                                                                      \
      fprintf(stdout, "\033[0m\n");

#define loge(format, arg...)                                                                                       \
      getTimeStr(logTime);                                                                                         \
      fprintf(stdout, "\033[1m\033[40;31m %s E [%s:%s:%d] ", logTime, FILE_NAME(__FILE__), FUNC_FORMAT, __LINE__); \
      fprintf(stdout, format, ##arg);                                                                              \
      fprintf(stdout, "\033[0m\n");

#define logmark(format, arg...)                                                                                    \
      getTimeStr(logTime);                                                                                         \
      fprintf(stdout, "\033[1m\033[40;35m %s M [%s:%s:%d] ", logTime, FILE_NAME(__FILE__), FUNC_FORMAT, __LINE__); \
      fprintf(stdout, format, ##arg);                                                                              \
      fprintf(stdout, "\033[0m \n");

#define login() logi("IN")

#define logout() logi("OUT")

#else
#define logi(format, ...)
#define logd(format, ...)
#define logw(format, ...)
#define loge(format, ...)
#define logmark(format, ...)
#define login(format, ...)
#define logout(format, ...)

#endif // end DEBUG

#endif // end ANDROID

#endif // end JINBO_LOG_H
