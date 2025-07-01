#ifndef EXPERTADVICEFORM_H
#define EXPERTADVICEFORM_H

#include <QWidget>

namespace Ui {
class ExpertAdviceForm;
}

class ExpertAdviceForm : public QWidget
{
    Q_OBJECT

public:
    explicit ExpertAdviceForm(int expertId, int cropAreaId, QWidget *parent = nullptr);
    ~ExpertAdviceForm();

private:
    int expertId;
    int cropAreaId;
    Ui::ExpertAdviceForm *ui;

    void closeEvent(QCloseEvent *event);

    void loadAdviceList();
    void clearAdviceList();
    void addAdviceCard(const QVariantList &adviceInfo);

signals:
    void closeSignal();
private slots:
    void on_addAdviceButton_clicked();
};

#endif // EXPERTADVICEFORM_H
