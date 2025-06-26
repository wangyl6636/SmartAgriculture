#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

class DataBaseManager
{
public:
    DataBaseManager();

private:
    bool isconnect;

    //初始化数据
    bool InitDataBase();
};

#endif // DATABASEMANAGER_H
