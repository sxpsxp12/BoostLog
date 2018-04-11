QT += core
QT -= gui

CONFIG += c++11

TARGET = BoostLog
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

win32:{
    INCLUDEPATH += $$PWD/third-party/win32/boost_1_59_0/include
    DEPENDPATH += $$PWD/third-party/win32/boost_1_59_0/include

    CONFIG(debug,debug|release){
        LIBS += $$PWD/lib/win32/boost_1_59_0/libboost_atomic-vc140-mt-gd-1_59.lib    \
                $$PWD/lib/win32/boost_1_59_0/libboost_chrono-vc140-mt-gd-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_container-vc140-mt-gd-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_date_time-vc140-mt-gd-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_filesystem-vc140-mt-gd-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_regex-vc140-mt-gd-1_59.lib    \
                $$PWD/lib/win32/boost_1_59_0/libboost_system-vc140-mt-gd-1_59.lib \
                $$PWD/lib/win32/boost_1_59_0/libboost_thread-vc140-mt-gd-1_59.lib   \
                $$PWD/lib/win32/boost_1_59_0/libboost_log_setup-vc140-mt-gd-1_59.lib \
                $$PWD/lib/win32/boost_1_59_0/libboost_log-vc140-mt-gd-1_59.lib

    }else{
        LIBS += $$PWD/lib/win32/boost_1_59_0/libboost_container-vc140-mt-1_59.lib   \
                $$PWD/lib/win32/boost_1_59_0/libboost_chrono-vc140-mt-1_59.lib    \
                $$PWD/lib/win32/boost_1_59_0/libboost_atomic-vc140-mt-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_date_time-vc140-mt-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_filesystem-vc140-mt-1_59.lib     \
                $$PWD/lib/win32/boost_1_59_0/libboost_regex-vc140-mt-1_59.lib   \
                $$PWD/lib/win32/boost_1_59_0/libboost_system-vc140-mt-1_59.lib \
                $$PWD/lib/win32/boost_1_59_0/libboost_thread-vc140-mt-1_59.lib  \
                $$PWD/lib/win32/boost_1_59_0/libboost_log_setup-vc140-mt-1_59.lib \
                $$PWD/lib/win32/boost_1_59_0/libboost_log-vc140-mt-1_59.lib
    }

    BUILD_DIR = build_win
}

linux:{
    BUILD_DIR = build_linux

    INCLUDEPATH += $$PWD/third-party/linux64/boost-1_60_0
    DEPENDPATH += $$PWD/third-party/linux64/boost-1_60_0

    LIBS += -L$$PWD/lib/linux64/boost_1_60_0 -lboost_system -lboost_thread -lboost_log_setup \
                -lboost_log -lboost_filesystem -lboost_date_time -lboost_regex -lboost_chrono -lboost_atomic
}

OBJECTS_DIR = $$BUILD_DIR
MOC_DIR = $$BUILD_DIR
UI_DIR = $$BUILD_DIR
RCC_DIR = $$BUILD_DIR

SOURCES += main.cpp \
    BoostLog/boostlog.cpp

HEADERS += \
    BoostLog/boostlog.h

