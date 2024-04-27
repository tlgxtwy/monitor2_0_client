/****************************************************************************
** Meta object code from reading C++ file 'history_batch_set_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/history_batch_set_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'history_batch_set_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_history_batch_set_dialog_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_history_batch_set_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_history_batch_set_dialog_t qt_meta_stringdata_history_batch_set_dialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "history_batch_set_dialog"
QT_MOC_LITERAL(1, 25, 16), // "s_get_batch_list"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "timeout"
QT_MOC_LITERAL(4, 51, 4), // "path"
QT_MOC_LITERAL(5, 56, 5), // "param"
QT_MOC_LITERAL(6, 62, 17), // "s_get_batch_param"
QT_MOC_LITERAL(7, 80, 10), // "start_time"
QT_MOC_LITERAL(8, 91, 3), // "mis"
QT_MOC_LITERAL(9, 95, 20), // "on_select_pb_clicked"
QT_MOC_LITERAL(10, 116, 32), // "on_batch_tablewidget_itemClicked"
QT_MOC_LITERAL(11, 149, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(12, 167, 4), // "item"
QT_MOC_LITERAL(13, 172, 16), // "on_ok_pb_clicked"
QT_MOC_LITERAL(14, 189, 19) // "on_cache_pb_clicked"

    },
    "history_batch_set_dialog\0s_get_batch_list\0"
    "\0timeout\0path\0param\0s_get_batch_param\0"
    "start_time\0mis\0on_select_pb_clicked\0"
    "on_batch_tablewidget_itemClicked\0"
    "QTableWidgetItem*\0item\0on_ok_pb_clicked\0"
    "on_cache_pb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_history_batch_set_dialog[] = {

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
       1,    3,   44,    2, 0x06 /* Public */,
       6,    2,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   56,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,
      13,    0,   60,    2, 0x08 /* Private */,
      14,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void history_batch_set_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<history_batch_set_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_get_batch_list((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 1: _t->s_get_batch_param((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->on_select_pb_clicked(); break;
        case 3: _t->on_batch_tablewidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_ok_pb_clicked(); break;
        case 5: _t->on_cache_pb_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (history_batch_set_dialog::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&history_batch_set_dialog::s_get_batch_list)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (history_batch_set_dialog::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&history_batch_set_dialog::s_get_batch_param)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject history_batch_set_dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_history_batch_set_dialog.data,
    qt_meta_data_history_batch_set_dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *history_batch_set_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *history_batch_set_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_history_batch_set_dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int history_batch_set_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void history_batch_set_dialog::s_get_batch_list(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void history_batch_set_dialog::s_get_batch_param(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
