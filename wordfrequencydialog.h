#ifndef WORDFREQUENCYDIALOG_H
#define WORDFREQUENCYDIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class wordfrequencydialog;
}

class wordfrequencydialog : public QDialog {
    Q_OBJECT

public:
    explicit wordfrequencydialog(const QMap<QString, int>& wordFreq, QWidget *parent = nullptr);
    ~wordfrequencydialog();

private:
    Ui::wordfrequencydialog *ui;
};

#endif // WORDFREQUENCYDIALOG_H
