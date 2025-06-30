#include "databasemanager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QElapsedTimer>

DataBaseManager::DataBaseManager() {}

DataBaseManager::~DataBaseManager() {
    if (db.isOpen()) db.close();
}

bool DataBaseManager::InitDataBase() {
    if (QSqlDatabase::contains("smartagri_connection")) {
        db = QSqlDatabase::database("smartagri_connection");
    } else {
        db = QSqlDatabase::addDatabase("QODBC", "smartagri_connection");
        QString dsn = QString("DRIVER=MySQL ODBC 9.3 Unicode Driver;SERVER=rm-2ze58122pu228651soo.mysql.rds.aliyuncs.com;DATABASE=SAdb;USER=dashuai;PASSWORD=DaShuai123456;OPTION=3;");
        db.setDatabaseName(dsn);
    }
    if (db.open()) {
        qDebug("successful connect!");
        return true;
    } else {
        qDebug("connect failed!");
        return false;
    }
}

bool DataBaseManager::IsOpen() const {
    qDebug("检查数据库连接");
    return db.isOpen();
}

// 用户相关
int DataBaseManager::AddUser(const QString& name, const QString& phone, const QString& password, const QString& role, QString* errorOut) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (name, phone, passwd, role) VALUES (:name, :phone, :passwd, :role)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":passwd", password);
    query.bindValue(":role", role);
    bool ok = query.exec();
    if (!ok && errorOut) {
        *errorOut = query.lastError().text();
        return -1;
    }else{
        return query.lastInsertId().toInt();
    }
}
// 兼容原有接口
int DataBaseManager::AddUser(const QString& name, const QString& phone, const QString& password, const QString& role) {
    return AddUser(name,phone,password,role,nullptr);
}

bool DataBaseManager::UpdateUser(int userId, const QString& name, const QString& phone, const QString& password, const QString& role) {
    QSqlQuery query(db);
    query.prepare("UPDATE users SET name=:name, phone=:phone, passwd=:passwd, role=:role WHERE id=:id");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":passwd", password);
    query.bindValue(":role", role);
    query.bindValue(":id", userId);
    return query.exec();
}

bool DataBaseManager::DeleteUser(int userId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM users WHERE id=:id");
    query.bindValue(":id", userId);
    return query.exec();
}

bool DataBaseManager::CheckUserLogin(const QString& name, const QString& phone, const QString& password, QString& role) {
    QSqlQuery query(db);
    query.prepare("SELECT role FROM users WHERE name=:name AND phone=:phone AND passwd=:passwd");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":passwd", password);
    if (query.exec() && query.next()) {
        role = query.value(0).toString();
        return true;
    }
    return false;
}

bool DataBaseManager::IsUserExists(const QString& phone){
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE phone=:phone");
    query.bindValue(":phone", phone);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

QVariantList DataBaseManager::GetUserInfo(int userId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE id=:id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        for (int i = 0; i < query.record().count(); ++i)
            result << query.value(i);
    }
    return result;
}

QVariantList DataBaseManager::GetAllUsers() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users");
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

int DataBaseManager::GetUserIdByPhone(const QString& phone) {
    QSqlQuery query(db);
    query.prepare("SELECT id FROM users WHERE phone=:phone");
    query.bindValue(":phone", phone);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();  // 返回对应的 userId
    }
    return -1;  // 如果没有找到该电话号码的用户，返回 -1
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
// 添加专家建议
bool DataBaseManager::AddExpertAdvice(int expertId, int cropAreaId, const QString& title, const QString& content, const QString& category) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO expert_advice (expert_id, crop_area_id, title, content, category) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(expertId);
    query.addBindValue(cropAreaId);
    query.addBindValue(title);
    query.addBindValue(content);
    query.addBindValue(category);
    return query.exec();
}

// 更新专家建议
bool DataBaseManager::UpdateExpertAdvice(int adviceId, const QString& title, const QString& content, const QString& category) {
    QSqlQuery query(db);
    query.prepare("UPDATE expert_advice SET title=?, content=?, category=? WHERE id=?");
    query.addBindValue(title);
    query.addBindValue(content);
    query.addBindValue(category);
    query.addBindValue(adviceId);
    return query.exec();
}

// 删除专家建议
bool DataBaseManager::DeleteExpertAdvice(int adviceId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM expert_advice WHERE id=?");
    query.addBindValue(adviceId);
    return query.exec();
}

// 获取特定种植区域的专家建议
QVariantList DataBaseManager::GetExpertAdvices(int cropAreaId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare(
        "SELECT ea.id, ea.title, ea.content, ea.category, ea.created_at, u.name AS expert_name "
        "FROM expert_advice ea "
        "JOIN expert e ON ea.expert_id = e.id "
        "JOIN users u ON e.user_id = u.id "  // 通过用户表获取专家姓名
        "WHERE ea.crop_area_id = ? "
        "ORDER BY ea.created_at DESC"
        );
    query.addBindValue(cropAreaId);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap advice;
            advice["id"] = query.value("id");
            advice["title"] = query.value("title");
            advice["content"] = query.value("content");
            advice["category"] = query.value("category");
            advice["created_at"] = query.value("created_at");
            advice["expert_name"] = query.value("expert_name");
            result.append(advice);
        }
    } else {
        qWarning() << "GetExpertAdvices error:" << query.lastError().text();
    }
    return result;
}

