#include "databasemanager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QString>

DataBaseManager::DataBaseManager() {
    InitDataBase();
}

DataBaseManager::~DataBaseManager() {
    if (db.isOpen()) db.close();
}

bool DataBaseManager::InitDataBase() {
    QString dsn = QString("DRIVER=MySQL ODBC 9.3 Unicode Driver;SERVER=rm-2ze58122pu228651soo.mysql.rds.aliyuncs.com;DATABASE=SAdb;USER=dashuai;PASSWORD=DaShuai123456;OPTION=3;");
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(dsn);
    if (db.open()) {
        qDebug("successful connect!");
        return true;
    } else {
        qDebug("connect failed!");
        return false;
    }
}

bool DataBaseManager::IsOpen() const {
    return db.isOpen();
}

// 用户相关
bool DataBaseManager::AddUser(const QString& name, const QString& phone, const QString& password, const QString& role) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO user (name, phone, password, role) VALUES (?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(password);
    query.addBindValue(role);
    return query.exec();
}

bool DataBaseManager::UpdateUser(int userId, const QString& name, const QString& phone, const QString& password, const QString& role) {
    QSqlQuery query(db);
    query.prepare("UPDATE user SET name=?, phone=?, password=?, role=? WHERE id=?");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(password);
    query.addBindValue(role);
    query.addBindValue(userId);
    return query.exec();
}

bool DataBaseManager::DeleteUser(int userId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM user WHERE id=?");
    query.addBindValue(userId);
    return query.exec();
}

bool DataBaseManager::CheckUserLogin(const QString& phone, const QString& password, QString& role) {
    QSqlQuery query(db);
    query.prepare("SELECT role FROM user WHERE phone=? AND password=?");
    query.addBindValue(phone);
    query.addBindValue(password);
    if (query.exec() && query.next()) {
        role = query.value(0).toString();
        return true;
    }
    return false;
}

QVariantList DataBaseManager::GetUserInfo(int userId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user WHERE id=?");
    query.addBindValue(userId);
    if (query.exec() && query.next()) {
        for (int i = 0; i < query.record().count(); ++i)
            result << query.value(i);
    }
    return result;
}

QVariantList DataBaseManager::GetAllUsers() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user");
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

// 作物区相关
bool DataBaseManager::AddCropArea(int farmerId, const QString& cropType, float area, const QString& location, const QString& detail) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO crop_area (farmer_id, crop_type, area, location, detail) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(farmerId);
    query.addBindValue(cropType);
    query.addBindValue(area);
    query.addBindValue(location);
    query.addBindValue(detail);
    return query.exec();
}

bool DataBaseManager::UpdateCropArea(int cropAreaId, const QString& cropType, float area, const QString& location, const QString& detail) {
    QSqlQuery query(db);
    query.prepare("UPDATE crop_area SET crop_type=?, area=?, location=?, detail=? WHERE id=?");
    query.addBindValue(cropType);
    query.addBindValue(area);
    query.addBindValue(location);
    query.addBindValue(detail);
    query.addBindValue(cropAreaId);
    return query.exec();
}

bool DataBaseManager::DeleteCropArea(int cropAreaId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM crop_area WHERE id=?");
    query.addBindValue(cropAreaId);
    return query.exec();
}

QVariantList DataBaseManager::GetCropAreas(int farmerId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM crop_area WHERE farmer_id=?");
    query.addBindValue(farmerId);
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

QVariantList DataBaseManager::GetAllCropAreas() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM crop_area");
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

// 系统建议相关
bool DataBaseManager::AddSystemAdvice(int sensorId, int cropAreaId, const QString& fertilizerAdvice, const QString& irrigationAdvice) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO system_advice (sensor_id, crop_area_id, fertilizer_advice, irrigation_advice) VALUES (?, ?, ?, ?)");
    query.addBindValue(sensorId);
    query.addBindValue(cropAreaId);
    query.addBindValue(fertilizerAdvice);
    query.addBindValue(irrigationAdvice);
    return query.exec();
}

