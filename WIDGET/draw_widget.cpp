#include "draw_widget.h"
#include "ui_draw_widget.h"


draw_widget::draw_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::draw_widget)
{
    ui->setupUi(this);

    //注册事件
    ui->plot_->installEventFilter(this);

    m_textLabel = new QCPItemText(ui->plot_);

    // 设置文本样式
    //m_textLabel->setText("Hover over a point");
    m_textLabel->setFont(QFont(font().family(), 10));
    //m_textLabel->setPadding(QMargins(8, 4, 8, 4));
    m_textLabel->setPen(QPen(Qt::black));
   // m_textLabel->setBrush(QBrush(Qt::white));
    m_textLabel->setTextAlignment(Qt::AlignLeft);
    m_textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐
    m_textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);//位置类型（当前轴范围的比例为单位/实际坐标为单位）



    ui->power_rb->setChecked(true);
    ui->volt_rb->setChecked(true);
    ui->temp_rb->setChecked(true);
    ui->gvolt_rb->setChecked(true);
    ui->gfre_rb->setChecked(true);
    //暂时屏蔽 效率
    ui->eff_rb->setChecked(false);

    ui->plot_->addGraph();
    ui->plot_->addGraph();
    ui->plot_->addGraph();
    ui->plot_->addGraph();
    ui->plot_->addGraph();
    ui->plot_->addGraph();
    ui->plot_->addGraph();

    ui->plot_->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));
    ui->plot_->graph(6)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,PEN_LENGTH));

    ui->plot_->graph(0)->setName("0");
    ui->plot_->graph(1)->setName("1");
    ui->plot_->graph(2)->setName("2");
    ui->plot_->graph(3)->setName("3");
    ui->plot_->graph(4)->setName("4");
    ui->plot_->graph(5)->setName("5");
    ui->plot_->graph(6)->setName("6");
    ui->plot_->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                               QCP::iSelectLegend | QCP::iSelectPlottables);
    QPen tmp_pen;
    tmp_pen.setWidth(PEN_LENGTH);
    tmp_pen.setColor(QColor(0,85,255));
    ui->plot_->graph(0)->setPen(tmp_pen);
    tmp_pen.setColor(QColor(255,170,0));
    ui->plot_->graph(1)->setPen(tmp_pen);
    tmp_pen.setColor(QColor(170,170,0));
    ui->plot_->graph(2)->setPen(tmp_pen);
    tmp_pen.setColor(QColor(0,255,0));
    ui->plot_->graph(3)->setPen(tmp_pen);
    tmp_pen.setColor(QColor(255,170,255));
    ui->plot_->graph(4)->setPen(tmp_pen);
    tmp_pen.setColor(QColor(255,0,127));
    ui->plot_->graph(5)->setPen(tmp_pen);
    //设置x轴缩放
    QList<QCPAxis*> axes;
    axes << ui->plot_->xAxis << ui->plot_->yAxis;
    ui->plot_->axisRect()->setRangeZoomAxes(axes);
    ui->plot_->axisRect()->setRangeZoomFactor(1.2,1);

    QSharedPointer<QCPAxisTickerDateTime> timer(new QCPAxisTickerDateTime);
    ui->plot_->xAxis->setTicker(timer);
    timer->setTickCount(24);
    timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    ui->plot_->xAxis->setSubTicks(false);
//    ui->plot_->xAxis->setRange(db_start_date, db_stop_date);
    timer->setDateTimeFormat("yyyy-MM-dd hh:mm");
    //倾斜显示时间刻度值
    ui->plot_->xAxis->setTickLabelRotation(30);
    //ui->plot_->yAxis->setRange(0,720);

    //设置可以选中单个数据点
    ui->plot_->setSelectionRectMode(QCP::srmSelect);
    ui->plot_->graph(0)->setSelectable(QCP::stSingleData);
    ui->plot_->graph(1)->setSelectable(QCP::stSingleData);
    ui->plot_->graph(2)->setSelectable(QCP::stSingleData);
    ui->plot_->graph(3)->setSelectable(QCP::stSingleData);
    ui->plot_->graph(4)->setSelectable(QCP::stSingleData);
    ui->plot_->graph(5)->setSelectable(QCP::stSingleData);

    //屏蔽效率绘图
    ui->plot_->graph(5)->setVisible(false);

    ui->plot_->setMouseTracking(true);

    //connect(ui->plot_,&QCustomPlot::mouseDoubleClick,this,&draw_widget::onm_plot_tip_event);
    connect(ui->plot_,&QCustomPlot::mouseMove,this,&draw_widget::onm_plot_tip_event);
    //connect(ui->plot_,&QCustomPlot::mouseRelease,this,&draw_widget::onm_plot_tip_event);
    //connect(ui->plot_,&QCustomPlot::mousePress,this,&draw_widget::onm_plot_tip_event);
}

