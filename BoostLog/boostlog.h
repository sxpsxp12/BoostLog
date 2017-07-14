#ifndef BOOSTLOG_H
#define BOOSTLOG_H

#include "boost/log/core.hpp"
#include "boost/log/expressions.hpp"
#include "boost/log/sinks/text_file_backend.hpp"
#include "boost/log/utility/setup/file.hpp"
#include "boost/log/utility/setup/console.hpp"
#include "boost/log/utility/setup/common_attributes.hpp"
#include "boost/log/sources/global_logger_storage.hpp"
#include "boost/log/sources/severity_logger.hpp"
#include "boost/log/sources/record_ostream.hpp"
#include "boost/log/support/date_time.hpp"
#include "boost/log/sources/logger.hpp"
#include "boost/date_time/posix_time/posix_time_types.hpp"
#include "boost/log/attributes.hpp"
#include "boost/log/attributes/scoped_attribute.hpp"

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

enum severity_level {
    debug,
    warning,
    error,
    critical
};

//为了支持宽窄字符的sink格式化
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
        std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] = {
        "debug",
        "warning",
        "error",
        "critical"};

    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}

//声明全局的日志记录器(source)
BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::severity_logger_mt<severity_level>)
//定义属性占位符
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp,"TimeStamp",boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(scope, "Scope", attrs::named_scope::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(timeline, "Timeline", attrs::timer::value_type)

#define log_debug BOOST_LOG_SEV(my_logger::get(),debug) << "file:(" << __FILE__ << "-->line:" << __LINE__ << ") "
#define log_warning BOOST_LOG_SEV(my_logger::get(),warning) << "file:(" << __FILE__ << "-->line:" << __LINE__ << ") "
#define log_time_line BOOST_LOG_SCOPED_THREAD_ATTR("Timeline", attrs::timer())

void initBoostFileLog();
void initBoostConsoleLog();

#endif // BOOSTLOG_H