// 获取当前农户的所有专家建议
QVariantList DataBaseManager::GetFarmerExpertAdvices(int farmerId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare(
        "SELECT ea.id, ea.title, ea.content, ea.category, ea.created_at, u.name AS expert_name, "
        "       ca.crop_type, ca.location AS crop_location "
        "FROM expert_advice ea "
        "JOIN expert e ON ea.expert_id = e.id "
        "JOIN users u ON e.user_id = u.id "  // 通过用户表获取专家姓名
        "JOIN crop_area ca ON ea.crop_area_id = ca.id "
        "JOIN farmer f ON ca.farmer_id = f.id "
        "WHERE f.id = ? "  // 通过农户ID过滤
        "ORDER BY ea.created_at DESC"
        );
    query.addBindValue(farmerId);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap advice;
            advice["id"] = query.value("id");
            advice["title"] = query.value("title");
            advice["content"] = query.value("content");
            advice["category"] = query.value("category");
            advice["created_at"] = query.value("created_at");
            advice["expert_name"] = query.value("expert_name");
            advice["crop_type"] = query.value("crop_type");
            advice["crop_location"] = query.value("crop_location");
            result.append(advice);
        }
    } else {
        qWarning() << "GetFarmerExpertAdvices error:" << query.lastError().text();
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

//测试函数
// void DataBaseManager::TestPrintAllSensors() {
//     QSqlQuery query(db);
//     if (!query.exec("SELECT * FROM sensor")) {
//         qDebug() << "查询传感器数据失败:" << query.lastError().text();
//         return;
//     }
//     while (query.next()) {
//         QStringList row;
//         for (int i = 0; i < query.record().count(); ++i) {
//             row << query.record().fieldName(i) + "=" + query.value(i).toString();
//         }
//         qDebug() << row.join(", ");
//     }
// }

QVariantList DataBaseManager::GetSensorInfo(int sensorId) {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT id, resource, event, content, event_time, receive_time FROM sensor WHERE id=:id");
    query.bindValue(":id", sensorId);
    if (query.exec() && query.next()) {
        for (int i = 0; i < query.record().count(); ++i) {
            // content字段直接返回字符串，交由上层解析JSON
            result << query.value(i);
        }
    }
    return result;
}

QVariantList DataBaseManager::GetAllSensors() {
    QVariantList result;
    QSqlQuery query(db);
    query.prepare("SELECT id, resource, event, content, event_time, receive_time FROM sensor");
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


//农户相关
int DataBaseManager::AddFarmerUser(const int userId) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO farmer (user_id) VALUES (:userId)");
    query.bindValue(":userId", userId);

    if(query.exec()){
        return query.lastInsertId().toInt();
    } else {
        return -1;
    }
}

bool DataBaseManager::DeleteFarmerUser(const int farmerId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM farmer WHERE id=:farmerId");
    query.bindValue(":farmerId", farmerId);

    bool success = query.exec();
    return success;  // 返回是否删除成功
}

int DataBaseManager::GetFarmerId(const int userId) {
    QSqlQuery query(db);
    query.prepare("SELECT id FROM farmer WHERE user_id=:userId");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next()) {
        int farmerId = query.value(0).toInt();
        return farmerId;  // 返回对应的 farmerId
    }
    return -1;  // 如果没有找到农户信息，返回 -1
}

//专家相关
bool DataBaseManager::AddExpertUser(const int userId, const QString& field) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO expert (user_id, field) VALUES (:userId, :field)");
    query.bindValue(":userId", userId);
    query.bindValue(":field", field);

    return query.exec();
}

// 删除指定的专家用户
bool DataBaseManager::DeleteExpertUser(const int expertId) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM expert WHERE id=:expertId");
    query.bindValue(":expertId", expertId);

    bool success = query.exec();
    return success;  // 返回是否删除成功
}

// 根据 userId 获取对应的 expertId
int DataBaseManager::GetExpertId(const int userId) {
    QSqlQuery query(db);
    query.prepare("SELECT id FROM expert WHERE user_id=:userId");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();  // 返回对应的 expertId
    }
    return -1;  // 如果没有找到专家信息，返回 -1
}

QString DataBaseManager::GetLastError() const {
    QSqlQuery query(db);
    if (query.lastError().isValid()) { 
        return query.lastError().text();
    }
    return QString();  // 如果没有错误，返回空字符串
}

bool DataBaseManager::BeginTransaction() {
    return db.transaction();
}

bool DataBaseManager::CommitTransaction() {
    return db.commit();
}

bool DataBaseManager::RollbackTransaction() {
    return db.rollback();
}

bool DataBaseManager::TestConnection() {
    QSqlQuery testQuery(db);
    testQuery.prepare("SELECT 1"); // 执行简单查询测试连接

    QElapsedTimer timer;
    timer.start();

    if (!testQuery.exec()) {
        return false; // 查询失败，连接不可用
    }

    // 检查查询响应时间，避免长时间卡顿
    if (timer.elapsed() > 1000) { // 2秒超时
        return false;
    }

    return testQuery.next() && testQuery.value(0).toInt() == 1;
}
