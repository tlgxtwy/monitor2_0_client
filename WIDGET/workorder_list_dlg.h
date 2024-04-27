#ifndef WORKORDER_LIST_DLG_H
#define WORKORDER_LIST_DLG_H

#include <QDialog>
#include <QVector>
#include <QHash>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

/*
    工单筛选界面
    提供三种查询微逆编号的方式
    1.按微逆编号查询
    2.按工单编号查询
    3.按老化批次查询
*/

namespace Ui {
class workorder_list_dlg;
}

class workorder_list_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit workorder_list_dlg(QWidget *parent = nullptr);
    ~workorder_list_dlg();
    //起始编号和结束编号是否合法（限制单次1000台）
    bool is_mi_cid_valid();

    void write_workorder_success();
    void read_workderorder_success(QString workorder_id,QString series_id,QString extra_id,QString vacant_id,QString update_record);
    //void read_mes_workerorder_success(QString workorder_id,QStringList mi_list);

public slots:
    //获取工单编号  来源李洲权的服务器
    void onm_get_workorder_msg(QString path,QJsonObject obj);
private slots:
    void on_read_pb_clicked();

    void on_a_plus_pb_clicked();

    void on_a_minus_edt_clicked();

    void on_l_plus_pb_clicked();

    void on_l_minus_edt_clicked();

    void on_ok_pb_clicked();

    void on_write_pb_clicked();

    void on_cache_pb_clicked();
    void on_workorder_edt_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

signals:
    //信号:请求业务处理 读取工单内容 //李服务器
    void s_post_workorder_ctl(quint32 timeout,QNetworkRequest req,QByteArray body);
    //HTTP请求:读取工单编号 //李服务器
    void s_get_workorder_mi(quint32 timeout,QNetworkRequest req);
    //->界面: 显示工单下的编号
    void s_get_workorder(QString workorder_id,QStringList mis);
    //HTTP请求:读取工单编号 //自己的服务器
    void s_read_workorder(QString workorder);
    //HTTP请求:向自己的服务器  手动创建一个工单
    void s_write_workorder(QString workorder_id,QString series_id,QString extra_id,QString vacant_id,QString update_record);
private:
    Ui::workorder_list_dlg *ui;

    //QStringList m_mi_list;
    QStringList m_mi_list;

    bool a_plus();
    bool l_plus();

    void clear_all_value();
};

#endif // WORKORDER_LIST_DLG_H
