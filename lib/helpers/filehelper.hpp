#ifndef FILEHELPER_HPP
#define FILEHELPER_HPP

#include <QObject>

class FileHelper : public QObject
{
    Q_OBJECT
public:
    explicit FileHelper(QObject *parent = 0);
    static QString fileToString(QString path);
    static bool fileExists(QString path);

signals:

public slots:
};

#endif // FILEHELPER_HPP
