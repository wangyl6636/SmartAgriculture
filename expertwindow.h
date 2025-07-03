#ifndef EXPERTWINDOW_H
#define EXPERTWINDOW_H

#include "changeinfowindow.h"
#include "expertadviceform.h"
#include "systemadviceform.h"
#include "systemwindow.h"

#include <QMainWindow>

namespace Ui {
class ExpertWindow;
}

class ExpertWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExpertWindow(int expertId, QWidget *parent = nullptr);
    ~ExpertWindow();

private slots:
    void on_updateInfoButton_clicked();
    void on_suggestButton_clicked();
    void ReShow();

private:
    int expertId;
    Ui::ExpertWindow *ui;

    ChangeInfoWindow *changeInfoWindow;
    ExpertAdviceForm *expertAdviceForm;
    SystemAdviceForm *systemAdviceForm;
    SystemWindow *sysWin;
    // 动态加载作物区相关
    void loadCropAreas();
    void clearCropAreas();
    void addCropCard(const QVariantList &areaInfo, const QString &farmerPhone);
};

#endif // EXPERTWINDOW_H
