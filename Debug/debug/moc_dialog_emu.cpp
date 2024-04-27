/****************************************************************************
** Meta object code from reading C++ file 'dialog_emu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/control/dialog_emu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_emu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialog_emu_t {
    QByteArrayData data[17];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_emu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_emu_t qt_meta_stringdata_dialog_emu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dialog_emu"
QT_MOC_LITERAL(1, 11, 19), // "signal_set_EMU_code"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "data"
QT_MOC_LITERAL(4, 37, 21), // "signal_get_EMU_stauts"
QT_MOC_LITERAL(5, 59, 14), // "slot_getEMUCID"
QT_MOC_LITERAL(6, 74, 6), // "EMUCID"
QT_MOC_LITERAL(7, 81, 7), // "STATION"
QT_MOC_LITERAL(8, 89, 19), // "slot_get_EMU_status"
QT_MOC_LITERAL(9, 109, 6), // "status"
QT_MOC_LITERAL(10, 116, 7), // "reserve"
QT_MOC_LITERAL(11, 124, 4), // "func"
QT_MOC_LITERAL(12, 129, 4), // "sign"
QT_MOC_LITERAL(13, 134, 8), // "run_mode"
QT_MOC_LITERAL(14, 143, 4), // "time"
QT_MOC_LITERAL(15, 148, 32), // "on_pushButton_Reflux_set_clicked"
QT_MOC_LITERAL(16, 181, 34) // "on_pushButton_EMU_Info_get_cl..."

    },
    "dialog_emu\0signal_set_EMU_code\0\0data\0"
    "signal_get_EMU_stauts\0slot_getEMUCID\0"
    "EMUCID\0STATION\0slot_get_EMU_status\0"
    "status\0reserve\0func\0sign\0run_mode\0"
    "time\0on_pushButton_Reflux_set_clicked\0"
    "on_pushButton_EMU_Info_get_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_emu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   50,    2, 0x0a /* Public */,
       8,    6,   55,    2, 0x0a /* Public */,
      15,    0,   68,    2, 0x08 /* Private */,
      16,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialog_emu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dialog_emu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_set_EMU_code((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->signal_get_EMU_stauts((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->slot_getEMUCID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slot_get_EMU_status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 4: _t->on_pushButton_Reflux_set_clicked(); break;
        case 5: _t->on_pushButton_EMU_Info_get_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dialog_emu::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialog_emu::signal_set_EMU_code)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dialog_emu::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialog_emu::signal_get_EMU_stauts)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dialog_emu::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_dialog_emu.data,
    qt_meta_data_dialog_emu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dialog_emu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_emu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_emu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dialog_emu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void dialog_emu::signal_set_EMU_code(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dialog_emu::signal_get_EMU_stauts(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