draw_widget::~draw_widget()
{
    delete ui;
}

void draw_widget::set_name(QString name)
{
    ui->name_lb->setText(name);
    m_name = name;
}

void draw_widget::set_x_range(double start, double stop)
{
    ui->plot_->xAxis->setRange(start, stop);

}

void draw_widget::clear_y_range()
{
    m_yaxis_max = -100000;
    m_yaxis_min = 100000;

}

void draw_widget::plot()
{
    //绘画
    ui->plot_->replot();
}

void draw_widget::plot_power_data(QVector<double> &time_data, QVector<double> &power_data)
{

    QVector<double> tmp_empty;
    uint old_sec = 0;
    ui->plot_->graph(0)->setData(tmp_empty,tmp_empty);

    if(time_data.size() != power_data.size())
        return ;

    for(int i=0;i<power_data.size();i++)
    {
        if(power_data[i] > m_yaxis_max)
            m_yaxis_max = power_data[i];
        if(power_data[i] < m_yaxis_min)
            m_yaxis_min = power_data[i];

        if(i == 0)
            old_sec = time_data[i];
        else
        {
            //倒序 old > now  时间过长时插入一个空点
            if(old_sec - time_data[i] >= m_p_nan_point_time ||
               old_sec - time_data[i] <= (-m_p_nan_point_time))
            {
                ui->plot_->graph(0)->addData(old_sec/2 + time_data[i]/2 ,qQNaN());
            }
            old_sec = time_data[i];
        }
        ui->plot_->graph(0)->addData(time_data[i],power_data[i]);
    }


    if(ui->power_rb->isChecked())
    {
        ui->plot_->graph(0)->setVisible(true);
    }
    else {
        ui->plot_->graph(0)->setVisible(false);
    }
    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);

}

void draw_widget::plot_pvolt_data(QVector<double> &time_data, QVector<double> &pvlot_data)
{
    QVector<double> tmp_empty;
    uint old_sec = 0;
    ui->plot_->graph(1)->setData(tmp_empty,tmp_empty);
    if(time_data.size() != pvlot_data.size())
        return ;

    for(int i=0;i<pvlot_data.size();i++)
    {
        if(pvlot_data[i] > m_yaxis_max)
            m_yaxis_max = pvlot_data[i];
        if(pvlot_data[i] < m_yaxis_min)
            m_yaxis_min = pvlot_data[i];

        if(i == 0)
            old_sec = time_data[i];
        else
        {
            //倒序 old > now  时间过长时插入一个空点
            if(old_sec - time_data[i] >= m_p_nan_point_time ||
               old_sec - time_data[i] <= (-m_p_nan_point_time))
            {
                ui->plot_->graph(1)->addData(old_sec/2 + time_data[i]/2 ,qQNaN());
            }
            old_sec = time_data[i];
        }


        ui->plot_->graph(1)->addData(time_data[i],pvlot_data[i]);
    }



    if(ui->volt_rb->isChecked())
    {
        ui->plot_->graph(1)->setVisible(true);
    }
    else {
        ui->plot_->graph(1)->setVisible(false);
    }

    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);
}

void draw_widget::plot_temp_data(QVector<double> &time_data, QVector<double> &temp_data)
{
    QVector<double> tmp_empty;
    uint old_sec = 0;
    ui->plot_->graph(2)->setData(tmp_empty,tmp_empty);

    if(time_data.size() != temp_data.size())
        return ;

    for(int i=0;i<temp_data.size();i++)
    {
        if(temp_data[i] > m_yaxis_max)
            m_yaxis_max = temp_data[i];
        if(temp_data[i] < m_yaxis_min)
            m_yaxis_min = temp_data[i];

        if(i == 0)
            old_sec = time_data[i];
        else
        {
            //倒序 old > now  时间过长时插入一个空点
            if(old_sec - time_data[i] >= m_p_nan_point_time ||
               old_sec - time_data[i] <= (-m_p_nan_point_time))
            {
                ui->plot_->graph(2)->addData(old_sec/2 + time_data[i]/2 ,qQNaN());
            }
            old_sec = time_data[i];
        }
        ui->plot_->graph(2)->addData(time_data[i],temp_data[i]);
    }

    if(ui->temp_rb->isChecked())
    {
        ui->plot_->graph(2)->setVisible(true);
    }
    else {
        ui->plot_->graph(2)->setVisible(false);
    }

    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);
}

void draw_widget::plot_gridv_data(QVector<double> &time_data, QVector<double> &gridv_data)
{
    QVector<double> tmp_empty;
    uint old_sec = 0;
    //清空曲线
    ui->plot_->graph(3)->setData(tmp_empty,tmp_empty);

    if(time_data.size() != gridv_data.size())
        return ;

    for(int i=0;i<gridv_data.size();i++)
    {
        if(gridv_data[i] > m_yaxis_max)
            m_yaxis_max = gridv_data[i];
        if(gridv_data[i] < m_yaxis_min)
            m_yaxis_min = gridv_data[i];

        if(i == 0)
            old_sec = time_data[i];
        else
        {
            //倒序 old > now  时间过长时插入一个空点
            if(old_sec - time_data[i] >= m_p_nan_point_time ||
               old_sec - time_data[i] <= (-m_p_nan_point_time))
            {
                ui->plot_->graph(3)->addData(old_sec/2 + time_data[i]/2 ,qQNaN());
            }
            old_sec = time_data[i];
        }
        ui->plot_->graph(3)->addData(time_data[i],gridv_data[i]);
    }


    if(ui->gvolt_rb->isChecked())
    {
        ui->plot_->graph(3)->setVisible(true);
    }
    else {
        ui->plot_->graph(3)->setVisible(false);
    }

    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);
}

void draw_widget::plot_gridf_data(QVector<double> &time_data, QVector<double> &gridf_data)
{
    QVector<double> tmp_empty;
    uint old_sec = 0;
    ui->plot_->graph(4)->setData(tmp_empty,tmp_empty);

    if(time_data.size() != gridf_data.size())
        return ;

    for(int i=0;i<gridf_data.size();i++)
    {
        if(gridf_data[i] > m_yaxis_max)
            m_yaxis_max = gridf_data[i];
        if(gridf_data[i] < m_yaxis_min)
            m_yaxis_min = gridf_data[i];


        if(i == 0)
            old_sec = time_data[i];
        else
        {
            //倒序 old > now  时间过长时插入一个空点
            if(old_sec - time_data[i] >= m_p_nan_point_time ||
               old_sec - time_data[i] <= (-m_p_nan_point_time))
            {
                ui->plot_->graph(4)->addData(old_sec/2 + time_data[i]/2 ,qQNaN());
            }
            old_sec = time_data[i];
        }



        ui->plot_->graph(4)->addData(time_data[i],gridf_data[i]);
    }



    if(ui->gfre_rb->isChecked())
    {
        ui->plot_->graph(4)->setVisible(true);
    }
    else {
        ui->plot_->graph(4)->setVisible(false);
    }

    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);
}

void draw_widget::plot_eff_data(QVector<double> &time_data, QVector<double> &eff_data)
{
//QVector<double> tmp_empty;

    if(time_data.size() != eff_data.size())
        return ;

    for(int i=0;i<eff_data.size();i++)
    {
        if(eff_data[i] > m_yaxis_max)
            m_yaxis_max = eff_data[i];
        if(eff_data[i] < m_yaxis_min)
            m_yaxis_min = eff_data[i];

    }
    ui->plot_->graph(5)->setData(time_data,eff_data);


    if(ui->power_rb->isChecked())
    {
        ui->plot_->graph(5)->setVisible(true);
    }
    else {
        ui->plot_->graph(5)->setVisible(false);
    }

    //重置y轴 坐标
    ui->plot_->yAxis->setRange(m_yaxis_max + 10,m_yaxis_min - 10);
}

