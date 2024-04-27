#ifndef CLOSE_BUTTON_H
#define CLOSE_BUTTON_H

#include <QWidget>

namespace Ui {
class close_button;
}

class close_button : public QWidget
{
    Q_OBJECT

public:
    explicit close_button(QString bt_name,QWidget *parent = nullptr);
    ~close_button();

    void set_focus(bool status);           //设置状态选中
//    void set_index(uint32_t widget_index);
//    void set_name(QString name);
//    uint32_t get_index();
    void hide_button();    //隐藏关闭按键
    void show_button();    //显示关闭按键
//    void minus_index_one();  //widget_index -1 接口
private:
    Ui::close_button *ui;
//    uint32_t widget_index;      //界面编号
protected:
    void paintEvent(QPaintEvent *event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;
signals:
    void s_clicked_label(QString name);         //点击文本部分
    void s_clicked_close_button(QString name);  //点击关闭按钮部分
//    void close_button_selected(QString name);
//    void close_button_closed(QString name);
};

#endif // CLOSE_BUTTON_H
