/****************************************************************************
** Meta object code from reading C++ file 'draw_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/draw_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draw_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_draw_widget_t {
    QByteArrayData data[11];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_draw_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_draw_widget_t qt_meta_stringdata_draw_widget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "draw_widget"
QT_MOC_LITERAL(1, 12, 18), // "onm_plot_tip_event"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 45, 5), // "event"
QT_MOC_LITERAL(5, 51, 17), // "on_eff_rb_clicked"
QT_MOC_LITERAL(6, 69, 19), // "on_power_rb_clicked"
QT_MOC_LITERAL(7, 89, 18), // "on_volt_rb_clicked"
QT_MOC_LITERAL(8, 108, 18), // "on_temp_rb_clicked"
QT_MOC_LITERAL(9, 127, 19), // "on_gvolt_rb_clicked"
QT_MOC_LITERAL(10, 147, 18) // "on_gfre_rb_clicked"

    },
    "draw_widget\0onm_plot_tip_event\0\0"
    "QMouseEvent*\0event\0on_eff_rb_clicked\0"
    "on_power_rb_clicked\0on_volt_rb_clicked\0"
    "on_temp_rb_clicked\0on_gvolt_rb_clicked\0"
    "on_gfre_rb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_draw_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void draw_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<draw_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onm_plot_tip_event((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_eff_rb_clicked(); break;
        case 2: _t->on_power_rb_clicked(); break;
        case 3: _t->on_volt_rb_clicked(); break;
        case 4: _t->on_temp_rb_clicked(); break;
        case 5: _t->on_gvolt_rb_clicked(); break;
        case 6: _t->on_gfre_rb_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject draw_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_draw_widget.data,
    qt_meta_data_draw_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *draw_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *draw_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_draw_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int draw_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE