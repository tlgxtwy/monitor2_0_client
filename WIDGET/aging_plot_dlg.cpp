#include "aging_plot_dlg.h"
#include "ui_aging_plot_dlg.h"

aging_plot_dlg::aging_plot_dlg(QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aging_plot_dlg)
{
    ui->setupUi(this);

    ui->widget->init_by_name(name);
}

aging_plot_dlg::~aging_plot_dlg()
{
    delete ui;
}
