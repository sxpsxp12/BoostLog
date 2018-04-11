#include "boostlog.h"
#include <QtGlobal>

const char *log_path = NULL;
int log_level = 0;

//文件日志
void initBoostFileLog()
{
    if(!log_path)
        return;
    char buf[1024];
    strcpy(buf,log_path);
#if defined(Q_OS_WIN32)
    strcat(buf, "\\log_%Y-%m-%d_%H-%M-%S.txt");
#elif defined(Q_OS_UNIX)
    strcat(buf, "/log_%Y-%m-%d_%H-%M-%S.txt");
#endif

    std::cout << "buf:" << buf << std::endl;
    const char *file_name = buf;
    auto sink = logging::add_file_log
            (
                keywords::file_name = file_name,
                keywords::rotation_size = 100 * 1024 * 1024, //100M大小限制
                keywords::time_based_rotation = sinks::file::rotation_at_time_point(0 ,0, 0),
                keywords::format = expr::stream
                << expr::format_date_time(timestamp, "%Y-%m-%d %H:%M:%S")
                << ": <" << severity << "> "
                << expr::if_(expr::has_attr(timeline))
                [
                    expr::stream << "[" << timeline << "] "
                ]
                << expr::message
            );
    if(log_level)
        sink->set_filter(expr::attr< severity_level >("Severity") >= 1);
    sink->locked_backend()->auto_flush(true);//使日志实时更新
    logging::add_common_attributes();
}

//控制台调试
void initBoostConsoleLog()
{
    auto sink = logging::add_console_log
            (
                std::clog,
                keywords::format = expr::stream
                << expr::format_date_time(timestamp, "%Y-%m-%d %H:%M:%S")
                << ": <" << severity << "> "
                << expr::if_(expr::has_attr(timeline))
                [
                    expr::stream << "[" << timeline << "] "
                ]
                << expr::message
            );
    if(log_level)
        sink->set_filter(expr::attr< severity_level >("Severity") >= 1);
    sink->locked_backend()->auto_flush(true);//使日志实时更新
    logging::add_common_attributes();
}
