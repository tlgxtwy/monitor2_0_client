#include "flipover_widget.h"
#include "ui_flipover_widget.h"
#include <QPainter>
flipover_widget::flipover_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flipover_widget)
{
    ui->setupUi(this);
    ui->allpg_lb->setText("共    条");
    QStringList page_num;
    page_num << tr("50/页") << tr("100/页");
    ui->onepagenumm_cb->addItems(page_num);
    ui->onepagenumm_cb->setCurrentIndex(0);
    ui->current_bt->setText("1");
    ui->previous_bt->setText("<");
    ui->next_bt->setText(">");
    ui->first_bt->setText("<<");
    ui->last_bt->setText(">>");

    ui->current_bt->setEnabled(false);
    ui->first_bt->setEnabled(false);
    ui->previous_bt->setEnabled(false);
    ui->next_bt->setEnabled(false);
    ui->last_bt->setEnabled(false);
    //设置只能输入数字
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->jump_ledit);
    ui->jump_ledit->setValidator( validator );

    //ui->jump_ledit->setEnabled(false);

    m_page_num = 0;
    m_data_num = 0;
    ui->allpg_lb->setText(QString("共%1页").arg(m_page_num));
}

flipover_widget::~flipover_widget()
{
    delete ui;
}

void flipover_widget::set_page_num(uint64_t data_num)
{
    int index = ui->onepagenumm_cb->currentIndex();
    uint8_t onepage_num = 50;  //该组件默认是30
    if(index == 0)
        onepage_num = 50;
    else if(index ==1)
        onepage_num = 100;

    if(data_num == 0)
    {
        m_page_num = 1;
    }
    else {
        m_page_num = data_num / onepage_num;   //总页数
        if(data_num % onepage_num)
            m_page_num +=1;
    }

    m_data_num = data_num;


    ui->allpg_lb->setText(QString("共%1页").arg(m_page_num));

    //根据当前页和总页数
    set_page_bt_state();

}

uint flipover_widget::get_page_index()
{
    uint page_num = ui->current_bt->text().toUInt();
    return (page_num -1) * get_one_page_num();
}

uint8_t flipover_widget::get_one_page_num()
{
    if(ui->onepagenumm_cb->currentIndex() == 0)
        return 50;
    else if(ui->onepagenumm_cb->currentIndex() == 1)
        return 100;
    //默认一页50项
    return 50;
}

void flipover_widget::set_page_bt_state()
{
    uint current_page = ui->current_bt->text().toUInt();
    //如果当前页大于之前总页数 设置为最后一页  一般不会出现
    //总页不只一页
    if(current_page >= m_page_num && m_page_num !=1)
    {
        //设置为最后一页
        ui->current_bt->setText(QString::number(m_page_num));
        ui->current_bt->setEnabled(false);
        ui->first_bt->setEnabled(true);
        ui->previous_bt->setEnabled(true);
        ui->next_bt->setEnabled(false);
        ui->last_bt->setEnabled(false);
    }
    else if(current_page >= m_page_num && m_page_num ==1)
    {
        //设置为最后一页
        ui->current_bt->setText(QString::number(m_page_num));
        ui->current_bt->setEnabled(false);
        ui->first_bt->setEnabled(false);
        ui->previous_bt->setEnabled(false);
        ui->next_bt->setEnabled(false);
        ui->last_bt->setEnabled(false);
    }//不是第一页
    else if(current_page <m_page_num && current_page !=1){
        ui->current_bt->setEnabled(false);
        ui->first_bt->setEnabled(true);
        ui->previous_bt->setEnabled(true);
        ui->next_bt->setEnabled(true);
        ui->last_bt->setEnabled(true);
    }//是第一页
    else if(current_page <m_page_num && current_page ==1){
        ui->current_bt->setEnabled(false);
        ui->first_bt->setEnabled(false);
        ui->previous_bt->setEnabled(false);
        ui->next_bt->setEnabled(true);
        ui->last_bt->setEnabled(true);
    }
}

void flipover_widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor("gray")); //设置画笔记颜色
    p.drawRect(0, 0, width() -1, height() -1); //绘制边框
}

void flipover_widget::on_next_bt_clicked()
{
    uint current_page = ui->current_bt->text().toUInt();
    ui->current_bt->setText(QString::number(current_page +1));
    set_page_bt_state();

    emit s_new_page_select();
}


void flipover_widget::on_previous_bt_clicked()
{
    uint current_page = ui->current_bt->text().toUInt();
    ui->current_bt->setText(QString::number(current_page -1));
    set_page_bt_state();
    emit s_new_page_select();
}


void flipover_widget::on_first_bt_clicked()
{
    //uint current_page = ui->current_bt->text().toUInt();
    ui->current_bt->setText(QString::number(1));
    set_page_bt_state();
    emit s_new_page_select();
}

void flipover_widget::on_last_bt_clicked()
{
    ui->current_bt->setText(QString::number(m_page_num));
    set_page_bt_state();
    emit s_new_page_select();
}


void flipover_widget::on_onepagenumm_cb_currentIndexChanged(int index)
{
    set_page_num(m_data_num);
    ui->current_bt->setText("1");

    set_page_bt_state();
}


void flipover_widget::on_jump_ledit_editingFinished()
{
    //跳转页不为空时
    uint32_t jump_page = 1;

    if(ui->jump_ledit->text() == "" ||ui->jump_ledit->text() == "0")
    {
        jump_page = 1;
    }
    else {
        jump_page = ui->jump_ledit->text().toUInt();
    }

    if(jump_page <= m_page_num)
    {
        ui->current_bt->setText(QString::number(jump_page));
        set_page_bt_state();
        emit s_new_page_select();

    }
    ui->jump_ledit->setText("");
}

