/****************************************************************************
** Meta object code from reading C++ file 'cs_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SYS/client/cs_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cs_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cs_client_t {
    QByteArrayData data[26];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs_client_t qt_meta_stringdata_cs_client = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cs_client"
QT_MOC_LITERAL(1, 10, 9), // "s_cs_test"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 2), // "tt"
QT_MOC_LITERAL(4, 24, 20), // "s_cs_request_new_msg"
QT_MOC_LITERAL(5, 45, 4), // "path"
QT_MOC_LITERAL(6, 50, 3), // "obj"
QT_MOC_LITERAL(7, 54, 20), // "s_cs_request_timeout"
QT_MOC_LITERAL(8, 75, 17), // "s_cs_request_busy"
QT_MOC_LITERAL(9, 93, 23), // "s_cs_request_err_status"
QT_MOC_LITERAL(10, 117, 3), // "url"
QT_MOC_LITERAL(11, 121, 11), // "status_code"
QT_MOC_LITERAL(12, 133, 8), // "onm_send"
QT_MOC_LITERAL(13, 142, 7), // "timeout"
QT_MOC_LITERAL(14, 150, 5), // "param"
QT_MOC_LITERAL(15, 156, 13), // "onm_send_user"
QT_MOC_LITERAL(16, 170, 6), // "server"
QT_MOC_LITERAL(17, 177, 7), // "account"
QT_MOC_LITERAL(18, 185, 8), // "password"
QT_MOC_LITERAL(19, 194, 8), // "onm_recv"
QT_MOC_LITERAL(20, 203, 14), // "QNetworkReply*"
QT_MOC_LITERAL(21, 218, 5), // "reply"
QT_MOC_LITERAL(22, 224, 8), // "onm_stop"
QT_MOC_LITERAL(23, 233, 18), // "onm_timer_callback"
QT_MOC_LITERAL(24, 252, 9), // "onm_start"
QT_MOC_LITERAL(25, 262, 24) // "onm_set_account_password"

    },
    "cs_client\0s_cs_test\0\0tt\0s_cs_request_new_msg\0"
    "path\0obj\0s_cs_request_timeout\0"
    "s_cs_request_busy\0s_cs_request_err_status\0"
    "url\0status_code\0onm_send\0timeout\0param\0"
    "onm_send_user\0server\0account\0password\0"
    "onm_recv\0QNetworkReply*\0reply\0onm_stop\0"
    "onm_timer_callback\0onm_start\0"
    "onm_set_account_password"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,
       8,    0,   83,    2, 0x06 /* Public */,
       9,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    3,   89,    2, 0x0a /* Public */,
      15,    6,   96,    2, 0x0a /* Public */,
      19,    1,  109,    2, 0x0a /* Public */,
      22,    0,  112,    2, 0x0a /* Public */,
      23,    0,  113,    2, 0x0a /* Public */,
      24,    0,  114,    2, 0x0a /* Public */,
      25,    2,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,   13,   10,   14,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   10,   14,   16,   17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,

       0        // eod
};

void cs_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cs_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_cs_test((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->s_cs_request_new_msg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 2: _t->s_cs_request_timeout(); break;
        case 3: _t->s_cs_request_busy(); break;
        case 4: _t->s_cs_request_err_status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->onm_send((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 6: _t->onm_send_user((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 7: _t->onm_recv((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->onm_stop(); break;
        case 9: _t->onm_timer_callback(); break;
        case 10: _t->onm_start(); break;
        case 11: _t->onm_set_account_password((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cs_client::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cs_client::s_cs_test)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (cs_client::*)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cs_client::s_cs_request_new_msg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (cs_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cs_client::s_cs_request_timeout)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (cs_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cs_client::s_cs_request_busy)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (cs_client::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cs_client::s_cs_request_err_status)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cs_client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cs_client.data,
    qt_meta_data_cs_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cs_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cs_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cs_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void cs_client::s_cs_test(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cs_client::s_cs_request_new_msg(QString _t1, QJsonObject _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cs_client::s_cs_request_timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void cs_client::s_cs_request_busy()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void cs_client::s_cs_request_err_status(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
