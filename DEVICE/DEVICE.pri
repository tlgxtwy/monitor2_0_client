INCLUDEPATH += \
    $$PWD/BRY \
    $$PWD/BYM \
    $$PWD/STATION \
#    $$PWD/RACK

DEPENDPATH += \
    $$PWD/BRY \
    $$PWD/BYM \
    $$PWD/STATION \
#    $$PWD/RACK

HEADERS += \
    $$PWD/BRY/basic_bry_factory.h \
    $$PWD/BRY/bry1000.h \
    $$PWD/BRY/bry2000.h \
    $$PWD/BRY/bry_base.h \
    $$PWD/BRY/bry_general.h \
    $$PWD/BYM/basic_bym_factory.h \
    $$PWD/BYM/bym_base.h \
    $$PWD/BYM/bym_four.h \
    $$PWD/BYM/bym_one.h \
    $$PWD/BYM/bym_two.h \
    $$PWD/STATION/station.h
#    $$PWD/RACK/aging_room.h \
#    $$PWD/RACK/arack_base.h \
#    $$PWD/RACK/arack_one.h
SOURCES += \
    $$PWD/BRY/basic_bry_factory.cpp \
    $$PWD/BRY/bry1000.cpp \
    $$PWD/BRY/bry2000.cpp \
    $$PWD/BRY/bry_base.cpp \
    $$PWD/BRY/bry_general.cpp \
    $$PWD/BYM/basic_bym_factory.cpp \
    $$PWD/BYM/bym_base.cpp \
    $$PWD/BYM/bym_four.cpp \
    $$PWD/BYM/bym_one.cpp \
    $$PWD/BYM/bym_two.cpp \
    $$PWD/STATION/station.cpp
#    $$PWD/RACK/aging_room.cpp \
#    $$PWD/RACK/arack_base.cpp \
#    $$PWD/RACK/arack_one.cpp
