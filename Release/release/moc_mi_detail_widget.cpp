/****************************************************************************
** Meta object code from reading C++ file 'mi_detail_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/mi_detail_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mi_detail_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mi_detail_widget_t {
    QByteArrayData data[14];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mi_detail_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mi_detail_widget_t qt_meta_stringdata_mi_detail_widget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "mi_detail_widget"
QT_MOC_LITERAL(1, 17, 19), // "s_select_power_data"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "timeout"
QT_MOC_LITERAL(4, 46, 4), // "path"
QT_MOC_LITERAL(5, 51, 5), // "param"
QT_MOC_LITERAL(6, 57, 21), // "onm_display_plot_data"
QT_MOC_LITERAL(7, 79, 4), // "name"
QT_MOC_LITERAL(8, 84, 4), // "data"
QT_MOC_LITERAL(9, 89, 22), // "onm_display_power_data"
QT_MOC_LITERAL(10, 112, 20), // "onm_set_select_param"
QT_MOC_LITERAL(11, 133, 10), // "start_time"
QT_MOC_LITERAL(12, 144, 9), // "stop_time"
QT_MOC_LITERAL(13, 154, 21) // "on_select1_pb_clicked"

    },
    "mi_detail_widget\0s_select_power_data\0"
    "\0timeout\0path\0param\0onm_display_plot_data\0"
    "name\0data\0onm_display_power_data\0"
    "onm_set_select_param\0start_time\0"
    "stop_time\0on_select1_pb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mi_detail_widget[] = {

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
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   46,    2, 0x0a /* Public */,
       9,    2,   51,    2, 0x0a /* Public */,
      10,    3,   56,    2, 0x0a /* Public */,
      13,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    4,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,   11,   12,
    QMetaType::Void,

       0        // eod
};

void mi_detail_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mi_detail_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_select_power_data((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 1: _t->onm_display_plot_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 2: _t->onm_display_power_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 3: _t->onm_set_select_param((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->on_select1_pb_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mi_detail_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mi_detail_widget::s_select_power_data)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mi_detail_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_mi_detail_widget.data,
    qt_meta_data_mi_detail_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mi_detail_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mi_detail_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mi_detail_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mi_detail_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void mi_detail_widget::s_select_power_data(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
