#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QProcess>
#include <QFile>
#include <QDir>
//#include "cs_client.h"
#include "user_login_dlg.h"
#include "bridge.h"

#include "common.h"
#define VERSION "软件版本2.20"

QString exe_path = "";
QString config_path = "";

void relogin(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qRegisterMetaType<QJsonObject>("QJsonObject");
    qRegisterMetaType<QMap<QString,station *>>("QHash<QString,station *>");


    bridge::ins()->start();

    // 登录界面控制
    user_login_dlg tmp_login_dlg;
    tmp_login_dlg.get_user_login_history(QDir(a.applicationDirPath()).filePath("./config/user_config.json"));
    if(tmp_login_dlg.exec() == QDialog::Accepted)
    {
        MainWindow w;

        //登录成功
        w.showMaximized();

        w.setWindowTitle("BYDAS" + bridge::ins()->csclient()->analysis_server() + VERSION);
        a.setStyle(QStyleFactory::create("Fusion"));

        //保存exe的文件路径
        exe_path = QCoreApplication::applicationFilePath();

        w.show();
        int ret = a.exec();
        //重登录
        if(ret == 2)
        {
            atexit(relogin);
        }

        return  ret;
    }

    return 0;
}
//重启应用程序
void relogin()
{
    QProcess process;
    process.startDetached(exe_path);
}


