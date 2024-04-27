/****************************************************************************
** Meta object code from reading C++ file 'dialog_file.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/control/dialog_file.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_file.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialog_file_t {
    QByteArrayData data[13];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_file_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_file_t qt_meta_stringdata_dialog_file = {
    {
QT_MOC_LITERAL(0, 0, 11), // "dialog_file"
QT_MOC_LITERAL(1, 12, 15), // "signal_fileSave"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "fileName"
QT_MOC_LITERAL(4, 38, 16), // "slot_receivePara"
QT_MOC_LITERAL(5, 55, 9), // "str_Grid*"
QT_MOC_LITERAL(6, 65, 10), // "s_str_Grid"
QT_MOC_LITERAL(7, 76, 8), // "str_Cer*"
QT_MOC_LITERAL(8, 85, 9), // "s_str_Cer"
QT_MOC_LITERAL(9, 95, 20), // "slot_receiveFilePath"
QT_MOC_LITERAL(10, 116, 8), // "filePath"
QT_MOC_LITERAL(11, 125, 26), // "on_pushButton_save_clicked"
QT_MOC_LITERAL(12, 152, 28) // "on_pushButton_cancel_clicked"

    },
    "dialog_file\0signal_fileSave\0\0fileName\0"
    "slot_receivePara\0str_Grid*\0s_str_Grid\0"
    "str_Cer*\0s_str_Cer\0slot_receiveFilePath\0"
    "filePath\0on_pushButton_save_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_file[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   42,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,
      11,    0,   50,    2, 0x08 /* Private */,
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialog_file::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dialog_file *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_fileSave((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_receivePara((*reinterpret_cast< str_Grid*(*)>(_a[1])),(*reinterpret_cast< str_Cer*(*)>(_a[2]))); break;
        case 2: _t->slot_receiveFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_save_clicked(); break;
        case 4: _t->on_pushButton_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dialog_file::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialog_file::signal_fileSave)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dialog_file::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_dialog_file.data,
    qt_meta_data_dialog_file,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dialog_file::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_file::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_file.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dialog_file::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void dialog_file::signal_fileSave(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
