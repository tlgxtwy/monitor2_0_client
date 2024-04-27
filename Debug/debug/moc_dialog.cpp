/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/control/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[81];
    char stringdata0[1419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 14), // "signal_COP_set"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "Js_COP_set"
QT_MOC_LITERAL(4, 34, 15), // "signal_COP_read"
QT_MOC_LITERAL(5, 50, 11), // "Js_COP_read"
QT_MOC_LITERAL(6, 62, 14), // "signal_COP_Ack"
QT_MOC_LITERAL(7, 77, 7), // "COP_Ack"
QT_MOC_LITERAL(8, 85, 16), // "signal_MaxOP_set"
QT_MOC_LITERAL(9, 102, 12), // "Js_MaxOP_set"
QT_MOC_LITERAL(10, 115, 17), // "signal_MaxOP_read"
QT_MOC_LITERAL(11, 133, 13), // "Js_MaxOP_read"
QT_MOC_LITERAL(12, 147, 16), // "signal_MaxOP_Ack"
QT_MOC_LITERAL(13, 164, 9), // "MaxOP_Ack"
QT_MOC_LITERAL(14, 174, 15), // "signal_Grid_set"
QT_MOC_LITERAL(15, 190, 11), // "Js_Grid_set"
QT_MOC_LITERAL(16, 202, 16), // "signal_Grid_read"
QT_MOC_LITERAL(17, 219, 12), // "Js_Grid_read"
QT_MOC_LITERAL(18, 232, 15), // "signal_Grid_Ack"
QT_MOC_LITERAL(19, 248, 8), // "Grid_Ack"
QT_MOC_LITERAL(20, 257, 18), // "signal_select_back"
QT_MOC_LITERAL(21, 276, 2), // "js"
QT_MOC_LITERAL(22, 279, 14), // "signal_Cer_set"
QT_MOC_LITERAL(23, 294, 10), // "Js_Cer_set"
QT_MOC_LITERAL(24, 305, 15), // "signal_Cer_read"
QT_MOC_LITERAL(25, 321, 11), // "Js_Cer_read"
QT_MOC_LITERAL(26, 333, 14), // "signal_Cer_Ack"
QT_MOC_LITERAL(27, 348, 7), // "Cer_Ack"
QT_MOC_LITERAL(28, 356, 19), // "signal_sendToDialog"
QT_MOC_LITERAL(29, 376, 9), // "str_Grid*"
QT_MOC_LITERAL(30, 386, 10), // "s_str_Grid"
QT_MOC_LITERAL(31, 397, 8), // "str_Cer*"
QT_MOC_LITERAL(32, 406, 9), // "s_str_Cer"
QT_MOC_LITERAL(33, 416, 19), // "signal_sendFilePath"
QT_MOC_LITERAL(34, 436, 8), // "filePaht"
QT_MOC_LITERAL(35, 445, 15), // "log_receiveData"
QT_MOC_LITERAL(36, 461, 4), // "data"
QT_MOC_LITERAL(37, 466, 16), // "log_receiveData1"
QT_MOC_LITERAL(38, 483, 22), // "QHash<QString,QString>"
QT_MOC_LITERAL(39, 506, 11), // "slot_setCID"
QT_MOC_LITERAL(40, 518, 3), // "CID"
QT_MOC_LITERAL(41, 522, 6), // "EMUCID"
QT_MOC_LITERAL(42, 529, 7), // "STATION"
QT_MOC_LITERAL(43, 537, 15), // "slot_receiveCOP"
QT_MOC_LITERAL(44, 553, 6), // "Re_COP"
QT_MOC_LITERAL(45, 560, 17), // "slot_receiveMaxOP"
QT_MOC_LITERAL(46, 578, 8), // "Re_MaxOP"
QT_MOC_LITERAL(47, 587, 16), // "slot_receiveGrid"
QT_MOC_LITERAL(48, 604, 7), // "Re_Grid"
QT_MOC_LITERAL(49, 612, 15), // "slot_receiveCer"
QT_MOC_LITERAL(50, 628, 6), // "Re_Cer"
QT_MOC_LITERAL(51, 635, 13), // "slot_fileSave"
QT_MOC_LITERAL(52, 649, 8), // "fileName"
QT_MOC_LITERAL(53, 658, 13), // "slot_openFile"
QT_MOC_LITERAL(54, 672, 29), // "slot_set_maxop_read_back_flag"
QT_MOC_LITERAL(55, 702, 10), // "old_status"
QT_MOC_LITERAL(56, 713, 6), // "status"
QT_MOC_LITERAL(57, 720, 27), // "slot_set_cop_read_back_flag"
QT_MOC_LITERAL(58, 748, 28), // "slot_set_grid_read_back_flag"
QT_MOC_LITERAL(59, 777, 27), // "slot_set_cer_read_back_flag"
QT_MOC_LITERAL(60, 805, 31), // "slot_set_r_maxop_read_back_flag"
QT_MOC_LITERAL(61, 837, 29), // "slot_set_r_cop_read_back_flag"
QT_MOC_LITERAL(62, 867, 30), // "slot_set_r_grid_read_back_flag"
QT_MOC_LITERAL(63, 898, 29), // "slot_set_r_cer_read_back_flag"
QT_MOC_LITERAL(64, 928, 18), // "onm_timer_callback"
QT_MOC_LITERAL(65, 947, 32), // "on_pushButton_MaxOP_read_clicked"
QT_MOC_LITERAL(66, 980, 31), // "on_pushButton_MaxOP_set_clicked"
QT_MOC_LITERAL(67, 1012, 29), // "on_pushButton_COP_set_clicked"
QT_MOC_LITERAL(68, 1042, 30), // "on_pushButton_COP_read_clicked"
QT_MOC_LITERAL(69, 1073, 29), // "on_pushButton_GridSet_clicked"
QT_MOC_LITERAL(70, 1103, 30), // "on_pushButton_GridRead_clicked"
QT_MOC_LITERAL(71, 1134, 29), // "on_pushButton_CerRead_clicked"
QT_MOC_LITERAL(72, 1164, 28), // "on_pushButton_CerSet_clicked"
QT_MOC_LITERAL(73, 1193, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(74, 1219, 28), // "on_pushButton_update_clicked"
QT_MOC_LITERAL(75, 1248, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(76, 1277, 33), // "on_comboBox_program_textActiv..."
QT_MOC_LITERAL(77, 1311, 4), // "arg1"
QT_MOC_LITERAL(78, 1316, 38), // "on_comboBox_program_currentTe..."
QT_MOC_LITERAL(79, 1355, 34), // "on_comboBox_CID_currentTextCh..."
QT_MOC_LITERAL(80, 1390, 28) // "on_checkBox_all_stateChanged"

    },
    "Dialog\0signal_COP_set\0\0Js_COP_set\0"
    "signal_COP_read\0Js_COP_read\0signal_COP_Ack\0"
    "COP_Ack\0signal_MaxOP_set\0Js_MaxOP_set\0"
    "signal_MaxOP_read\0Js_MaxOP_read\0"
    "signal_MaxOP_Ack\0MaxOP_Ack\0signal_Grid_set\0"
    "Js_Grid_set\0signal_Grid_read\0Js_Grid_read\0"
    "signal_Grid_Ack\0Grid_Ack\0signal_select_back\0"
    "js\0signal_Cer_set\0Js_Cer_set\0"
    "signal_Cer_read\0Js_Cer_read\0signal_Cer_Ack\0"
    "Cer_Ack\0signal_sendToDialog\0str_Grid*\0"
    "s_str_Grid\0str_Cer*\0s_str_Cer\0"
    "signal_sendFilePath\0filePaht\0"
    "log_receiveData\0data\0log_receiveData1\0"
    "QHash<QString,QString>\0slot_setCID\0"
    "CID\0EMUCID\0STATION\0slot_receiveCOP\0"
    "Re_COP\0slot_receiveMaxOP\0Re_MaxOP\0"
    "slot_receiveGrid\0Re_Grid\0slot_receiveCer\0"
    "Re_Cer\0slot_fileSave\0fileName\0"
    "slot_openFile\0slot_set_maxop_read_back_flag\0"
    "old_status\0status\0slot_set_cop_read_back_flag\0"
    "slot_set_grid_read_back_flag\0"
    "slot_set_cer_read_back_flag\0"
    "slot_set_r_maxop_read_back_flag\0"
    "slot_set_r_cop_read_back_flag\0"
    "slot_set_r_grid_read_back_flag\0"
    "slot_set_r_cer_read_back_flag\0"
    "onm_timer_callback\0on_pushButton_MaxOP_read_clicked\0"
    "on_pushButton_MaxOP_set_clicked\0"
    "on_pushButton_COP_set_clicked\0"
    "on_pushButton_COP_read_clicked\0"
    "on_pushButton_GridSet_clicked\0"
    "on_pushButton_GridRead_clicked\0"
    "on_pushButton_CerRead_clicked\0"
    "on_pushButton_CerSet_clicked\0"
    "on_pushButton_add_clicked\0"
    "on_pushButton_update_clicked\0"
    "on_pushButton_delete_clicked\0"
    "on_comboBox_program_textActivated\0"
    "arg1\0on_comboBox_program_currentTextChanged\0"
    "on_comboBox_CID_currentTextChanged\0"
    "on_checkBox_all_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       4,    1,  257,    2, 0x06 /* Public */,
       6,    1,  260,    2, 0x06 /* Public */,
       8,    1,  263,    2, 0x06 /* Public */,
      10,    1,  266,    2, 0x06 /* Public */,
      12,    1,  269,    2, 0x06 /* Public */,
      14,    1,  272,    2, 0x06 /* Public */,
      16,    1,  275,    2, 0x06 /* Public */,
      18,    1,  278,    2, 0x06 /* Public */,
      20,    1,  281,    2, 0x06 /* Public */,
      22,    1,  284,    2, 0x06 /* Public */,
      24,    1,  287,    2, 0x06 /* Public */,
      26,    1,  290,    2, 0x06 /* Public */,
      28,    2,  293,    2, 0x06 /* Public */,
      33,    1,  298,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      35,    1,  301,    2, 0x0a /* Public */,
      37,    1,  304,    2, 0x0a /* Public */,
      39,    3,  307,    2, 0x0a /* Public */,
      43,    1,  314,    2, 0x0a /* Public */,
      45,    1,  317,    2, 0x0a /* Public */,
      47,    1,  320,    2, 0x0a /* Public */,
      49,    1,  323,    2, 0x0a /* Public */,
      51,    1,  326,    2, 0x0a /* Public */,
      53,    0,  329,    2, 0x0a /* Public */,
      54,    2,  330,    2, 0x0a /* Public */,
      57,    2,  335,    2, 0x0a /* Public */,
      58,    2,  340,    2, 0x0a /* Public */,
      59,    2,  345,    2, 0x0a /* Public */,
      60,    2,  350,    2, 0x0a /* Public */,
      61,    2,  355,    2, 0x0a /* Public */,
      62,    2,  360,    2, 0x0a /* Public */,
      63,    2,  365,    2, 0x0a /* Public */,
      64,    0,  370,    2, 0x0a /* Public */,
      65,    0,  371,    2, 0x08 /* Private */,
      66,    0,  372,    2, 0x08 /* Private */,
      67,    0,  373,    2, 0x08 /* Private */,
      68,    0,  374,    2, 0x08 /* Private */,
      69,    0,  375,    2, 0x08 /* Private */,
      70,    0,  376,    2, 0x08 /* Private */,
      71,    0,  377,    2, 0x08 /* Private */,
      72,    0,  378,    2, 0x08 /* Private */,
      73,    0,  379,    2, 0x08 /* Private */,
      74,    0,  380,    2, 0x08 /* Private */,
      75,    0,  381,    2, 0x08 /* Private */,
      76,    1,  382,    2, 0x08 /* Private */,
      78,    1,  385,    2, 0x08 /* Private */,
      79,    1,  388,    2, 0x08 /* Private */,
      80,    1,  391,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QJsonObject,   15,
    QMetaType::Void, QMetaType::QJsonObject,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QJsonObject,   21,
    QMetaType::Void, QMetaType::QJsonObject,   23,
    QMetaType::Void, QMetaType::QJsonObject,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, 0x80000000 | 29, 0x80000000 | 31,   30,   32,
    QMetaType::Void, QMetaType::QString,   34,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void, 0x80000000 | 38,   36,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::QString,   40,   41,   42,
    QMetaType::Void, 0x80000000 | 38,   44,
    QMetaType::Void, 0x80000000 | 38,   46,
    QMetaType::Void, 0x80000000 | 38,   48,
    QMetaType::Void, 0x80000000 | 38,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   55,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void, QMetaType::Int,   77,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_COP_set((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->signal_COP_read((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->signal_COP_Ack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signal_MaxOP_set((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->signal_MaxOP_read((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->signal_MaxOP_Ack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->signal_Grid_set((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 7: _t->signal_Grid_read((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: _t->signal_Grid_Ack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->signal_select_back((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 10: _t->signal_Cer_set((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 11: _t->signal_Cer_read((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 12: _t->signal_Cer_Ack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->signal_sendToDialog((*reinterpret_cast< str_Grid*(*)>(_a[1])),(*reinterpret_cast< str_Cer*(*)>(_a[2]))); break;
        case 14: _t->signal_sendFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->log_receiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->log_receiveData1((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 17: _t->slot_setCID((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 18: _t->slot_receiveCOP((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 19: _t->slot_receiveMaxOP((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 20: _t->slot_receiveGrid((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 21: _t->slot_receiveCer((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 22: _t->slot_fileSave((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->slot_openFile(); break;
        case 24: _t->slot_set_maxop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 25: _t->slot_set_cop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->slot_set_grid_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 27: _t->slot_set_cer_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 28: _t->slot_set_r_maxop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 29: _t->slot_set_r_cop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 30: _t->slot_set_r_grid_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->slot_set_r_cer_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 32: _t->onm_timer_callback(); break;
        case 33: _t->on_pushButton_MaxOP_read_clicked(); break;
        case 34: _t->on_pushButton_MaxOP_set_clicked(); break;
        case 35: _t->on_pushButton_COP_set_clicked(); break;
        case 36: _t->on_pushButton_COP_read_clicked(); break;
        case 37: _t->on_pushButton_GridSet_clicked(); break;
        case 38: _t->on_pushButton_GridRead_clicked(); break;
        case 39: _t->on_pushButton_CerRead_clicked(); break;
        case 40: _t->on_pushButton_CerSet_clicked(); break;
        case 41: _t->on_pushButton_add_clicked(); break;
        case 42: _t->on_pushButton_update_clicked(); break;
        case 43: _t->on_pushButton_delete_clicked(); break;
        case 44: _t->on_comboBox_program_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->on_comboBox_program_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_comboBox_CID_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->on_checkBox_all_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_COP_set)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_COP_read)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_COP_Ack)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_MaxOP_set)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_MaxOP_read)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_MaxOP_Ack)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Grid_set)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Grid_read)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Grid_Ack)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_select_back)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Cer_set)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Cer_read)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_Cer_Ack)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(str_Grid * , str_Cer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_sendToDialog)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::signal_sendFilePath)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void Dialog::signal_COP_set(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog::signal_COP_read(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog::signal_COP_Ack(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dialog::signal_MaxOP_set(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dialog::signal_MaxOP_read(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dialog::signal_MaxOP_Ack(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Dialog::signal_Grid_set(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Dialog::signal_Grid_read(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Dialog::signal_Grid_Ack(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Dialog::signal_select_back(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Dialog::signal_Cer_set(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Dialog::signal_Cer_read(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Dialog::signal_Cer_Ack(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Dialog::signal_sendToDialog(str_Grid * _t1, str_Cer * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Dialog::signal_sendFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
