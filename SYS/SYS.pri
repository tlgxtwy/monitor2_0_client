INCLUDEPATH += \
    $$PWD/client \
    $$PWD/midlayer \
    $$PWD/sys

DEPENDPATH += \
    $$PWD/client \
    $$PWD/midlayer \
    $$PWD/sys

HEADERS += \
    $$PWD/client/cs_client.h \
    $$PWD/client/mes_client.h \
    $$PWD/midlayer/bridge.h \
    $$PWD/sys/core_mg.h


SOURCES += \
    $$PWD/client/cs_client.cpp \
    $$PWD/client/mes_client.cpp \
    $$PWD/midlayer/bridge.cpp \
    $$PWD/sys/core_mg.cpp

