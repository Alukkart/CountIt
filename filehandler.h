#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>

class FileHandler {
public:
    static QString readFile(const QString& filePath);
    static bool writeFile(const QString& filePath, const QString& content);
};

#endif // FILEHANDLER_H
