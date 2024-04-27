#ifndef AGING_PLOT_DLG_H
#define AGING_PLOT_DLG_H

#include <QDialog>

namespace Ui {
class aging_plot_dlg;
}

class aging_plot_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit aging_plot_dlg(QString name,QWidget *parent = nullptr);
    ~aging_plot_dlg();

private:
    Ui::aging_plot_dlg *ui;
};

#endif // AGING_PLOT_DLG_H
