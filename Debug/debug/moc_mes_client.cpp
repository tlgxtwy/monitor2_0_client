/****************************************************************************
** Meta object code from reading C++ file 'mes_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SYS/client/mes_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mes_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mes_client_t {
    QByteArrayData data[25];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mes_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mes_client_t qt_meta_stringdata_mes_client = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mes_client"
QT_MOC_LITERAL(1, 11, 9), // "s_cs_test"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "tt"
QT_MOC_LITERAL(4, 25, 20), // "s_cs_request_new_msg"
QT_MOC_LITERAL(5, 46, 4), // "path"
QT_MOC_LITERAL(6, 51, 3), // "obj"
QT_MOC_LITERAL(7, 55, 18), // "s_cs_request_error"
QT_MOC_LITERAL(8, 74, 20), // "s_cs_request_timeout"
QT_MOC_LITERAL(9, 95, 17), // "s_cs_request_busy"
QT_MOC_LITERAL(10, 113, 23), // "s_cs_request_err_status"
QT_MOC_LITERAL(11, 137, 3), // "url"
QT_MOC_LITERAL(12, 141, 11), // "status_code"
QT_MOC_LITERAL(13, 153, 8), // "onm_post"
QT_MOC_LITERAL(14, 162, 7), // "timeout"
QT_MOC_LITERAL(15, 170, 15), // "QNetworkRequest"
QT_MOC_LITERAL(16, 186, 3), // "req"
QT_MOC_LITERAL(17, 190, 4), // "body"
QT_MOC_LITERAL(18, 195, 7), // "onm_get"
QT_MOC_LITERAL(19, 203, 8), // "onm_recv"
QT_MOC_LITERAL(20, 212, 14), // "QNetworkReply*"
QT_MOC_LITERAL(21, 227, 5), // "reply"
QT_MOC_LITERAL(22, 233, 8), // "onm_stop"
QT_MOC_LITERAL(23, 242, 18), // "onm_timer_callback"
QT_MOC_LITERAL(24, 261, 9) // "onm_start"

    },
    "mes_client\0s_cs_test\0\0tt\0s_cs_request_new_msg\0"
    "path\0obj\0s_cs_request_error\0"
    "s_cs_request_timeout\0s_cs_request_busy\0"
    "s_cs_request_err_status\0url\0status_code\0"
    "onm_post\0timeout\0QNetworkRequest\0req\0"
    "body\0onm_get\0onm_recv\0QNetworkReply*\0"
    "reply\0onm_stop\0onm_timer_callback\0"
    "onm_start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mes_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       7,    1,   82,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    2,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    3,   92,    2, 0x0a /* Public */,
      18,    2,   99,    2, 0x0a /* Public */,
      19,    1,  104,    2, 0x0a /* Public */,
      22,    0,  107,    2, 0x0a /* Public */,
      23,    0,  108,    2, 0x0a /* Public */,
      24,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 15, QMetaType::QByteArray,   14,   16,   17,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mes_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mes_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_cs_test((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->s_cs_request_new_msg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 2: _t->s_cs_request_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->s_cs_request_timeout(); break;
        case 4: _t->s_cs_request_busy(); break;
        case 5: _t->s_cs_request_err_status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->onm_post((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QNetworkRequest(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 7: _t->onm_get((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QNetworkRequest(*)>(_a[2]))); break;
        case 8: _t->onm_recv((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->onm_stop(); break;
        case 10: _t->onm_timer_callback(); break;
        case 11: _t->onm_start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 8:
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
            using _t = void (mes_client::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_test)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mes_client::*)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_request_new_msg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mes_client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_request_error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mes_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_request_timeout)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (mes_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_request_busy)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (mes_client::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mes_client::s_cs_request_err_status)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mes_client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_mes_client.data,
    qt_meta_data_mes_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mes_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mes_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mes_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mes_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void mes_client::s_cs_test(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mes_client::s_cs_request_new_msg(QString _t1, QJsonObject _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mes_client::s_cs_request_error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mes_client::s_cs_request_timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void mes_client::s_cs_request_busy()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void mes_client::s_cs_request_err_status(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
