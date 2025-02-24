#include "wordfrequencydialog.h"
#include "ui_wordfrequencydialog.h"

#include <QStringList>

wordfrequencydialog::wordfrequencydialog(const QMap<QString, int>& wordFreq, QWidget *parent)
    : QDialog(parent), ui(new Ui::wordfrequencydialog) {
    ui->setupUi(this);

    ui->textBrowser->setStyleSheet("border-radius: 10px; border: 0px; padding: 5px; background-color: #232229;");

    // Отладка: выводим словарь в консоль
    qDebug() << "Частотный словарь:" << wordFreq;

    // Создаем список для вывода
    QStringList sortedWords;

    // Преобразуем QMap в список пар "слово - частота"
    QList<QPair<QString, int>> wordList;
    for (auto it = wordFreq.begin(); it != wordFreq.end(); ++it) {
        wordList.append(qMakePair(it.key(), it.value()));
    }

    // Сортируем список по убыванию частоты
    std::sort(wordList.begin(), wordList.end(), [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    });

    // Берем топ-10 слов
    int count = 0;
    for (const auto& pair : wordList) {
        if (count >= 10) break;
        sortedWords.append(QString("%1 - %2 раз").arg(pair.first).arg(pair.second));
        count++;
    }

    // Выводим в текстовое поле
    ui->textBrowser->setText(sortedWords.join("\n"));
}

wordfrequencydialog::~wordfrequencydialog() {
    delete ui;
}
