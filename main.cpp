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

void OpptimizerUtils::refreshStatus()
{
    QProcess p;
    QString strOutput;
    QString strError;
    p.start("cat /proc/opptimizer");
    p.waitForFinished(-1);
    strOutput = p.readAllStandardOutput();
    strError = p.readAllStandardError();
    qDebug() << strOutput;
    qDebug() << strError;
    if (strError.length() > 1)
        lastOPPtimizerStatus = "ERROR";
    else
        lastOPPtimizerStatus = strOutput;

    QProcess p2;
    QString strOutput2;
    QString strError2;
    p2.start("cat /sys/power/sr_vdd1_autocomp");
    p2.waitForFinished(-1);
    strOutput2 = p2.readAllStandardOutput();
    strError2 = p2.readAllStandardError();
    qDebug() << strOutput2;
    qDebug() << strError2;
    if (strError2.length() > 1)
        lastSmartReflexStatus = "ERROR";
    else
        lastSmartReflexStatus = strOutput2;
}

QString OpptimizerUtils::getModuleVersion()
{
    if(lastOPPtimizerStatus == "ERROR")
        return "ERR";

    QRegExp rx("\\Wv(\\d+\\.\\d+)");
    int pos = rx.indexIn(lastOPPtimizerStatus);
    if (pos > -1) {
        return rx.cap(1);
    }
    else
        return "Unknown";
}

QString OpptimizerUtils::getMaxVoltage()
{
    if(lastOPPtimizerStatus == "ERROR")
        return "ERR";

    QRegExp rx("u_volt_dyn_nominal:\\s+(\\d+)");
    int pos = rx.indexIn(lastOPPtimizerStatus);
    if (pos > -1) {
        return rx.cap(1);
    }
    else
        return "Unknown";
}

QString OpptimizerUtils::getSmartReflexStatus()
{
    if(lastSmartReflexStatus == "ERROR")
        return "ERR";
    if (lastSmartReflexStatus.left(1) == "1")
        return "On";
    if (lastSmartReflexStatus.left(1) == "0")
        return "Off";
    return "Unknown";
}

QString OpptimizerUtils::getMaxFreq()
{
    if(lastOPPtimizerStatus == "ERROR")
        return "ERR";

    QRegExp rx("opp rate:\\s+(\\d\\d\\d\\d)");
    int pos = rx.indexIn(lastOPPtimizerStatus);
    if (pos > -1) {
        return QString::number(rx.cap(1).toInt());
    }
    else
        return "Unknown";
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
    viewer.showFullScreen();

    return app->exec();
}
