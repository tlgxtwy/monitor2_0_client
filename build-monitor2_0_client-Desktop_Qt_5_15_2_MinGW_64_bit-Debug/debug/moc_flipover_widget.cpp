/****************************************************************************
** Meta object code from reading C++ file 'flipover_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/flipover_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flipover_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_flipover_widget_t {
    QByteArrayData data[10];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_flipover_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_flipover_widget_t qt_meta_stringdata_flipover_widget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "flipover_widget"
QT_MOC_LITERAL(1, 16, 17), // "s_new_page_select"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18), // "on_next_bt_clicked"
QT_MOC_LITERAL(4, 54, 22), // "on_previous_bt_clicked"
QT_MOC_LITERAL(5, 77, 19), // "on_first_bt_clicked"
QT_MOC_LITERAL(6, 97, 18), // "on_last_bt_clicked"
QT_MOC_LITERAL(7, 116, 37), // "on_onepagenumm_cb_currentInde..."
QT_MOC_LITERAL(8, 154, 5), // "index"
QT_MOC_LITERAL(9, 160, 29) // "on_jump_ledit_editingFinished"

    },
    "flipover_widget\0s_new_page_select\0\0"
    "on_next_bt_clicked\0on_previous_bt_clicked\0"
    "on_first_bt_clicked\0on_last_bt_clicked\0"
    "on_onepagenumm_cb_currentIndexChanged\0"
    "index\0on_jump_ledit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_flipover_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void flipover_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<flipover_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_new_page_select(); break;
        case 1: _t->on_next_bt_clicked(); break;
        case 2: _t->on_previous_bt_clicked(); break;
        case 3: _t->on_first_bt_clicked(); break;
        case 4: _t->on_last_bt_clicked(); break;
        case 5: _t->on_onepagenumm_cb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_jump_ledit_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (flipover_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&flipover_widget::s_new_page_select)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject flipover_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_flipover_widget.data,
    qt_meta_data_flipover_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *flipover_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *flipover_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_flipover_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int flipover_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void flipover_widget::s_new_page_select()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
