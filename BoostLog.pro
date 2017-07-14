QT += core
QT -= gui

CONFIG += c++11

TARGET = BoostLog
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/third-party/boost_1_59_0/include

CONFIG(debug, debug|release) {
    LIBS += $$PWD/lib/libboost_system-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_log_setup-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_thread-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_filesystem-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_date_time-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_log-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_chrono-vc140-mt-gd-1_59.lib \
            $$PWD/lib/libboost_atomic-vc140-mt-gd-1_59.lib
} else {
    LIBS += $$PWD/lib/libboost_system-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_thread-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_log_setup-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_filesystem-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_date_time-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_log-vc140-mt-1_59.lib    \
            $$PWD/lib/libboost_chrono-vc140-mt-1_59.lib \
            $$PWD/lib/libboost_atomic-vc140-mt-1_59.lib
}
SOURCES += main.cpp \
    BoostLog/boostlog.cpp

HEADERS += \
    BoostLog/boostlog.h

