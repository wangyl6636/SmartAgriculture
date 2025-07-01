#ifndef SYSTEMADVICEFORM_H
#define SYSTEMADVICEFORM_H

#include <QWidget>

namespace Ui {
class SystemAdviceForm;
}

class SystemAdviceForm : public QWidget
{
    Q_OBJECT

public:
    explicit SystemAdviceForm(int id, int roleIndex, QWidget *parent = nullptr);
    ~SystemAdviceForm();

signals:
    void closeSignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onSubmitButtonClicked();

private:
    int id;
    int roleIndex;//0是农户，1是专家
    Ui::SystemAdviceForm *ui;
};

#endif // SYSTEMADVICEFORM_H
