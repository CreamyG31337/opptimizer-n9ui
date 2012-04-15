#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "main.h"

MySettings::MySettings():
    qsettInternal(new QSettings("/home/user/.config/FakeCompany/OPPtimizer.conf",QSettings::NativeFormat,this))
{
}
MySettings::~MySettings()
{
}

QString OpptimizerUtils::isModuleInstalled()
{
    QProcess p;
    QString output;
    //needs root :(
    //p.start("/sbin/status apps/proximus-daemon");
    p.start("lsmod | grep opptimizer");
    p.waitForFinished(-1);
    output = p.readAllStandardOutput();
    qDebug() << output;
    qDebug() << "e:" + p.readAllStandardError();
    if (output.length() > 1)
        return "daemon appears to be running as pid " + output;
    else
        return "error - cannot find pid of daemon! May be normal if you just started the device.";
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("FakeCompany");
    QCoreApplication::setOrganizationDomain("appcheck.net");
    QCoreApplication::setApplicationName("OPPtimizer");

    MySettings objSettings;
    OpptimizerUtils objOpptimizerUtils;

    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("objQSettings",&objSettings);
    viewer.rootContext()->setContextProperty("objOpptimizerUtils",&objOpptimizerUtils);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/opptimizern9ui/main.qml"));
    //viewer.showExpanded();
    viewer.showFullScreen();

    return app->exec();
}
