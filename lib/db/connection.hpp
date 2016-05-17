#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QList>

#include "../models/city.hpp"
#include "../models/customer.hpp"
#include "../models/distance.hpp"
#include "../models/office.hpp"
#include "../models/shipment.hpp"

typedef QList<City*> CityList;
typedef QList<Customer*> CustomerList;
typedef QList<Distance*> DistanceList;
typedef QList<Office*> OfficeList;
typedef QList<Shipment*> ShipmentList;

class Connection : public QObject
{
    Q_OBJECT

private:
    explicit Connection(QObject *parent = 0);
    static Connection *m_connection;
    QSqlDatabase m_db;
    void seed();

public:
    static Connection *getConnection();
signals:

public slots:
};

#endif // CONNECTION_HPP
