#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QString>

class TextProcessor {
public:
    static int countWords(const QString& text);
    static int countCharacters(const QString& text);
    static int countSpaces(const QString& text);          // Новый метод
    static int countSpecialCharacters(const QString& text); // Новый метод
    static int countLines(const QString& text);
    static QString applyFilters(const QString& text, bool removePunctuation);
};

#endif // TEXTPROCESSOR_H
