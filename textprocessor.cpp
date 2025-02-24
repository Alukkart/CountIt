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
    return text.count(QRegularExpression("[^a-zA-Z0-9\\s]")); // Считает все не-буквенно-цифровые символы
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
