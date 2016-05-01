#ifndef OFFICE_HPP
#define OFFICE_HPP

#include <QObject>
#include <QString>

#include "city.hpp"

class Office : public QObject
{
    Q_OBJECT

private:
    int m_id;
    QString m_name;
    City *m_city;
    QString m_address;

public:
    explicit Office(QObject *parent = 0);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(City* city READ getCity WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged)

    int getId() const;
    QString getName() const;
    City *getCity() const;
    QString getAddress() const;

signals:
    void idChanged(int newId);
    void nameChanged(QString newName);
    void cityChanged(City* newCity);
    void addressChanged(QString newAddress);

public slots:
    void setName(const QString &name);
    void setId(int id);
    void setCity(City *city);
    void setAddress(const QString &address);
};

#endif // OFFICE_HPP
