#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
namespace Ui {
class Dialog;
}

struct str_Grid
{
    QString uOV1;
    QString tOV1;
    QString uUV1;
    QString tUV1;
    QString uOF1;
    QString tOF1;
    QString uUF1;
    QString tUF1;
    QString uOV2;
    QString tOV2;
    QString uUV2;
    QString tUV2;
    QString uOF2;
    QString tOF2;
    QString uUF2;
    QString tUF2;
    QString GT;
    QString URov;
    QString URuv;
    QString FRof;
    QString FRuf;
    int superPF;
    int ASPQU;
    int CEIDFU;
    int Var;
    QString HVRT;
    QString LVRT;
    int RatedFreq;
};

struct str_Cer
{
    int Fixed_non_P;
    QString Fixed_non_P_Para;
    int Max_non_P;
    int Remote_P_slope;
    QString Remote_P_slopePara;
    QString Reconnect_P_slope;
    int OverVol_10;
    QString OverVol_10_Para;
    int UF_hyst;
    int UF_hyst_powerOn;
    int LFSM_Mode;
    QString LFSMO_fact;
    QString LFSMO_fdeact;
    QString LFSMO_Droop;
    QString LFSMO_Trec;
    QString LFSMO_P_slope;
    int LFSMO_Pn;  //0 OFF,1按Pn降额
    QString LFSMU_fact;
    QString LFSMU_fdeact;
    QString LFSMU_Droop;
    int Island;
    int DF1;
    int DF2;
    int FVRT;
    QString ratedVol;
    int PU_mode;
    QString PU_InitialVol;
    QString PU_EndVol;
    QString PU_Droop;
    QString PU_DroopSpd;
    int QU_mode;
    QString QU_UVstart;
    QString QU_UVstop;
    QString QU_OVstart;
    QString QU_OVstop;
    QString QU_Plockin;
    QString QU_PlockOut;
    int tao;
    int certification_En;
};

struct Grid
{
    int Ver_old;
    QString CID;
    double uOV1;
    float tOV1;
    float uUV1;
    float tUV1;
    float uOF1;
    float tOF1;
    float uUF1;
    float tUF1;
    float uOV2;
    float tOV2;
    float uUV2;
    float tUV2;
    float uOF2;
    float tOF2;
    float uUF2;
    float tUF2;
    int GT;
    float URov;
    float URuv;
    float FRof;
    float FRuf;
    int superPF;
    int ASPQU;
    int CEIDFU;
    int Var;
    float HVRT;
    float LVRT;
    int RatedFreq;
    float t_RatedFreq;
};

struct Cer
{
    QString CID;
    int Fixed_non_P;
    float Fixed_non_P_Para;
    int Max_non_P;
    int Remote_P_slope;
    float Remote_P_slopePara;
    float Reconnect_P_slope;
    int OverVol_10;
    float OverVol_10_Para;
    int UF_hyst;
    int UF_hyst_powerOn;
    int LFSM_Mode;
    float LFSMO_fact;
    float LFSMO_fdeact;
    float LFSMO_Droop;
    int LFSMO_Trec;
    float LFSMO_P_slope;
    int LFSMO_Pn;  //0 OFF,1按Pn降额
    float LFSMU_fact;
    float LFSMU_fdeact;
    float LFSMU_Droop;
    int Island;
    int DF1;
    int DF2;
    int FVRT;
    int ratedVol;
    int PU_mode;
    float PU_InitialVol;
    float PU_EndVol;
    float PU_Droop;
    float PU_DroopSpd;
    int QU_mode;
    float QU_UVstart;
    float QU_UVstop;
    float QU_OVstart;
    float QU_OVstop;
    float QU_Plockin;
    float QU_PlockOut;
    int tao;
    int certification_En;

    int SWH_Tao;
    int SWH_MaxPF;

};



class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


    void log_sendData(const QString data);
    void log_green(const QString msg);
    void log_red(const QString msg);
    void limitTextLines();



public slots:
    void log_receiveData(QString data);

    void log_receiveData1(QHash <QString, QString> data);
    //设置CID
    void slot_setCID(QStringList CID, QString EMUCID, QString STATION);

    //接收COP,发送接收应答
    void slot_receiveCOP(QHash<QString, QString> Re_COP);

    //接收MaxOP,发送接收应答
    void slot_receiveMaxOP(QHash<QString, QString> Re_MaxOP);

    //接收Grid,发送接收应答
    void slot_receiveGrid(QHash<QString, QString> Re_Grid);

    //接收Cer,发送接收应答
    void slot_receiveCer(QHash<QString, QString> Re_Cer);


    void slot_fileSave(QString fileName);
    void slot_openFile();

    void slot_set_maxop_read_back_flag(QString old_status,QString status);
    void slot_set_cop_read_back_flag(QString old_status,QString status);
    void slot_set_grid_read_back_flag(QString old_status,QString status);
    void slot_set_cer_read_back_flag(QString old_status,QString status);
    void slot_set_r_maxop_read_back_flag(QString old_status,QString status);
    void slot_set_r_cop_read_back_flag(QString old_status,QString status);
    void slot_set_r_grid_read_back_flag(QString old_status,QString status);
    void slot_set_r_cer_read_back_flag(QString old_status,QString status);

    void onm_timer_callback();
