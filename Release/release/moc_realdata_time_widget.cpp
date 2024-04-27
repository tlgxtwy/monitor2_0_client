/****************************************************************************
** Meta object code from reading C++ file 'realdata_time_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WIDGET/realdata_time_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'realdata_time_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_realdata_time_widget_t {
    QByteArrayData data[75];
    char stringdata0[1100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_realdata_time_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_realdata_time_widget_t qt_meta_stringdata_realdata_time_widget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "realdata_time_widget"
QT_MOC_LITERAL(1, 21, 19), // "s_select_power_data"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 7), // "timeout"
QT_MOC_LITERAL(4, 50, 4), // "path"
QT_MOC_LITERAL(5, 55, 5), // "param"
QT_MOC_LITERAL(6, 61, 5), // "s_ctl"
QT_MOC_LITERAL(7, 67, 9), // "s_get_cop"
QT_MOC_LITERAL(8, 77, 22), // "QHash<QString,QString>"
QT_MOC_LITERAL(9, 100, 4), // "data"
QT_MOC_LITERAL(10, 105, 12), // "s_get_max_op"
QT_MOC_LITERAL(11, 118, 10), // "s_get_grid"
QT_MOC_LITERAL(12, 129, 9), // "s_get_cer"
QT_MOC_LITERAL(13, 139, 26), // "s_set_maxop_read_back_flag"
QT_MOC_LITERAL(14, 166, 10), // "old_status"
QT_MOC_LITERAL(15, 177, 6), // "status"
QT_MOC_LITERAL(16, 184, 24), // "s_set_cop_read_back_flag"
QT_MOC_LITERAL(17, 209, 25), // "s_set_grid_read_back_flag"
QT_MOC_LITERAL(18, 235, 24), // "s_set_cer_read_back_flag"
QT_MOC_LITERAL(19, 260, 28), // "s_set_r_maxop_read_back_flag"
QT_MOC_LITERAL(20, 289, 26), // "s_set_r_cop_read_back_flag"
QT_MOC_LITERAL(21, 316, 27), // "s_set_r_grid_read_back_flag"
QT_MOC_LITERAL(22, 344, 26), // "s_set_r_cer_read_back_flag"
QT_MOC_LITERAL(23, 371, 11), // "s_write_log"
QT_MOC_LITERAL(24, 383, 16), // "s_get_emu_status"
QT_MOC_LITERAL(25, 400, 7), // "reserve"
QT_MOC_LITERAL(26, 408, 4), // "func"
QT_MOC_LITERAL(27, 413, 4), // "sign"
QT_MOC_LITERAL(28, 418, 8), // "run_mode"
QT_MOC_LITERAL(29, 427, 4), // "time"
QT_MOC_LITERAL(30, 432, 20), // "s_double_cid_clicked"
QT_MOC_LITERAL(31, 453, 3), // "cid"
QT_MOC_LITERAL(32, 457, 10), // "start_time"
QT_MOC_LITERAL(33, 468, 9), // "stop_time"
QT_MOC_LITERAL(34, 478, 13), // "s_add_station"
QT_MOC_LITERAL(35, 492, 9), // "s_add_emu"
QT_MOC_LITERAL(36, 502, 12), // "s_add_plc_mi"
QT_MOC_LITERAL(37, 515, 13), // "s_add_wifi_mi"
QT_MOC_LITERAL(38, 529, 13), // "s_del_station"
QT_MOC_LITERAL(39, 543, 9), // "s_del_emu"
QT_MOC_LITERAL(40, 553, 8), // "s_del_mi"
QT_MOC_LITERAL(41, 562, 19), // "onm_display_emu_ctl"
QT_MOC_LITERAL(42, 582, 18), // "onm_display_mi_ctl"
QT_MOC_LITERAL(43, 601, 21), // "onm_update_power_data"
QT_MOC_LITERAL(44, 623, 22), // "QMap<QString,station*>"
QT_MOC_LITERAL(45, 646, 9), // "t_station"
QT_MOC_LITERAL(46, 656, 20), // "on_select_bt_clicked"
QT_MOC_LITERAL(47, 677, 31), // "on_treeWidget_itemDoubleClicked"
QT_MOC_LITERAL(48, 709, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(49, 726, 4), // "item"
QT_MOC_LITERAL(50, 731, 6), // "column"
QT_MOC_LITERAL(51, 738, 13), // "onm_show_menu"
QT_MOC_LITERAL(52, 752, 3), // "pos"
QT_MOC_LITERAL(53, 756, 20), // "onm_open_add_emu_dlg"
QT_MOC_LITERAL(54, 777, 23), // "onm_open_add_wifimi_dlg"
QT_MOC_LITERAL(55, 801, 22), // "onm_open_add_plcmi_dlg"
QT_MOC_LITERAL(56, 824, 11), // "onm_ctl_emu"
QT_MOC_LITERAL(57, 836, 14), // "onm_ctl_all_mi"
QT_MOC_LITERAL(58, 851, 14), // "onm_ctl_plc_mi"
QT_MOC_LITERAL(59, 866, 15), // "onm_ctl_wifi_mi"
QT_MOC_LITERAL(60, 882, 22), // "on_add_station_clicked"
QT_MOC_LITERAL(61, 905, 15), // "onm_del_station"
QT_MOC_LITERAL(62, 921, 11), // "onm_del_emu"
QT_MOC_LITERAL(63, 933, 10), // "onm_del_mi"
QT_MOC_LITERAL(64, 944, 11), // "onm_set_cop"
QT_MOC_LITERAL(65, 956, 11), // "onm_get_cop"
QT_MOC_LITERAL(66, 968, 14), // "onm_set_max_op"
QT_MOC_LITERAL(67, 983, 14), // "onm_get_max_op"
QT_MOC_LITERAL(68, 998, 12), // "onm_set_grid"
QT_MOC_LITERAL(69, 1011, 12), // "onm_get_grid"
QT_MOC_LITERAL(70, 1024, 11), // "onm_set_cer"
QT_MOC_LITERAL(71, 1036, 11), // "onm_get_cer"
QT_MOC_LITERAL(72, 1048, 15), // "onm_select_back"
QT_MOC_LITERAL(73, 1064, 16), // "onm_set_emu_func"
QT_MOC_LITERAL(74, 1081, 18) // "onm_get_emu_status"

    },
    "realdata_time_widget\0s_select_power_data\0"
    "\0timeout\0path\0param\0s_ctl\0s_get_cop\0"
    "QHash<QString,QString>\0data\0s_get_max_op\0"
    "s_get_grid\0s_get_cer\0s_set_maxop_read_back_flag\0"
    "old_status\0status\0s_set_cop_read_back_flag\0"
    "s_set_grid_read_back_flag\0"
    "s_set_cer_read_back_flag\0"
    "s_set_r_maxop_read_back_flag\0"
    "s_set_r_cop_read_back_flag\0"
    "s_set_r_grid_read_back_flag\0"
    "s_set_r_cer_read_back_flag\0s_write_log\0"
    "s_get_emu_status\0reserve\0func\0sign\0"
    "run_mode\0time\0s_double_cid_clicked\0"
    "cid\0start_time\0stop_time\0s_add_station\0"
    "s_add_emu\0s_add_plc_mi\0s_add_wifi_mi\0"
    "s_del_station\0s_del_emu\0s_del_mi\0"
    "onm_display_emu_ctl\0onm_display_mi_ctl\0"
    "onm_update_power_data\0QMap<QString,station*>\0"
    "t_station\0on_select_bt_clicked\0"
    "on_treeWidget_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0onm_show_menu\0"
    "pos\0onm_open_add_emu_dlg\0"
    "onm_open_add_wifimi_dlg\0onm_open_add_plcmi_dlg\0"
    "onm_ctl_emu\0onm_ctl_all_mi\0onm_ctl_plc_mi\0"
    "onm_ctl_wifi_mi\0on_add_station_clicked\0"
    "onm_del_station\0onm_del_emu\0onm_del_mi\0"
    "onm_set_cop\0onm_get_cop\0onm_set_max_op\0"
    "onm_get_max_op\0onm_set_grid\0onm_get_grid\0"
    "onm_set_cer\0onm_get_cer\0onm_select_back\0"
    "onm_set_emu_func\0onm_get_emu_status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_realdata_time_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  274,    2, 0x06 /* Public */,
       6,    3,  281,    2, 0x06 /* Public */,
       7,    1,  288,    2, 0x06 /* Public */,
      10,    1,  291,    2, 0x06 /* Public */,
      11,    1,  294,    2, 0x06 /* Public */,
      12,    1,  297,    2, 0x06 /* Public */,
      13,    2,  300,    2, 0x06 /* Public */,
      16,    2,  305,    2, 0x06 /* Public */,
      17,    2,  310,    2, 0x06 /* Public */,
      18,    2,  315,    2, 0x06 /* Public */,
      19,    2,  320,    2, 0x06 /* Public */,
      20,    2,  325,    2, 0x06 /* Public */,
      21,    2,  330,    2, 0x06 /* Public */,
      22,    2,  335,    2, 0x06 /* Public */,
      23,    1,  340,    2, 0x06 /* Public */,
      24,    6,  343,    2, 0x06 /* Public */,
      30,    3,  356,    2, 0x06 /* Public */,
      34,    3,  363,    2, 0x06 /* Public */,
      35,    3,  370,    2, 0x06 /* Public */,
      36,    3,  377,    2, 0x06 /* Public */,
      37,    3,  384,    2, 0x06 /* Public */,
      38,    3,  391,    2, 0x06 /* Public */,
      39,    3,  398,    2, 0x06 /* Public */,
      40,    3,  405,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      41,    2,  412,    2, 0x0a /* Public */,
      42,    2,  417,    2, 0x0a /* Public */,
      43,    1,  422,    2, 0x0a /* Public */,
      46,    0,  425,    2, 0x0a /* Public */,
      47,    2,  426,    2, 0x08 /* Private */,
      51,    1,  431,    2, 0x08 /* Private */,
      53,    0,  434,    2, 0x08 /* Private */,
      54,    0,  435,    2, 0x08 /* Private */,
      55,    0,  436,    2, 0x08 /* Private */,
      56,    0,  437,    2, 0x08 /* Private */,
      57,    0,  438,    2, 0x08 /* Private */,
      58,    0,  439,    2, 0x08 /* Private */,
      59,    0,  440,    2, 0x08 /* Private */,
      60,    0,  441,    2, 0x08 /* Private */,
      61,    0,  442,    2, 0x08 /* Private */,
      62,    0,  443,    2, 0x08 /* Private */,
      63,    0,  444,    2, 0x08 /* Private */,
      64,    1,  445,    2, 0x08 /* Private */,
      65,    1,  448,    2, 0x08 /* Private */,
      66,    1,  451,    2, 0x08 /* Private */,
      67,    1,  454,    2, 0x08 /* Private */,
      68,    1,  457,    2, 0x08 /* Private */,
      69,    1,  460,    2, 0x08 /* Private */,
      70,    1,  463,    2, 0x08 /* Private */,
      71,    1,  466,    2, 0x08 /* Private */,
      72,    1,  469,    2, 0x08 /* Private */,
      73,    1,  472,    2, 0x08 /* Private */,
      74,    1,  475,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   15,   25,   26,   27,   28,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   31,   32,   33,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QJsonObject,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    4,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    4,    9,
    QMetaType::Void, 0x80000000 | 44,   45,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 48, QMetaType::Int,   49,   50,
    QMetaType::Void, QMetaType::QPoint,   52,
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
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,

       0        // eod
};

