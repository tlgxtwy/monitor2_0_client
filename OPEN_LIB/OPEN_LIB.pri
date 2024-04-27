#SOURCES += \
CONFIG += c++11

INCLUDEPATH += \
    $$PWD/QsLog/include \
    $$PWD/QCustomPlot \
    $$PWD/cdateedit

DEPENDPATH += \
    $$PWD/QsLog/include \
    $$PWD/QCustomPlot \
    $$PWD/cdateedit

DEFINES += QS_LOG_LINE_NUMBERS    # automatically writes the file and line for each log message
#DEFINES += QS_LOG_DISABLE         # logging code is replaced with a no-op
HEADERS += \
    $$PWD/QsLog/include/QsLog.h \
    $$PWD/QsLog/include/QsLogDest.h \
    $$PWD/QsLog/include/QsLogDisableForThisFile.h \
    $$PWD/QsLog/include/QsLogLevel.h \
    $$PWD/QCustomPlot/qcustomplot.h \
    $$PWD/cdateedit/cdateedit.h
SOURCES += \
    $$PWD/QCustomPlot/qcustomplot.cpp \
    $$PWD/cdateedit/cdateedit.cpp

LIBS += -L$$PWD/QsLog/bin -lQsLog2


