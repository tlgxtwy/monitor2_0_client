/****************************************************************************
** Meta object code from reading C++ file 'user_login_dlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/user_login_dlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_login_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_user_login_dlg_t {
    QByteArrayData data[21];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_user_login_dlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_user_login_dlg_t qt_meta_stringdata_user_login_dlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "user_login_dlg"
QT_MOC_LITERAL(1, 15, 7), // "s_login"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "timeout"
QT_MOC_LITERAL(4, 32, 4), // "path"
QT_MOC_LITERAL(5, 37, 5), // "param"
QT_MOC_LITERAL(6, 43, 10), // "cloud_path"
QT_MOC_LITERAL(7, 54, 7), // "account"
QT_MOC_LITERAL(8, 62, 8), // "password"
QT_MOC_LITERAL(9, 71, 15), // "s_current_login"
QT_MOC_LITERAL(10, 87, 15), // "onm_password_en"
QT_MOC_LITERAL(11, 103, 16), // "onm_password_dis"
QT_MOC_LITERAL(12, 120, 21), // "onm_new_login_success"
QT_MOC_LITERAL(13, 142, 18), // "onm_new_login_fail"
QT_MOC_LITERAL(14, 161, 11), // "status_code"
QT_MOC_LITERAL(15, 173, 19), // "on_login_pb_clicked"
QT_MOC_LITERAL(16, 193, 18), // "on_exit_pb_clicked"
QT_MOC_LITERAL(17, 212, 33), // "on_account_cb_currentIndexCha..."
QT_MOC_LITERAL(18, 246, 5), // "index"
QT_MOC_LITERAL(19, 252, 32), // "on_account_cb_currentTextChanged"
QT_MOC_LITERAL(20, 285, 4) // "arg1"

    },
    "user_login_dlg\0s_login\0\0timeout\0path\0"
    "param\0cloud_path\0account\0password\0"
    "s_current_login\0onm_password_en\0"
    "onm_password_dis\0onm_new_login_success\0"
    "onm_new_login_fail\0status_code\0"
    "on_login_pb_clicked\0on_exit_pb_clicked\0"
    "on_account_cb_currentIndexChanged\0"
    "index\0on_account_cb_currentTextChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_user_login_dlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   64,    2, 0x06 /* Public */,
       9,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      13,    2,   87,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,
      17,    1,   94,    2, 0x08 /* Private */,
      19,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void user_login_dlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<user_login_dlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_login((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 1: _t->s_current_login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->onm_password_en(); break;
        case 3: _t->onm_password_dis(); break;
        case 4: _t->onm_new_login_success((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onm_new_login_fail((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->on_login_pb_clicked(); break;
        case 7: _t->on_exit_pb_clicked(); break;
        case 8: _t->on_account_cb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_account_cb_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (user_login_dlg::*)(quint32 , QString , QJsonObject , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user_login_dlg::s_login)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (user_login_dlg::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user_login_dlg::s_current_login)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject user_login_dlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_user_login_dlg.data,
    qt_meta_data_user_login_dlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *user_login_dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *user_login_dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_user_login_dlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int user_login_dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void user_login_dlg::s_login(quint32 _t1, QString _t2, QJsonObject _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void user_login_dlg::s_current_login(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
