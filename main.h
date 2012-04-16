#ifndef MAIN_H
#define MAIN_H

#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative>
#include <MDeclarativeCache>
#include <QtCore/QSettings>
#include <QtDeclarative/QDeclarativeContext>
#include <QtCore/QCoreApplication>
#include <QtCore/QtGlobal>
#include <QtCore/QStringList>
#include <QtCore/QObject>
#include <QtCore/QAbstractListModel>
#include <QtCore/QScopedPointer>
#include <QProcess>
#include <QDebug>
#include <QSharedPointer>
#include <QtAlgorithms>
#include <QStack>
#include <QMap>
#include <QFile>


class OpptimizerUtils : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE QString getModuleVersion();
    Q_INVOKABLE QString getMaxVoltage();
    Q_INVOKABLE QString getSmartReflexStatus();
    Q_INVOKABLE QString getMaxFreq();
    Q_INVOKABLE void refreshStatus();
    Q_INVOKABLE void applySettings(int reqFreq, int reqVolt, bool SREnable, bool changeVolt);
private:
    QString lastOPPtimizerStatus;
    QString lastSmartReflexStatus;
};

//annoying wrapper class for qsettings
class MySettings : public QObject
{
    Q_OBJECT
public:
    explicit MySettings();
    virtual ~MySettings();
    Q_INVOKABLE QVariant getValue(QString keyval,QVariant defaultval){
        return qsettInternal->value(keyval,defaultval);
    }
    Q_INVOKABLE void setValue(QString key,QVariant value){
        qsettInternal->setValue(key,value);
    }
    Q_INVOKABLE void beginGroup(QString prefix){
        qsettInternal->beginGroup(prefix);
    }
    Q_INVOKABLE void endGroup(){
        qsettInternal->endGroup();
    }
    Q_INVOKABLE bool contains(QString key){
        return qsettInternal->contains(key);
    }
    Q_INVOKABLE QStringList childGroups(){
        return qsettInternal->childGroups();
    }
    Q_INVOKABLE QString group(){
        return qsettInternal->group();
    }
    Q_INVOKABLE void remove(QString key){
        qsettInternal->remove(key);
    }
    Q_INVOKABLE QString fileName(){
        return qsettInternal->fileName();
    }
    Q_INVOKABLE void clear(){
        qsettInternal->clear();
    }
private:
    QSettings *qsettInternal;
};


#endif // MAIN_H
