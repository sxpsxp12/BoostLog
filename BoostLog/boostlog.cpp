#include "boostlog.h"
#include "Windows.h"

//文件日志
void initBoostFileLog()
{
    char buf[512];
    GetModuleFileNameA(NULL,buf,512);
    *strrchr(buf,'\\') = '\0';
    strcat(buf, "\\log_%Y-%m-%d_%H-%M-%S.txt");
    const char *file_name = buf;

    auto sink = logging::add_file_log
            (
                keywords::file_name = file_name,
                keywords::rotation_size = 100 * 1024 * 1024, //100M大小限制
                keywords::time_based_rotation = sinks::file::rotation_at_time_point(0 ,0, 0),
                keywords::format = expr::stream
                << expr::format_date_time(timestamp, "%Y-%m-%d %H:%M:%S")
                << ": <" << severity << "> "
                << expr::if_(expr::has_attr(scope))
                [
                    expr::stream << "scope:(" << scope << ") "
                ]
                << expr::if_(expr::has_attr(timeline))
                [
                    expr::stream << "timeLine:[" << timeline << "] "
                ]
                << expr::message
            );
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
                << expr::if_(expr::has_attr(scope))
                [
                    expr::stream << "scope:(" << scope << ") "
                ]
                << expr::if_(expr::has_attr(timeline))
                [
                    expr::stream << "timeLine:[" << timeline << "] "
                ]
                << expr::message
            );
    sink->locked_backend()->auto_flush(true);//使日志实时更新
    logging::add_common_attributes();
//    logging::core::get()->add_global_attribute("Scope", attrs::named_scope());
}
