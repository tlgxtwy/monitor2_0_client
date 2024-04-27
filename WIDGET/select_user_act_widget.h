#ifndef SELECT_USER_ACT_WIDGET_H
#define SELECT_USER_ACT_WIDGET_H

#include <QDialog>
#include <QJsonObject>
#include <QLabel>

/*
    查询用户动作界面
*/


namespace Ui {
class select_user_act_widget;
}


class TooltipPopup : public QLabel
{
public:
    TooltipPopup(QWidget *parent = nullptr) : QLabel(parent)
    {
        setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
        setStyleSheet("QLabel { background-color: lightyellow; border: 1px solid gray; padding: 2px; }");
    }

    void showTooltip(const QString &text, const QPoint &pos)
    {
        setText(text);
        move(pos);
        show();
    }
};


class select_user_act_widget : public QDialog
{
    Q_OBJECT

public:
    explicit select_user_act_widget(QWidget *parent = nullptr);
    ~select_user_act_widget();

private slots:
    //界面: 查询用户操作记录
    void on_select_pb_clicked();
//    void onm_show_tips(int row, int column);
//    void onm_hide_tips();
//protected:
//    void leaveEvent(QEvent *event) override;
public slots:
    //界面: 显示用户操作记录
    void onm_display_user_act(QJsonObject data);

signals:
    //HTTP请求:查询用户记录
    void s_select_user_act(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::select_user_act_widget *ui;

    TooltipPopup m_tips;
};

#endif // SELECT_USER_ACT_WIDGET_H
