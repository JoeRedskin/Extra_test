include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += TESTIDIR=\\\"$$PWD/../testi\\\"


HEADERS +=  ../app/common.h \
    ../app/text/text.h \
    fibonachi_test.h \
    ../app/text/_text.h

SOURCES +=  main.cpp \
    ../app/load.c \
    ../app/save.c \
    ../app/show.c \
    ../app/shownum.c \
    ../app/text/mplb.c \
    ../app/text/cursors.c \
    ../app/text/append_line.c \
    ../app/text/create_text.c \
    ../app/text/pp.c \
    ../app/text/process_even_odd.c \
    ../app/text/process_forward_extra_option.c \
    ../app/text/process_forward.c \
    ../app/text/randomic.c \
    ../app/text/remove_all.c \
    ../app/text/tracer.c

INCLUDEPATH += ../app
