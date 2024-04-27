#ifndef AGING_MI_WIDGET_H
#define AGING_MI_WIDGET_H

#include <QWidget>

#include "workorder_list_dlg.h"
#include <QHash>
#include <QJsonObject>

#include <QTableWidgetItem>
#include <QStyledItemDelegate>
#include <QTextDocument>
#include <QPainter>

/*
    微逆老化查询的主界面
*/

namespace Ui {
class aging_mi_widget;
}

#define DEFAULT_VALUE_MIN (400000)
#define DEFAULT_VALUE_MAX (-400000)

class NewlineDelegate : public QStyledItemDelegate
{
public:
    //用于表格行扩展
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QString text = index.data(Qt::DisplayRole).toString();
        QStringList lines = text.split("\r");
        QTextDocument doc;

        int role = index.data(Qt::UserRole).toInt();
        if(role == 2)
        {
            painter->fillRect(option.rect, QBrush(QColor(255,79,82)));
        }
        else if(role == 1)
        {
            painter->fillRect(option.rect, QBrush(QColor(240,255,108)));
        }
        else if(role == 3)
        {
            painter->fillRect(option.rect, QBrush(QColor(138,255,165)));
        }
        doc.setDefaultFont(option.font);
        doc.setPlainText(lines.join("\n")); // Use "\n" for newline

        painter->save();

        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        opt.text = "";
        painter->translate(opt.rect.left(), opt.rect.top());
        doc.drawContents(painter);

        painter->restore();
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QString text = index.data(Qt::DisplayRole).toString();
        QStringList lines = text.split("\r");
        QTextDocument doc;
        doc.setDefaultFont(option.font);
        doc.setPlainText(lines.join("\n")); // Use "\n" for newline

        int maxWidth = option.rect.width();
        doc.setTextWidth(maxWidth);

        int maxHeight = 100; // Set a maximum height
        int idealHeight = doc.size().height();
        return QSize(doc.idealWidth(), qMin(idealHeight, maxHeight));
    }
};







class aging_mi_widget : public QWidget
{
    Q_OBJECT

public:
    explicit aging_mi_widget(QWidget *parent = nullptr);
    ~aging_mi_widget();
    //界面: 记录得到工单下的微逆列表 并显示当前的工单号到界面
    void onm_get_workorder_mis(QString workorder_id, QStringList mis);
    //界面: 记录得到某老化批次下的列表 并显示当前的老化时间批次到界面
    void onm_get_batch_mis(QString start_time,QStringList mis);
signals:
    //HTTP请求: 查询工单
    void s_select_workorder(quint32 timeout, QString path, QJsonObject param);
    //HTTP请求:写入工单
    void s_write_workorder(quint32 timeout, QString path, QJsonObject param);
    //HTTP请求:读取老化报告
    void s_read_aging_data(quint32 timeout, QString path, QJsonObject param);
    //打开某微逆的详细数据界面 并显示给定时间段的曲线数据
    void s_open_midetail_data_widget(QString name,QString start_time,QString stop_time);
public slots:
    //查询云端的工单
    void onm_read_cloud_workorder(QString workorder_id);
    //写入云端的工单
    void onm_write_cloud_wororder(QString workorder_id, QString series_id, QString extra_id, QString vacant_id, QString update_record);
    //读取云端的工单成功
    void onm_read_cloud_workorder_success(QJsonObject data);
    //写入云端的工单成功
    void onm_write_cloud_workorder_success();
    //读取老化数据成功
    void onm_read_aging_data_success(QJsonObject data);
private slots:
    //来自界面的操作
    //切换查询模式 工单 批次  编号
    void on_select_way_cb_currentIndexChanged(int index);
    //打开工单查询界面
    void on_sel_workorder_pb_clicked();
    //查询老化报告
    void on_select_pb_clicked();
    //导出老化报告到excel文件中
    void on_export_pb_clicked();
    //打开老化参数配置界面
    void on_pushButton_clicked();
    //打开微逆详细界面
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    //打开批次查询界面
    void on_batch_pb_clicked();

private:
    Ui::aging_mi_widget *ui;

    workorder_list_dlg m_workorder_dlg;

    QHash<QString,QString> m_mis;
    //QStringList m_mis;
    QString m_room;
    QString m_start_time;

    QJsonObject m_report;
    //设置查询模式 工单 批次  编号
    void set_select_way(int id);
    //生成excel文件
    void export_aging_report(QString file_path);
};

#endif // AGING_MI_WIDGET_H
