#ifndef CITY_HPP
#define CITY_HPP

#include <QObject>
#include <QString>

class City : public QObject
{
    Q_OBJECT

private:
    int m_id;
    QString m_name;

public:
    explicit City(QObject *parent = 0);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    int getId() const;
    QString getName() const;

signals:
    void idChanged(int newId);
    void nameChanged(QString newName);

public slots:
    void setName(const QString &value);
    void setId(int value);
};

#endif // CITY_HPP
