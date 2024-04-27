#include "workorder_list_dlg.h"
#include "ui_workorder_list_dlg.h"

#include <QMessageBox>
#include "common.h"
//#include "sys_mg/bg_mg.h"
#include "bym_base.h"

workorder_list_dlg::workorder_list_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workorder_list_dlg)
{
    ui->setupUi(this);

    ui->a_table_wd->setColumnCount(1);
    ui->a_table_wd->setHorizontalHeaderLabels(QStringList()<< "微逆列表");
    //设置最后一栏自适应长度
    ui->a_table_wd->horizontalHeader()->setStretchLastSection(true);
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->a_table_wd->setAlternatingRowColors(true);
    //设置不可编辑
    ui->a_table_wd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置为行选中
    ui->a_table_wd->setSelectionBehavior(QTableWidget::SelectRows);
    // 必须设置选中行的背景色 系统默认的是无法代码选中高亮某行
    ui->a_table_wd->setStyleSheet("selection-background-color:rgb(181,204,255)");

    ui->l_table_wd->setColumnCount(1);
    ui->l_table_wd->setHorizontalHeaderLabels(QStringList()<< "微逆列表");
    //设置最后一栏自适应长度
    ui->l_table_wd->horizontalHeader()->setStretchLastSection(true);
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->l_table_wd->setAlternatingRowColors(true);
    //设置不可编辑
    ui->l_table_wd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置为行选中
    ui->l_table_wd->setSelectionBehavior(QTableWidget::SelectRows);
    // 必须设置选中行的背景色 系统默认的是无法代码选中高亮某行
    ui->l_table_wd->setStyleSheet("selection-background-color:rgb(181,204,255)");

    //ui->widget_5->setEnabled(false);

    ui->widget->setDisabled(true);
    ui->widget_5->setDisabled(true);
    ui->write_pb->setDisabled(true);

}

workorder_list_dlg::~workorder_list_dlg()
{
    delete ui;
}

bool workorder_list_dlg::is_mi_cid_valid()
{
    bool ok1 = false,ok2 = false;
    uint32_t start_num = 0,stop_num = 0;

    if(!bym_base::is_cid_valid(ui->start_mi_edt->text()))
    {
        QMessageBox::warning(this, "警告", "连续序列号中,起始微逆编号不符合其规则");
        return false;
    }

    if(!bym_base::is_cid_valid(ui->stop_mi_edt->text()))
    {
        QMessageBox::warning(this, "警告", "连续序列号中,结束微逆编号不符合其规则");
        return false;
    }

    start_num = ui->start_mi_edt->text().toUInt(&ok1,16);
    stop_num = ui->stop_mi_edt->text().toUInt(&ok2,16);
    if(stop_num < start_num)
    {
        QMessageBox::warning(this, "警告", "连续序列号中,起始编号 不能大于 结束编号");
        return false;
    }

    //1000个微逆
    if((stop_num - start_num) > 0x0FFF)
    {
        QMessageBox::warning(this, "警告", "连续序列号中,目前单个工单只支持1000台微逆");
        return false;
    }

    int a_count = ui->a_table_wd->rowCount();
    int l_count = ui->l_table_wd->rowCount();

    for(int i=0;i<a_count;i++)
    {
        if(ui->a_table_wd->item(i,0)->text() >= ui->start_mi_edt->text() &&
           ui->a_table_wd->item(i,0)->text() <= ui->stop_mi_edt->text())
        {
            ui->a_table_wd->removeRow(i);
            i--;
            a_count--;
        }
    }

    for(int i=0;i<l_count;i++)
    {
        if(ui->l_table_wd->item(i,0)->text() < ui->start_mi_edt->text() ||
           ui->l_table_wd->item(i,0)->text() > ui->stop_mi_edt->text())
        {
            ui->l_table_wd->removeRow(i);
            i--;
            l_count--;
        }
    }
    //ui->widget_5->setEnabled(true);
    return true;
}

void workorder_list_dlg::write_workorder_success()
{
    QMessageBox::information(this,"消息提示 ","写入成功");
}

