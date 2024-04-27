#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QToolTip>
#include <open_lib/QCustomPlot/qcustomplot.h>
#include <QTimer>
//#include "devices/arack_one.h"
//#include "devices/bym_base.h"

/*
    绘图界面
*/

namespace Ui {
class draw_widget;
}
#define PEN_LENGTH   2
class draw_widget : public QWidget
{
    Q_OBJECT

public:
    explicit draw_widget(QWidget *parent = nullptr);
    ~draw_widget();
    void set_name(QString name);

    //设置 x轴range
    void set_x_range(double start,double stop);
    void clear_y_range();
    void plot();
    //显示每项数据  功率 直流电压 温度 电网电压  电网电流 效率（暂时没有使用 效率检测的精度不够）
    void plot_power_data(QVector<double> &time_data,QVector<double> &power_data);
    void plot_pvolt_data(QVector<double> &time_data,QVector<double> &pvlot_data);
    void plot_temp_data(QVector<double> &time_data,QVector<double> &temp_data);
    void plot_gridv_data(QVector<double> &time_data,QVector<double> &gridv_data);
    void plot_gridf_data(QVector<double> &time_data,QVector<double> &gridf_data);
    void plot_eff_data(QVector<double> &time_data,QVector<double> &eff_data);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    //弹出小提示  数据为当前鼠标的坐标
    void onm_plot_tip_event(QMouseEvent *event);  //显示数据提示
    //关闭或开启  某条曲线的显示
    void on_eff_rb_clicked();
    void on_power_rb_clicked();
    void on_volt_rb_clicked();
    void on_temp_rb_clicked();
    void on_gvolt_rb_clicked();
    void on_gfre_rb_clicked();
private:
    Ui::draw_widget *ui;

    //QTimer m_timer;

    QString m_name = "";
    QCPItemText *m_textLabel = nullptr;

    int m_p_nan_point_time = 900; //3600 秒

    double m_yaxis_min = 100000;
    double m_yaxis_max = -100000;

    double get_y_value(uint8_t graph_id,float x_val);
    void plot_tips(double x_val,double y_val);
};

#endif // DRAW_WIDGET_H
