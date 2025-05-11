#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textprocessor.h"
#include "filehandler.h"
#include "wordfrequencydialog.h"
#include <QFileDialog>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveFile);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::updateStatistics);
    connect(ui->copyButton, &QPushButton::clicked, this, &MainWindow::copyResults);
    connect(ui->frequencyButton, &QPushButton::clicked, this, &MainWindow::showWordFrequency);

    ui->textEdit->setStyleSheet("border-radius: 10px; border: 0px; padding: 5px; background-color: #232229;");
    ui->openButton->setStyleSheet("border-radius: 6px; background-color: #232229;");
    ui->saveButton->setStyleSheet("border-radius: 6px; background-color: #232229;");
    ui->copyButton->setStyleSheet("border-radius: 6px; background-color: #232229;");
    ui->frequencyButton->setStyleSheet("border-radius: 6px; background-color: #232229;");

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Текстовые файлы (*.txt)");
    if (!filePath.isEmpty()) {
        ui->textEdit->setText(FileHandler::readFile(filePath));
    }
}

void MainWindow::saveFile() {
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовые файлы (*.txt)");
    if (!filePath.isEmpty()) {
        FileHandler::writeFile(filePath, ui->textEdit->toPlainText());
    }
}

void MainWindow::updateStatistics() {
    QString text = ui->textEdit->toPlainText();

    ui->wordCountLabel->setText("Слов: " + QString::number(TextProcessor::countWords(text)));
    ui->charCountLabel->setText("Символов: " + QString::number(TextProcessor::countCharacters(text)));
    ui->spaceCountLabel->setText("Пробелов: " + QString::number(TextProcessor::countSpaces(text)));
    ui->specialCharCountLabel->setText("Спецсимволов: " + QString::number(TextProcessor::countSpecialCharacters(text)));
    ui->lineCountLabel->setText("Строк: " + QString::number(TextProcessor::countLines(text)));
}


void MainWindow::copyResults() {
    QString results;
    results += "Слов: " + QString::number(TextProcessor::countWords(ui->textEdit->toPlainText())) + "\n";
    results += "Символов: " + QString::number(TextProcessor::countCharacters(ui->textEdit->toPlainText())) + "\n";
    results += "Строк: " + QString::number(TextProcessor::countLines(ui->textEdit->toPlainText())) + "\n";
    results += "Пробелов: " + QString::number(TextProcessor::countSpaces(ui->textEdit->toPlainText())) + "\n";
    results += "Спецсимволов: " + QString::number(TextProcessor::countSpecialCharacters(ui->textEdit->toPlainText())) + "\n";

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(results);
}

void MainWindow::showWordFrequency() {
    QString text = ui->textEdit->toPlainText();  // Получаем текст из редактора

    QMap<QString, int> wordFreq = TextProcessor::wordFrequency(text);

    // Проверяем, есть ли слова
    if (wordFreq.isEmpty()) {
        qDebug() << "В тексте нет слов для анализа!";
        return;
    }

    wordfrequencydialog dialog(wordFreq, this);
    dialog.exec();
}