bool DataBaseManager::UpdateSystemAdvice(int adviceId, const QString& fertilizerAdvice, const QString& irrigationAdvice) {
    QSqlQuery query(db);
    query.prepare("UPDATE system_advice SET fertilizer_advice=?, irrigation_advice=? WHERE id=?");
    query.addBindValue(fertilizerAdvice);
    query.addBindValue(irrigationAdvice);
    query.addBindValue(adviceId);
    return query.exec();
}

bool DataBaseManager::DeleteSystemAdvice(int adviceId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM system_advice WHERE id=?");
    query.addBindValue(adviceId);
    return query.exec();
}

QVariantList DataBaseManager::GetSystemAdvices(int cropAreaId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM system_advice WHERE crop_area_id=?");
    query.addBindValue(cropAreaId);
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

QVariantList DataBaseManager::GetAllSystemAdvices() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM system_advice");
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

// 专家建议相关
bool DataBaseManager::AddExpertAdvice(int expertId, int cropAreaId, const QString& content) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO expert_advice (expert_id, crop_area_id, content) VALUES (?, ?, ?)");
    query.addBindValue(expertId);
    query.addBindValue(cropAreaId);
    query.addBindValue(content);
    return query.exec();
}

bool DataBaseManager::UpdateExpertAdvice(int adviceId, const QString& content) {
    QSqlQuery query(db);
    query.prepare("UPDATE expert_advice SET content=? WHERE id=?");
    query.addBindValue(content);
    query.addBindValue(adviceId);
    return query.exec();
}

bool DataBaseManager::DeleteExpertAdvice(int adviceId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM expert_advice WHERE id=?");
    query.addBindValue(adviceId);
    return query.exec();
}

QVariantList DataBaseManager::GetExpertAdvices(int cropAreaId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM expert_advice WHERE crop_area_id=?");
    query.addBindValue(cropAreaId);
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

QVariantList DataBaseManager::GetAllExpertAdvices() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM expert_advice");
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

// 模型优化建议相关
bool DataBaseManager::AddModelOptimization(int systemAdviceId, int farmerId, int expertId, const QString& content) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO model_optimization (system_advice_id, farmer_id, expert_id, content) VALUES (?, ?, ?, ?)");
    query.addBindValue(systemAdviceId);
    query.addBindValue(farmerId);
    query.addBindValue(expertId);
    query.addBindValue(content);
    return query.exec();
}

bool DataBaseManager::UpdateModelOptimization(int optimizationId, const QString& content) {
    QSqlQuery query(db);
    query.prepare("UPDATE model_optimization SET content=? WHERE id=?");
    query.addBindValue(content);
    query.addBindValue(optimizationId);
    return query.exec();
}

bool DataBaseManager::DeleteModelOptimization(int optimizationId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM model_optimization WHERE id=?");
    query.addBindValue(optimizationId);
    return query.exec();
}

QVariantList DataBaseManager::GetModelOptimizations(int systemAdviceId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM model_optimization WHERE system_advice_id=?");
    query.addBindValue(systemAdviceId);
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

QVariantList DataBaseManager::GetAllModelOptimizations() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM model_optimization");
    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            for (int i = 0; i < query.record().count(); ++i)
                row << query.value(i);
            result << QVariant(row);
        }
    }
    return result;
}

// 单例实现
DataBaseManager& DataBaseManager::instance() {
    static DataBaseManager instance;
    return instance;
}

void DataBaseManager::TestPrintAllSensors() {
    QSqlQuery query(db);
    if (!query.exec("SELECT * FROM sensor")) {
        qDebug() << "查询传感器数据失败:" << query.lastError().text();
        return;
    }
    while (query.next()) {
        QStringList row;
        for (int i = 0; i < query.record().count(); ++i) {
            row << query.record().fieldName(i) + "=" + query.value(i).toString();
        }
        qDebug() << row.join(", ");
    }
}