void workorder_list_dlg::read_workderorder_success(QString workorder_id, QString series_id, QString extra_id, QString vacant_id, QString update_record)
{
    bool ret = true;

    clear_all_value();

    ui->workorder_edt->setText(workorder_id);

    if(series_id.length() >=17)
    {
        ui->start_mi_edt->setText(series_id.mid(0,8));
        ui->stop_mi_edt->setText(series_id.mid(9,8));

        if(!bym_base::is_cid_valid(ui->start_mi_edt->text()) ||
           !bym_base::is_cid_valid(ui->stop_mi_edt->text()))
        {
            QMessageBox::information(this,"消息提示 ","连续序列编号异常");
            ret = false;
        }
    }
    else
    {
        if(series_id.length() == 0 && extra_id.length() == 0 && vacant_id.length() == 0 &&
           update_record.length() == 0)
        {
            QMessageBox::information(this,"消息提示 ","在云端系统没有查到当前工单");
        }
        else
        {
            QMessageBox::information(this,"消息提示 ","连续序列数据异常");
        }
        ret = false;
    }

    if(((extra_id.length() +1) % 9) == 0 || extra_id.length() == 0)
    {
        uint32_t mi_size = 0;
        mi_size = (extra_id.length()+1) /9;
        for(uint32_t i=0;i<mi_size;i++)
        {
            QString mi_cid;
            mi_cid = extra_id.mid(i*9,8);
            if(bym_base::is_cid_valid(mi_cid))
            {
                ui->a_mi_edt->setText(mi_cid);
                if(!a_plus())
                {
                    ret = false;
                    break;
                }
            }
            else {
                QMessageBox::warning(this, "警告", "微逆编号" + mi_cid + "不符合其规则");
                ret = false;
                break;
            }
        }
    }
    else
    {
        QMessageBox::information(this,"消息提示 ","额外微逆序号异常");
        ret = false;
    }

    if(((vacant_id.length() +1) % 9) == 0 || vacant_id.length() == 0)
    {
        uint32_t mi_size = 0;
        mi_size = (vacant_id.length()+1) /9;
        for(uint32_t i=0;i<mi_size;i++)
        {
            QString mi_cid;
            mi_cid = vacant_id.mid(i*9,8);
            if(bym_base::is_cid_valid(mi_cid))
            {
                ui->l_mi_edt->setText(mi_cid);

                if(!l_plus())
                {
                    ret = false;
                    break;
                }
            }
            else {
                QMessageBox::warning(this, "警告", "微逆编号" + mi_cid + "不符合其规则");
                ret = false;
                break;
            }
        }
    }
    else
    {
        QMessageBox::information(this,"消息提示 ","缺少微逆序号异常");
        ret = false;
    }

    if(ret)
    {
        QMessageBox::information(this,"消息提示 ","读取成功");
        ui->a_mi_edt->clear();
        ui->l_mi_edt->clear();
    }
    else
    {
        clear_all_value();
    }
}

void workorder_list_dlg::onm_get_workorder_msg(QString path, QJsonObject obj)
{
    if(path == "/blade-auth/token")
    {
        QString work_order = ui->workorder_edt->text();
        QNetworkRequest req;
        QUrl tmp_url("http://192.168.1.248:81/protrace/halfproducttrace/list");
        QUrlQuery tmp_url_quy;


        work_order.replace("+","%2B");
//        work_order.remove(10,1);
//        work_order.insert(10,"%2B");

        tmp_url_quy.addQueryItem("docNumber",work_order);
        tmp_url_quy.addQueryItem("size","1000");
        tmp_url_quy.addQueryItem("productOrder","10");
        tmp_url.setQuery(tmp_url_quy);
        req.setUrl(tmp_url);

        req.setRawHeader("Authorization","Basic c2FiZXI6c2FiZXJfc2VjcmV0");
        req.setRawHeader("Tenant-Id","000000");
        req.setRawHeader("blade-auth",QString(obj.value("data").toObject().value("tokenType").toString()+
                         " " + obj.value("data").toObject().value("refreshToken").toString()).toUtf8());
        //req.setRawHeader("blade-auth","bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJpc3N1c2VyIiwiYXVkIjoiYXVkaWVuY2UiLCJ1c2VyX2lkIjoiMTY4NDM4NzA0ODEyNTI4NDM1MyIsInRva2VuX3R5cGUiOiJyZWZyZXNoX3Rva2VuIiwiY2xpZW50X2lkIjoic2FiZXIiLCJleHAiOjE2OTExMzIyMTQsIm5iZiI6MTY5MDUyNzQxNH0.OmF4Kh4r3_XzM4lz4fKFZAJ24d-2ByApn1Ro3gdmEpg");

        emit s_get_workorder_mi(5000,req);
    }
    else if(path == "/protrace/halfproducttrace/list")
    {
        QJsonArray datas = obj.value("data").toObject().value("records").toArray();
        m_mi_list.clear();
        for(int i=0;i<datas.size();i++)
        {
            QString mi_cid = datas[i].toObject().value("halfProductCode").toString();
            m_mi_list.append(mi_cid);
        }

        QMessageBox::information(this,"消息提示 ","读取工单成功 有过功率测试记录的微逆数量:" + QString::number(m_mi_list.size()));
    }
}


