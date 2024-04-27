#ifndef FLIPOVER_WIDGET_H
#define FLIPOVER_WIDGET_H

#include <QWidget>

namespace Ui {
class flipover_widget;
}

class flipover_widget : public QWidget
{
    Q_OBJECT

public:
    explicit flipover_widget(QWidget *parent = nullptr);
    ~flipover_widget();
    void set_page_num(uint64_t data_num); //设置页数

    uint get_page_index();   //获取索引的起始index
    uint8_t get_one_page_num();  //获取一页显示的数据量
signals:
    void s_new_page_select();
private:
    Ui::flipover_widget *ui;
    uint64_t m_page_num;
    uint64_t m_data_num;
    void set_page_bt_state();  //设置翻页控件状态
protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_next_bt_clicked();
    void on_previous_bt_clicked();
    void on_first_bt_clicked();
    void on_last_bt_clicked();
    void on_onepagenumm_cb_currentIndexChanged(int index);
    void on_jump_ledit_editingFinished();
};

#endif // FLIPOVER_WIDGET_H
