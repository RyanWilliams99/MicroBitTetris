#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 57 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 58 // UTC second 0-61
#define YOTTA_BUILD_UUID 3cdb37c5-c0f8-43e7-9e9e-0a6c3df3f454 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID d90e46cdb5c0a1bcce9e5580d7bd441e4e479e85 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 1 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION d90e46c // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