bool draw_widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->plot_)
    {
        if(event->type() == QEvent::Leave)
        {
            m_textLabel->position->setCoords(0, 0);
            //m_textLabel->setText(strtooltip);
            m_textLabel->setText("");

            plot();
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}


void draw_widget::onm_plot_tip_event(QMouseEvent *event)
{
    //获取鼠标坐标，相对父窗体坐标
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    //鼠标坐标转化为CustomPlot内部坐标
    float x_val = ui->plot_->xAxis->pixelToCoord(x_pos);
    float y_val = ui->plot_->yAxis->pixelToCoord(y_pos);
    plot_tips(x_val,y_val);
}



void draw_widget::on_eff_rb_clicked()
{
    if(ui->eff_rb->isChecked())
    {
        ui->plot_->graph(5)->setVisible(true);
    }
    else {
        ui->plot_->graph(5)->setVisible(false);
    }

}



void draw_widget::on_power_rb_clicked()
{
    if(ui->power_rb->isChecked())
    {
        ui->plot_->graph(0)->setVisible(true);
    }
    else {
        ui->plot_->graph(0)->setVisible(false);
    }
    plot();
}

void draw_widget::on_volt_rb_clicked()
{
    if(ui->volt_rb->isChecked())
    {
        ui->plot_->graph(1)->setVisible(true);
    }
    else {
        ui->plot_->graph(1)->setVisible(false);
    }
    plot();
}

void draw_widget::on_temp_rb_clicked()
{
    if(ui->temp_rb->isChecked())
    {
        ui->plot_->graph(2)->setVisible(true);
    }
    else {
        ui->plot_->graph(2)->setVisible(false);
    }
    plot();
}

void draw_widget::on_gvolt_rb_clicked()
{
    if(ui->gvolt_rb->isChecked())
    {
        ui->plot_->graph(3)->setVisible(true);
    }
    else {
        ui->plot_->graph(3)->setVisible(false);
    }
    plot();
}

void draw_widget::on_gfre_rb_clicked()
{
    if(ui->gfre_rb->isChecked())
    {
        ui->plot_->graph(4)->setVisible(true);
    }
    else {
        ui->plot_->graph(4)->setVisible(false);
    }
    plot();
}





double draw_widget::get_y_value(uint8_t graph_id, float x_val)
{
    double y = 0;
    QSharedPointer<QCPGraphDataContainer> tmpContainer;
    tmpContainer = ui->plot_->graph(graph_id)->data();
    //使用二分法快速查找所在点数据！！！敲黑板，下边这段是重点
    int low = 0, high = tmpContainer->size();
    while(high > low)
    {
        int middle = (low + high) / 2;
        if(x_val < tmpContainer->constBegin()->mainKey() ||
                x_val > (tmpContainer->constEnd()-1)->mainKey())
            break;

        if(x_val == (tmpContainer->constBegin() + middle)->mainKey())
        {
            y = (tmpContainer->constBegin() + middle)->mainValue();
            break;
        }
        if(x_val > (tmpContainer->constBegin() + middle)->mainKey())
        {
            low = middle;
        }
        else if(x_val < (tmpContainer->constBegin() + middle)->mainKey())
        {
            high = middle;
        }
        if(high - low <= 1)
        {   //差值计算所在位置数据
            y = (tmpContainer->constBegin()+low)->mainValue() + ( (x_val - (tmpContainer->constBegin() + low)->mainKey()) *
                ((tmpContainer->constBegin()+high)->mainValue() - (tmpContainer->constBegin()+low)->mainValue()) ) /
                ((tmpContainer->constBegin()+high)->mainKey() - (tmpContainer->constBegin()+low)->mainKey());
            break;
        }

    }
    return y;
}


void draw_widget::plot_tips(double x_val, double y_val)
{
    //获得x轴坐标位置对应的曲线上y的值
    double power_value = get_y_value(0,x_val);
    double volt_value = get_y_value(1,x_val);
    double temp_value = get_y_value(2,x_val);
    double gvolt_value = get_y_value(3,x_val);
    double gfreq_value = get_y_value(4,x_val);
    double eff_value = get_y_value(5,x_val);

    //曲线的上点坐标位置，用来显示QToolTip提示框
//    float out_x = ui->plot_->xAxis->coordToPixel(x_val);
//    float out_y = ui->plot_->yAxis->coordToPixel(y_val);

    QString date = QDateTime::fromTime_t(x_val).toString("yyyy-MM-dd hh:mm:ss");
    QString strtooltip;
    strtooltip += date + "\r\n";
    if(ui->power_rb->isChecked())
        strtooltip += "发电功率(W): " + QString::number(power_value) + "\r\n";
    if(ui->volt_rb->isChecked())
        strtooltip += "PV电压(V): " + QString::number(volt_value) + "\r\n";
    if(ui->temp_rb->isChecked())
        strtooltip += "温度(℃): " + QString::number(temp_value) + "\r\n";
    if(ui->gvolt_rb->isChecked())
        strtooltip += "并网电压(V): " + QString::number(gvolt_value) + "\r\n";
    if(ui->gfre_rb->isChecked())
        strtooltip += "并网频率(Hz): " + QString::number(gfreq_value) + "\r\n";
    if(ui->eff_rb->isChecked())
        strtooltip += "效率(%): " + QString::number(eff_value) + "\r\n";

    m_textLabel->position->setCoords(0.1, 0.5);
    m_textLabel->setText(strtooltip);

    plot();

}
