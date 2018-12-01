#pragma once

#include <cstdio>

#include "Thread.h"

#ifdef _DEBUG
#define DEFAULT_LOG_LEVEL LOG_DEBUG
#else
#define DEFAULT_LOG_LEVEL LOG_INFO
#endif

class Logger : Lockable
{
public:
		
	enum LOGLEVEL{
		LOG_NONE,
		LOG_ERROR,
		LOG_WARNING,
		LOG_INFO,
		LOG_DEBUG
	};

	Logger():out(stderr), i_maxLevel(DEFAULT_LOG_LEVEL){}
	Logger(const char* path);

	void SetLevel(int level){i_maxLevel = level;}	
	void Write( int level, const char* fmt, ... );
	void WriteRaw(const char* fmt, ...);
	
	static Logger* getSingleton();

private:

	int i_maxLevel;
	char buffer[2000];
	FILE* out;
};

#define HDTLogRaw( fmt, ... ) Logger::getSingleton()->WriteRaw( fmt, __VA_ARGS__ )
#define HDTLogError( fmt, ... ) Logger::getSingleton()->Write( Logger::LOG_ERROR, fmt, __VA_ARGS__ )
#define HDTLogWarning( fmt, ... ) Logger::getSingleton()->Write( Logger::LOG_WARNING, fmt, __VA_ARGS__ )
#define HDTLogInfo( fmt, ... ) Logger::getSingleton()->Write( Logger::LOG_INFO, fmt, __VA_ARGS__ )
#define HDTLogDebug( fmt, ... ) Logger::getSingleton()->Write( Logger::LOG_DEBUG, fmt, __VA_ARGS__ )