void realdata_time_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<realdata_time_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_select_power_data((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 1: _t->s_ctl((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 2: _t->s_get_cop((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 3: _t->s_get_max_op((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 4: _t->s_get_grid((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 5: _t->s_get_cer((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 6: _t->s_set_maxop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->s_set_cop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->s_set_grid_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->s_set_cer_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->s_set_r_maxop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->s_set_r_cop_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->s_set_r_grid_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->s_set_r_cer_read_back_flag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->s_write_log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->s_get_emu_status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 16: _t->s_double_cid_clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 17: _t->s_add_station((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 18: _t->s_add_emu((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 19: _t->s_add_plc_mi((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 20: _t->s_add_wifi_mi((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 21: _t->s_del_station((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 22: _t->s_del_emu((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 23: _t->s_del_mi((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 24: _t->onm_display_emu_ctl((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 25: _t->onm_display_mi_ctl((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 26: _t->onm_update_power_data((*reinterpret_cast< QMap<QString,station*>(*)>(_a[1]))); break;
        case 27: _t->on_select_bt_clicked(); break;
        case 28: _t->on_treeWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->onm_show_menu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 30: _t->onm_open_add_emu_dlg(); break;
        case 31: _t->onm_open_add_wifimi_dlg(); break;
        case 32: _t->onm_open_add_plcmi_dlg(); break;
        case 33: _t->onm_ctl_emu(); break;
        case 34: _t->onm_ctl_all_mi(); break;
        case 35: _t->onm_ctl_plc_mi(); break;
        case 36: _t->onm_ctl_wifi_mi(); break;
        case 37: _t->on_add_station_clicked(); break;
        case 38: _t->onm_del_station(); break;
        case 39: _t->onm_del_emu(); break;
        case 40: _t->onm_del_mi(); break;
        case 41: _t->onm_set_cop((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 42: _t->onm_get_cop((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 43: _t->onm_set_max_op((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 44: _t->onm_get_max_op((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 45: _t->onm_set_grid((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 46: _t->onm_get_grid((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 47: _t->onm_set_cer((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 48: _t->onm_get_cer((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 49: _t->onm_select_back((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 50: _t->onm_set_emu_func((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 51: _t->onm_get_emu_status((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_select_power_data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_ctl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QHash<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_get_cop)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QHash<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_get_max_op)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QHash<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_get_grid)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QHash<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_get_cer)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_maxop_read_back_flag)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_cop_read_back_flag)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_grid_read_back_flag)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_cer_read_back_flag)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_r_maxop_read_back_flag)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_r_cop_read_back_flag)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_r_grid_read_back_flag)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_set_r_cer_read_back_flag)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_write_log)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_get_emu_status)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_double_cid_clicked)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_add_station)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_add_emu)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_add_plc_mi)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_add_wifi_mi)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_del_station)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_del_emu)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (realdata_time_widget::*)(quint32 , QString , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&realdata_time_widget::s_del_mi)) {
                *result = 23;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject realdata_time_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_realdata_time_widget.data,
    qt_meta_data_realdata_time_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *realdata_time_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *realdata_time_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_realdata_time_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int realdata_time_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 52;
    }
    return _id;
}

// SIGNAL 0
void realdata_time_widget::s_select_power_data(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void realdata_time_widget::s_ctl(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void realdata_time_widget::s_get_cop(QHash<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void realdata_time_widget::s_get_max_op(QHash<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void realdata_time_widget::s_get_grid(QHash<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void realdata_time_widget::s_get_cer(QHash<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void realdata_time_widget::s_set_maxop_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void realdata_time_widget::s_set_cop_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void realdata_time_widget::s_set_grid_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void realdata_time_widget::s_set_cer_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void realdata_time_widget::s_set_r_maxop_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void realdata_time_widget::s_set_r_cop_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void realdata_time_widget::s_set_r_grid_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void realdata_time_widget::s_set_r_cer_read_back_flag(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void realdata_time_widget::s_write_log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void realdata_time_widget::s_get_emu_status(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void realdata_time_widget::s_double_cid_clicked(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void realdata_time_widget::s_add_station(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void realdata_time_widget::s_add_emu(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void realdata_time_widget::s_add_plc_mi(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void realdata_time_widget::s_add_wifi_mi(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void realdata_time_widget::s_del_station(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void realdata_time_widget::s_del_emu(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void realdata_time_widget::s_del_mi(quint32 _t1, QString _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