//void workorder_list_dlg::read_mes_workerorder_success(QString workorder_id, QStringList mi_list)
//{
//    QMessageBox::information(this,"消息提示 ","读取成功");
//    m_mi_list = mi_list;
//}


void workorder_list_dlg::on_read_pb_clicked()
{
    m_mi_list.clear();
    //云端系统
    if(ui->comboBox->currentIndex() == 0)
    {
        QByteArray body(0);
        QNetworkRequest req;
        QUrl tmp_url("http://192.168.1.248:81/blade-auth/token");
        QUrlQuery tmp_url_quy;
        tmp_url_quy.addQueryItem("account","查看");
        tmp_url_quy.addQueryItem("grantType","password");
        tmp_url_quy.addQueryItem("password","123456");
        tmp_url_quy.addQueryItem("refreshToken","36000");
        tmp_url_quy.addQueryItem("tenantId","000000");
        tmp_url.setQuery(tmp_url_quy);
        req.setUrl(tmp_url);

        req.setRawHeader("Authorization","Basic c2FiZXI6c2FiZXJfc2VjcmV0");
        req.setRawHeader("Tenant-Id","000000");

        emit s_post_workorder_ctl(3000,req,body);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        emit s_read_workorder(ui->workorder_edt->text());

    }
}


void workorder_list_dlg::on_a_plus_pb_clicked()
{
    if(!is_mi_cid_valid())
    {
        return;
    }
    a_plus();
}


void workorder_list_dlg::on_a_minus_edt_clicked()
{
    int a_count = ui->a_table_wd->rowCount();
    int i=0;

    if(!is_mi_cid_valid())
    {
        return;
    }


    for(i=0;i<a_count;i++)
    {
        if(ui->a_mi_edt->text() == ui->a_table_wd->item(i,0)->text())
        {
            //移除该行
            ui->a_table_wd->removeRow(i);
            return;
        }
    }

    QMessageBox::warning(this, "警告", "当前列表中不存在该编号，无需删除");
}


void workorder_list_dlg::on_l_plus_pb_clicked()
{
    if(!is_mi_cid_valid())
    {
        return;
    }
    l_plus();
}

void workorder_list_dlg::on_l_minus_edt_clicked()
{
    int l_count = ui->l_table_wd->rowCount();
    int i=0;

    if(!is_mi_cid_valid())
    {
        return;
    }

    for(i=0;i<l_count;i++)
    {
        if(ui->l_mi_edt->text() == ui->l_table_wd->item(i,0)->text())
        {
            //移除该行
            ui->l_table_wd->removeRow(i);
            return;
        }
    }

    QMessageBox::warning(this, "警告", "当前列表中不存在该编号，无需删除");
}


void workorder_list_dlg::on_ok_pb_clicked()
{
    if(ui->comboBox->currentIndex() == 0)
    {

        emit s_get_workorder(ui->workorder_edt->text(),m_mi_list);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        QString workorder_id;
        QStringList mis;
        if(!is_mi_cid_valid())
        {
            return;
        }

        workorder_id = ui->workorder_edt->text();
        uint32_t start_mi_id = ui->start_mi_edt->text().toUInt();
        uint32_t stop_mi_id = ui->stop_mi_edt->text().toUInt();
        for(uint32_t i=start_mi_id;i<= stop_mi_id;i++)
        {
            mis.append(QString::number(i));

        }

        for(int i=0;i<ui->a_table_wd->rowCount();i++)
        {
            mis.append(ui->a_table_wd->item(i,0)->text());
        }


        for(int i=0;i<ui->l_table_wd->rowCount();i++)
        {
            mis.removeAll(ui->l_table_wd->item(i,0)->text());
        }

        emit s_get_workorder(workorder_id,mis);
    }

    this->close();
}


