#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QString>

class TextProcessor {
public:
    static int countWords(const QString& text);
    static int countCharacters(const QString& text);
    static int countSpaces(const QString& text);
    static int countSpecialCharacters(const QString& text);
    static int countLines(const QString& text);
    static QMap<QString, int> wordFrequency(const QString& text);
    static QString applyFilters(const QString& text, bool removePunctuation);
};

#endif // TEXTPROCESSOR_H
