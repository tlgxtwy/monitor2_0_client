/****************************************************************************
** Meta object code from reading C++ file 'select_mi_power_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/select_mi_power_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'select_mi_power_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_select_mi_power_widget_t {
    QByteArrayData data[16];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_select_mi_power_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_select_mi_power_widget_t qt_meta_stringdata_select_mi_power_widget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "select_mi_power_widget"
QT_MOC_LITERAL(1, 23, 27), // "s_open_midetail_data_widget"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 4), // "name"
QT_MOC_LITERAL(4, 57, 10), // "start_time"
QT_MOC_LITERAL(5, 68, 9), // "stop_time"
QT_MOC_LITERAL(6, 78, 22), // "s_select_mi_power_data"
QT_MOC_LITERAL(7, 101, 7), // "timeout"
QT_MOC_LITERAL(8, 109, 4), // "path"
QT_MOC_LITERAL(9, 114, 5), // "param"
QT_MOC_LITERAL(10, 120, 20), // "on_select_pb_clicked"
QT_MOC_LITERAL(11, 141, 32), // "on_tableWidget_itemDoubleClicked"
QT_MOC_LITERAL(12, 174, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(13, 192, 4), // "item"
QT_MOC_LITERAL(14, 197, 22), // "onm_display_power_data"
QT_MOC_LITERAL(15, 220, 4) // "data"

    },
    "select_mi_power_widget\0"
    "s_open_midetail_data_widget\0\0name\0"
    "start_time\0stop_time\0s_select_mi_power_data\0"
    "timeout\0path\0param\0on_select_pb_clicked\0"
    "on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0onm_display_power_data\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_select_mi_power_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    3,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   53,    2, 0x08 /* Private */,
      11,    1,   54,    2, 0x08 /* Private */,
      14,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    8,   15,

       0        // eod
};

void select_mi_power_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<select_mi_power_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_open_midetail_data_widget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->s_select_mi_power_data((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 2: _t->on_select_pb_clicked(); break;
        case 3: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onm_display_power_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (select_mi_power_widget::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&select_mi_power_widget::s_open_midetail_data_widget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (select_mi_power_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&select_mi_power_widget::s_select_mi_power_data)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject select_mi_power_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_select_mi_power_widget.data,
    qt_meta_data_select_mi_power_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *select_mi_power_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *select_mi_power_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_select_mi_power_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int select_mi_power_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void select_mi_power_widget::s_open_midetail_data_widget(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void select_mi_power_widget::s_select_mi_power_data(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
