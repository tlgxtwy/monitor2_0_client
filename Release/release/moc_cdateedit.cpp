/****************************************************************************
** Meta object code from reading C++ file 'cdateedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OPEN_LIB/cdateedit/cdateedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cdateedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDateEdit_t {
    QByteArrayData data[8];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDateEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDateEdit_t qt_meta_stringdata_CDateEdit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CDateEdit"
QT_MOC_LITERAL(1, 10, 11), // "setDateTime"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "dateTime"
QT_MOC_LITERAL(4, 32, 7), // "setDate"
QT_MOC_LITERAL(5, 40, 4), // "date"
QT_MOC_LITERAL(6, 45, 7), // "setTime"
QT_MOC_LITERAL(7, 53, 4) // "time"

    },
    "CDateEdit\0setDateTime\0\0dateTime\0setDate\0"
    "date\0setTime\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDateEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime,    3,
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void, QMetaType::QTime,    7,

       0        // eod
};

void CDateEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CDateEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDateTime((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 1: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->setTime((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDateEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QDateEdit::staticMetaObject>(),
    qt_meta_stringdata_CDateEdit.data,
    qt_meta_data_CDateEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CDateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDateEdit.stringdata0))
        return static_cast<void*>(this);
    return QDateEdit::qt_metacast(_clname);
}

int CDateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
