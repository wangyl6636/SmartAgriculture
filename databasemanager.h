#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QVariantList>

class DataBaseManager
{
public:
    DataBaseManager();
    ~DataBaseManager();

    bool InitDataBase();
    bool IsOpen() const; // 检查数据库是否打开

    // 用户相关
    bool AddUser(const QString& name, const QString& phone, const QString& password, const QString& role);
    bool UpdateUser(int userId, const QString& name, const QString& phone, const QString& password, const QString& role);
    bool DeleteUser(int userId);
    bool CheckUserLogin(const QString& phone, const QString& password, QString& role);
    QVariantList GetUserInfo(int userId);
    QVariantList GetAllUsers();

    // 作物区相关
    bool AddCropArea(int farmerId, const QString& cropType, float area, const QString& location, const QString& detail);
    bool UpdateCropArea(int cropAreaId, const QString& cropType, float area, const QString& location, const QString& detail);
    bool DeleteCropArea(int cropAreaId);
    QVariantList GetCropAreas(int farmerId);
    QVariantList GetAllCropAreas();

    // 建议相关
    bool AddSystemAdvice(int sensorId, int cropAreaId, const QString& fertilizerAdvice, const QString& irrigationAdvice);
    bool UpdateSystemAdvice(int adviceId, const QString& fertilizerAdvice, const QString& irrigationAdvice);
    bool DeleteSystemAdvice(int adviceId);
    QVariantList GetSystemAdvices(int cropAreaId);
    QVariantList GetAllSystemAdvices();

    // 专家建议相关
    bool AddExpertAdvice(int expertId, int cropAreaId, const QString& content);
    bool UpdateExpertAdvice(int adviceId, const QString& content);
    bool DeleteExpertAdvice(int adviceId);
    QVariantList GetExpertAdvices(int cropAreaId);
    QVariantList GetAllExpertAdvices();

    // 模型优化建议相关
    bool AddModelOptimization(int systemAdviceId, int farmerId, int expertId, const QString& content);
    bool UpdateModelOptimization(int optimizationId, const QString& content);
    bool DeleteModelOptimization(int optimizationId);
    QVariantList GetModelOptimizations(int systemAdviceId);
    QVariantList GetAllModelOptimizations();

    // 单例获取接口
    static DataBaseManager& instance();

    void TestPrintAllSensors();

private:
    QSqlDatabase db;

    // 单例相关
    DataBaseManager(const DataBaseManager&) = delete;
    DataBaseManager& operator=(const DataBaseManager&) = delete;
};

#endif // DATABASEMANAGER_H