void workorder_list_dlg::on_write_pb_clicked()
{
    QString workorder_id,series_id,extra_id,vacant_id,update_record;

    if(!bym_base::is_cid_valid(ui->start_mi_edt->text()) ||
       !bym_base::is_cid_valid(ui->stop_mi_edt->text()))
    {
        QMessageBox::information(this,"消息提示 ","连续序列的微逆边号不符合规则");
        return;
    }

    workorder_id = ui->workorder_edt->text();
    series_id = ui->start_mi_edt->text() + "~" + ui->stop_mi_edt->text();
    for(int i=0;i<ui->a_table_wd->rowCount();i++)
    {
        if(i!=0)
            extra_id.append(",");
        extra_id.append(ui->a_table_wd->item(i,0)->text());
    }

    for(int i=0;i<ui->l_table_wd->rowCount();i++)
    {
        if(i!=0)
            vacant_id.append(",");
        vacant_id.append(ui->l_table_wd->item(i,0)->text());
    }

    update_record = common::get_system_detail_time();

    emit s_write_workorder(workorder_id,series_id,extra_id,vacant_id,update_record);
}

bool workorder_list_dlg::a_plus()
{
    int a_count = ui->a_table_wd->rowCount();
    int i=0;

    if(!bym_base::is_cid_valid(ui->a_mi_edt->text()))
    {
        QMessageBox::warning(this, "警告", "当前微逆编号不符合其规则");
        return false;
    }

    if(ui->a_mi_edt->text() >= ui->start_mi_edt->text() &&
       ui->a_mi_edt->text() <= ui->stop_mi_edt->text())
    {
        QMessageBox::warning(this, "警告", "当前微逆编号已经在连续序列中 无需添加");
        return false;
    }

    for(i=0;i<a_count;i++)
    {
        if(ui->a_mi_edt->text() < ui->a_table_wd->item(i,0)->text())
        {
            break;
        }
        else if(ui->a_mi_edt->text() == ui->a_table_wd->item(i,0)->text())
        {
            QMessageBox::warning(this, "警告", "当前微逆列表中已经存在 无需添加");
            return false;
        }
    }
    ui->a_table_wd->insertRow(i);
    ui->a_table_wd->setItem(i,0,new QTableWidgetItem(ui->a_mi_edt->text()));
    ui->a_table_wd->item(i,0)->setTextAlignment(Qt::AlignCenter);

    return true;
}

bool workorder_list_dlg::l_plus()
{
    int l_count = ui->l_table_wd->rowCount();
    int i=0;

    if(!bym_base::is_cid_valid(ui->l_mi_edt->text()))
    {
        QMessageBox::warning(this, "警告", "当前微逆编号不符合其规则");
        return false;
    }

    if(ui->l_mi_edt->text() < ui->start_mi_edt->text() ||
       ui->l_mi_edt->text() > ui->stop_mi_edt->text())
    {
        QMessageBox::warning(this, "警告", "当前微逆编号不在连续序列中 无需添加");
        return false;
    }

    for(i=0;i<l_count;i++)
    {
        if(ui->l_mi_edt->text() < ui->l_table_wd->item(i,0)->text())
        {
            break;
        }
        else if(ui->l_mi_edt->text() == ui->l_table_wd->item(i,0)->text())
        {
            QMessageBox::warning(this, "警告", "当前微逆列表中已经存在 无需添加");
            return false;
        }
    }

    ui->l_table_wd->insertRow(i);
    ui->l_table_wd->setItem(i,0,new QTableWidgetItem(ui->l_mi_edt->text()));
    ui->l_table_wd->item(i,0)->setTextAlignment(Qt::AlignCenter);

    return true;
}

void workorder_list_dlg::clear_all_value()
{
    ui->start_mi_edt->clear();
    ui->stop_mi_edt->clear();
    ui->a_table_wd->clearContents();
    ui->l_table_wd->clearContents();
    ui->a_table_wd->setRowCount(0);
    ui->l_table_wd->setRowCount(0);
    ui->a_mi_edt->clear();
    ui->l_mi_edt->clear();

    m_mi_list.clear();
}


void workorder_list_dlg::on_cache_pb_clicked()
{
    this->close();
}


void workorder_list_dlg::on_workorder_edt_textChanged(const QString &arg1)
{
    clear_all_value();
}


void workorder_list_dlg::on_comboBox_currentIndexChanged(int index)
{
    clear_all_value();
    if(index == 0)
    {
        ui->widget->setDisabled(true);
        ui->widget_5->setDisabled(true);
        ui->write_pb->setDisabled(true);
    }
    else
    {
        ui->widget->setDisabled(false);
        ui->widget_5->setDisabled(false);
        ui->write_pb->setDisabled(false);
    }
}

