#include <QCoreApplication>
#include <QThread>
#include "BoostLog/boostlog.h"

/******************************************
 * by:sxpsxp12
 *本工程是个控制台程序，主要是用于C++程序的日志log调试；
 *参考文档：http://www.boost.org/doc/libs/1_64_0/libs/log/doc/html/index.html
 *使用了boost.log日志功能。支持控制台的输出和文件输出两种方式。方便调试和记录。
 *同时本工程中提供了记录函数运行时间的功能,可以通过该属性，分析程序性能
 * ***************************************/

void test_function()
{
    log_time_line;

    log_debug << "start";
    QThread::msleep(500);
    log_debug << "end";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 1
    initBoostConsoleLog();
    log_debug << "测试";

    test_function();
    log_debug << "测试";
#else
    initBoostFileLog();
    log_debug << "测试";
#endif
    return a.exec();
}
