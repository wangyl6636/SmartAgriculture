#include "databasemanager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QString>
DataBaseManager::DataBaseManager() {
    InitDataBase();
}

bool DataBaseManager::InitDataBase(){
    QString dsn = QString("DRIVER=MySQL ODBC 9.3 Unicode Driver;SERVER=rm-2ze58122pu228651soo.mysql.rds.aliyuncs.com;DATABASE=SAdb;USER=dashuai;PASSWORD=DaShuai123456;OPTION=3;");

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName(dsn);
    if(db.open()){
        qDebug("successful connect!");
        return true;
    }else{
        qDebug("connect failed!");
        return false;
    }
}
