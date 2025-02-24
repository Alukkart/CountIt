#include <QMap>
#include <QStringList>
#include "textprocessor.h"
#include <QRegularExpression>

int TextProcessor::countWords(const QString& text) {
    return text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts).size();
}

int TextProcessor::countCharacters(const QString& text) {
    return text.length();
}

int TextProcessor::countSpaces(const QString& text) {
    return text.count(' ');  // Считает пробелы
}

int TextProcessor::countSpecialCharacters(const QString& text) {
    return text.count(QRegularExpression("[^a-zA-Z0-9а-яА-Я\\s\\n\\r]")); // Считает все не-буквенно-цифровые символы
}

int TextProcessor::countLines(const QString& text) {
    if(text.length() == 0){
        return 0;
    };
    return text.count('\n') + 1;
}

QString TextProcessor::applyFilters(const QString& text, bool removePunctuation) {
    if (removePunctuation) {
        QString filteredText = text;
        filteredText.replace(QRegularExpression(R"([.,!?;:\"'()\[\]{}<>])"), "");
        return filteredText;
    }
    return text;
}

QMap<QString, int> TextProcessor::wordFrequency(const QString& text) {
    QMap<QString, int> frequencyMap;

    // Разбиваем текст на слова с учётом букв и цифр
    QRegularExpression regex("[а-яА-Яa-zA-Z0-9]+");  // Берём только буквы и цифры
    QRegularExpressionMatchIterator it = regex.globalMatch(text.toLower());


    // Подсчитываем частоту слов
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        QString word = match.captured(0);
        frequencyMap[word]++;
    }

    return frequencyMap;
}