signals:
    //设置COP
    void signal_COP_set(QJsonObject Js_COP_set);
    //读取COP
    void signal_COP_read(QJsonObject Js_COP_read);
    //发送读取COP的应答
    void signal_COP_Ack(QString COP_Ack);

    //设置MaxOP
    void signal_MaxOP_set(QJsonObject Js_MaxOP_set);
    //读取MaxOP
    void signal_MaxOP_read(QJsonObject Js_MaxOP_read);
    //发送读取MaxOP的应答
    void signal_MaxOP_Ack(QString MaxOP_Ack);

    //设置Grid
    void signal_Grid_set(QJsonObject Js_Grid_set);
    //读取Grid
    void signal_Grid_read(QJsonObject Js_Grid_read);
    //发送读取Grid的应答
    void signal_Grid_Ack(QString Grid_Ack);

    void signal_select_back(QJsonObject js);

    //设置Cer
    void signal_Cer_set(QJsonObject Js_Cer_set);
    //读取Cer
    void signal_Cer_read(QJsonObject Js_Cer_read);
    //发送读取Cer的应答
    void signal_Cer_Ack(QString Cer_Ack);


    void signal_sendToDialog(str_Grid *s_str_Grid, str_Cer *s_str_Cer);
    void signal_sendFilePath(QString filePaht);

private slots:

    //发送读取MaxOP的服务器命令
    void on_pushButton_MaxOP_read_clicked();
    //发送设置MaxOP的服务器命令
    void on_pushButton_MaxOP_set_clicked();
    //发送设置COP的服务器命令
    void on_pushButton_COP_set_clicked();
    //发送读取COP的服务器命令
    void on_pushButton_COP_read_clicked();
    //发送设置Grid的服务器命令
    void on_pushButton_GridSet_clicked();
    //发送读取Grid的服务器命令
    void on_pushButton_GridRead_clicked();
    //发送读取Cer的服务器命令
    void on_pushButton_CerRead_clicked();
    //发送设置Cer的服务器命令
    void on_pushButton_CerSet_clicked();

    //文件增加
    void on_pushButton_add_clicked();
    //文件修改
    void on_pushButton_update_clicked();
    //文件删除
    void on_pushButton_delete_clicked();

    void on_comboBox_program_textActivated(const QString &arg1);

    void on_comboBox_program_currentTextChanged(const QString &arg1);

    void on_comboBox_CID_currentTextChanged(const QString &arg1);

    void on_checkBox_all_stateChanged(int arg1);

private:

    Ui::Dialog *ui;

    void getGrid();
    void getCer();

    void Re_getGridNum(QString Grid);
    void Re_getCerNum(QString Cer);

    float Dec(float value, int decimalDigits);

    void readGridToStr();
    void readCerToStr();
    void displayGrid(str_Grid *Grid);
    void displayCer(str_Cer *Cer);
    void sacnDataFile();
    void getFilePath();
    void readJsonDoc(QString fileName);
    void creatJsonFile(str_Grid *s_str_Grid, str_Cer *s_str_Cer, QString filePath);

    void creat_item_checkBox(int row, QString name);        //在tablewidget指定行创建checkBox
    void set_item_checked(bool checked, int row);           //设置tablewidget指定行的checkBox状态为checked
    void get_CID_list();                                    //获取被勾选的CID


    int appendTimes;
    str_Grid s_str_Grid;
    str_Cer s_str_Cer;

    QString data_filePath;
    QStringList nameList;
    str_Grid save_Grid;
    str_Cer save_Cer;
    QJsonObject Json_para;

    Grid s_Grid;
    Grid s_Re_Grid;
    Cer s_Cer;
    Cer s_Re_Cer;
    QStringList MICID_List;
    QStringList MICID_list_checked;
    QString Current_MICID;
    QString emu_CID;
    QString station;

    QTimer m_timer;

    QStringList m_mi_r_MaxOP;
    QString r_MaxOP_ctl_time;   //最新一次控制时间  用于定时查询数据 查询成功后清空
    QStringList m_mi_r_COP;
    QString r_COP_ctl_time;
    QStringList m_mi_r_Grid;
    QString r_Grid_ctl_time;
    QStringList m_mi_r_Cer;
    QString r_Cer_ctl_time;

    QStringList m_mi_w_MaxOP;
    QString MaxOP_ctl_time;   //最新一次控制时间  用于定时查询数据 查询成功后清空
    QStringList m_mi_w_COP;
    QString COP_ctl_time;
    QStringList m_mi_w_Grid;
    QString Grid_ctl_time;
    QStringList m_mi_w_Cer;
    QString Cer_ctl_time;



    QByteArray Hex_MaxOP;
    QByteArray Hex_COP;
    QByteArray Hex_Grid;
    QByteArray Hex_Cer;
    QHash<QString, QString> save_Re_COP;
    QHash<QString, QString> save_Re_MaxOP;
    QHash<QString, QString> save_Re_Grid;
    QHash<QString, QString> save_Re_Cer;
};

#endif // DIALOG_H
