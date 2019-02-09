#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 28 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 52 // UTC second 0-61
#define YOTTA_BUILD_UUID 684d4220-1f16-4fbd-8d9c-6ddd76b66659 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID d1f5e8ac945be8de8b46d96e4cb5e05105e0075c // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION d1f5e8a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
